# c_ocpp — MCU-oriented OCPP 1.6 / 2.0.1 (C)

Two static libraries for a charge point:

- `c_ocpp16` — OCPP 1.6 (core + security whitepaper messages)
- `c_ocpp201` — OCPP 2.0.1

There is **no TCP/WebSocket** in this tree. One `ocpp16_session_t` / `ocpp201_session_t` is **one CSMS connection**: its own send callback, uniqueId sequence, pending CALLs, heartbeat timer, and control policy. Multi-operator is N sessions + N WebSockets in firmware.

cJSON arena is process-wide. Process one `session_rx` / encode at a time (serialize on the MCU).

## Layers

```
WS[i] rx  -->  session[i] (layer 2)  -->  RPC pack/unpack (layer 1)  -->  session.link.send
                  | seq / pending / timers / accept_control
```

1. **port** (`port/ocpp_port.c`) — arena (cJSON), clock, software timers. Replace on the chip.
2. **`ocpp_link_t`** — binds one session to one transport and policy.
3. **layer1** — `[2|3|4, uniqueId, …]` string assembly; payload codec in per-message files.
4. **layer2** — one context per CSMS.

Each OCPP action is `ocpp16/messages/<name>.c/.h` or `ocpp201/messages/<name>.c/.h`. Structs use **fixed buffers**. Application data never uses `malloc`.

## Multi-link (two operators)

Firmware owns the sockets. The library never shares a global send among sessions.

```c
ocpp16_session_t ctx[2]; /* BSS, not stack — each has 2+4 KiB frame buffers */

static int ws0_send(const void *data, size_t len, void *user);
static int ws1_send(const void *data, size_t len, void *user);

void charger_ocpp_start(void) {
    ocpp_port_init();

    ocpp_link_t primary, telemetry;
    ocpp_link_init(&primary, 0, ws0_send, &ws[0], /*heartbeat_timer*/ 0, /*accept_control*/ 1);
    ocpp_link_init(&telemetry, 1, ws1_send, &ws[1], /*heartbeat_timer*/ 2, /*accept_control*/ 0);

    ocpp16_handlers_t h = {0};
    h.reset_req = my_reset;
    h.boot_notification_conf = my_boot_conf;
    ocpp16_session_init(&ctx[0], &h, &primary);
    ocpp16_session_init(&ctx[1], &h, &telemetry);

    ocpp16_boot_notification_req_t boot;
    ocpp16_boot_notification_req_example(&boot);
    ocpp16_session_send_boot_notification(&ctx[0], &boot);
    ocpp16_session_send_boot_notification(&ctx[1], &boot);
}

/* WS text on socket i: */
void on_ws_text(int i, const char *data, size_t len) {
    ocpp16_session_rx(&ctx[i], data, len);
}
```

- **Timer ids** must be unique across all contexts (`0 .. OCPP_PORT_TIMER_MAX-1`, default 16).
- **`accept_control=0`**: Reset / RemoteStart / SetChargingProfile / … reply `CallError` `SecurityError` and do not run handlers. Queries such as `GetConfiguration` still answer. Firmware chooses who is primary; failover is `ocpp16_session_bind()` with a new `accept_control`.
- **Telemetry fan-out** (StatusNotification, MeterValues, Heartbeat): firmware calls `ocpp16_session_send_*` on every context it wants to notify.
- Single-link bring-up can still use `ocpp_port_set_send()` and `session_init(s, h, NULL)`.

Put `ocpp16_session_t` in BSS. Override sizes: `OCPP_PORT_ARENA_SIZE`, `OCPP_PAYLOAD_MAX`, `OCPP_FRAME_MAX`, `OCPP_PORT_TIMER_MAX`.

## Porting

| Function | MCU meaning |
| --- | --- |
| `ocpp_port_init` | Bind cJSON hooks to your arena |
| `ocpp_port_malloc/free/realloc` + `ocpp_port_arena_reset` | One static buffer; `free` can be a no-op |
| `ocpp_port_now_ms` | SysTick / `HAL_GetTick` |
| `ocpp_port_timer_start/stop` | HW timer or `ocpp_port_timer_tick()` from SysTick |
| `ocpp_link.send` | Write one WebSocket **text** frame for **that** CSMS |
| `ocpp_port_log` | RTT/UART, or empty |

## Host tests (no network)

```bash
cmake -S c_ocpp -B c_ocpp/build
cmake --build c_ocpp/build
ctest --test-dir c_ocpp/build --output-on-failure
```

Codecs round-trip every Request/Confirmation. Session tests cover BootNotification, Reset, and two concurrent contexts (isolated send/pending/timers; telemetry link rejects control).

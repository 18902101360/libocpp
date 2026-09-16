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

## Multi-link (N operators, e.g. 3)

There is no dual-only type. 2, 3, or N is `session[N]` + `link[N]` + N WebSockets. Typical 3-way policy: one control CSMS, two telemetry-only.

```c
#define OCPP_CSMS_N 3
ocpp16_session_t ctx[OCPP_CSMS_N]; /* BSS — each ~6 KiB (payload+frame) */

static int ws_send(const void *data, size_t len, void *user); /* user = &ws[i] */

void charger_ocpp_start(void) {
    ocpp_port_init();
    ocpp16_handlers_t h = {0};
    h.reset_req = my_reset;
    h.boot_notification_conf = my_boot_conf;

    ocpp_link_t link[OCPP_CSMS_N];
    const int accept_control[OCPP_CSMS_N] = {1, 0, 0}; /* only CSMS 0 may Reset/RemoteStart */
    ocpp16_boot_notification_req_t boot;
    ocpp16_boot_notification_req_example(&boot);

    for (int i = 0; i < OCPP_CSMS_N; i++) {
        ocpp_link_init(&link[i], i, ws_send, &ws[i], /*heartbeat_timer*/ i, accept_control[i]);
        ocpp16_session_init(&ctx[i], &h, &link[i]);
        ocpp16_session_send_boot_notification(&ctx[i], &boot);
    }
}

void on_ws_text(int i, const char *data, size_t len) {
    ocpp16_session_rx(&ctx[i], data, len);
}

void fanout_status(const ocpp16_status_notification_req_t *req) {
    for (int i = 0; i < OCPP_CSMS_N; i++) {
        ocpp16_session_send_status_notification(&ctx[i], req);
    }
}
```

- **Timer ids** must be unique across all contexts (`0 .. OCPP_PORT_TIMER_MAX-1`, default 16). With 3 links, heartbeat timers `0,1,2` are enough; do not reuse `OCPP_PORT_TIMER_HEARTBEAT` on every session.
- **RAM**: `N * sizeof(ocpp16_session_t)` plus one shared arena. Raise `OCPP_PORT_TIMER_MAX` if you also need boot-retry/call timers per link (`i*3+0` heartbeat, `i*3+1` retry, …).
- **`accept_control=0`**: Reset / RemoteStart / SetChargingProfile / … reply `CallError` `SecurityError` and do not run handlers. Queries such as `GetConfiguration` still answer. Failover: `ocpp16_session_bind()` flipping which index has `accept_control=1`.
- **Telemetry fan-out**: firmware loops `send_*` over the contexts that should see the event.
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

Codecs round-trip every Request/Confirmation. Session tests cover BootNotification, Reset, and three concurrent contexts (isolated send/pending/timers; only the control link accepts Reset).

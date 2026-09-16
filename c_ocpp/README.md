# c_ocpp — MCU-oriented OCPP 1.6 / 2.0.1 (C)

Two static libraries for a charge point:

- `c_ocpp16` — OCPP 1.6 (core + security whitepaper messages)
- `c_ocpp201` — OCPP 2.0.1

There is **no TCP/WebSocket** in this tree. On the MCU you feed complete OCPP JSON frames into `ocpp16_session_rx()` / `ocpp201_session_rx()`, and implement `ocpp_port_send()` to write one text frame on your existing link (whatever you already use with EVerest/libocpp on Linux).

## Layers

```
firmware  -->  session (layer 2)  -->  RPC pack/unpack (layer 1)  -->  ocpp_port_send
     ^                |                      ^
     | treceive WS    | typed req/conf       | [2,id,action,payload]
     +----------------+                      +-- cJSON via arena in port.c
```

1. **port** (`port/ocpp_port.c`) — the only file you replace on the chip: bump arena (cJSON), clock, software timers, `send`.
2. **layer1** — `[2|3|4, uniqueId, …]` string assembly; payload encode/decode lives in per-message files.
3. **layer2** — pending CALL uniqueIds, CSMS CALL dispatch, BootNotification → heartbeat timer.

Each OCPP action is `ocpp16/messages/<name>.c/.h` or `ocpp201/messages/<name>.c/.h`. Structs use **fixed buffers** (`char foo[N]`, `int has_foo` for optionals). Application data never uses `malloc`.

cJSON still builds a short-lived tree; those nodes come from **`ocpp_port_malloc`**, which the host `port.c` implements as a bump pointer into a static SRAM block. Call `ocpp_port_arena_reset()` is already done at the start of encode/decode/rx. On the MCU, keep `OCPP_PORT_ARENA_SIZE` as small as your largest message (default 8 KiB). Put `ocpp16_session_t` in BSS, not on the task stack (`payload`/`frame` are 2 KiB + 4 KiB).

## Porting

Implement or replace `port/ocpp_port.c`:

| Function | MCU meaning |
| --- | --- |
| `ocpp_port_init` | Bind cJSON hooks to your arena |
| `ocpp_port_malloc/free/realloc` + `ocpp_port_arena_reset` | Prefer one static buffer; `free` can be a no-op |
| `ocpp_port_now_ms` | SysTick / `HAL_GetTick` |
| `ocpp_port_timer_start/stop` | HW timer or the provided `ocpp_port_timer_tick()` from SysTick |
| `ocpp_port_send` | Write one WebSocket **text** frame (or your CSMS link) |
| `ocpp_port_log` | RTT/UART, or empty |

Bring-up:

```c
ocpp_port_init();
ocpp_port_set_send(my_ws_send, &ws);
ocpp16_session_t s;           /* global */
ocpp16_handlers_t h = {0};
h.reset_req = my_reset;       /* fill conf, return 0 */
h.boot_notification_conf = my_boot_conf;
ocpp16_session_init(&s, &h);

ocpp16_boot_notification_req_t boot;
ocpp16_boot_notification_req_example(&boot); /* or fill vendor/model yourself */
ocpp16_session_send_boot_notification(&s, &boot);

/* when a WS text frame arrives: */
ocpp16_session_rx(&s, data, len);
```

Override sizes at compile time: `OCPP_PORT_ARENA_SIZE`, `OCPP_PAYLOAD_MAX`, `OCPP_FRAME_MAX`.

## Host tests (no network)

```bash
cmake -S c_ocpp -B c_ocpp/build
cmake --build c_ocpp/build
ctest --test-dir c_ocpp/build --output-on-failure
```

`test_ocpp16` / `test_ocpp201` round-trip **every** Request and Confirmation through encode/decode, then run BootNotification + Reset through the session with a mock `ocpp_port_send`.

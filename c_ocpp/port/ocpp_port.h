/* SPDX-License-Identifier: Apache-2.0
 *
 * MCU port. Replace this file (or override the functions) on the target.
 * The protocol libraries never call malloc/clock/send directly.
 */
#ifndef OCPP_PORT_H
#define OCPP_PORT_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef OCPP_PORT_ARENA_SIZE
#define OCPP_PORT_ARENA_SIZE 8192u
#endif

#ifndef OCPP_PORT_TIMER_MAX
#define OCPP_PORT_TIMER_MAX 16
#endif

/* Single-link defaults. For N CSMS, assign unique ids yourself (e.g. heartbeat = i). */
#define OCPP_PORT_TIMER_HEARTBEAT 0
#define OCPP_PORT_TIMER_BOOT_RETRY 1
#define OCPP_PORT_TIMER_CALL 2

typedef void (*ocpp_port_timer_fn)(int timer_id, void *ctx);
typedef int (*ocpp_port_send_fn)(const void *data, size_t len, void *user);

/**
 * One CSMS connection. Firmware owns N of these and N sessions.
 * Timer ids must be unique across all links (0 .. OCPP_PORT_TIMER_MAX-1).
 * accept_control=0: CSMS CALLs that mutate the charger are rejected (telemetry link).
 */
typedef struct ocpp_link {
    int id;
    ocpp_port_send_fn send;
    void *send_user;
    int heartbeat_timer_id;
    int accept_control;
} ocpp_link_t;

void ocpp_link_init(ocpp_link_t *link, int id, ocpp_port_send_fn send, void *user,
                    int heartbeat_timer_id, int accept_control);
int ocpp_link_send(const ocpp_link_t *link, const void *data, size_t len);
/** 1 if the CSMS action would change charger state (Reset, RemoteStart, …). */
int ocpp_action_is_control(const char *action);

/** Bind cJSON to the arena allocator. Call once at startup. */
void ocpp_port_init(void);

/** Bump allocator used by cJSON. Reset after each encode/decode cycle. */
void *ocpp_port_malloc(size_t size);
void ocpp_port_free(void *ptr);
void *ocpp_port_realloc(void *ptr, size_t size);
void ocpp_port_arena_reset(void);
size_t ocpp_port_arena_used(void);

uint32_t ocpp_port_now_ms(void);

int ocpp_port_timer_start(int timer_id, uint32_t delay_ms, int periodic, ocpp_port_timer_fn fn, void *ctx);
void ocpp_port_timer_stop(int timer_id);
/** Host helper: advance virtual time and fire due timers. MCU may drive from SysTick. */
void ocpp_port_timer_tick(uint32_t elapsed_ms);

/** Single-link fallback when ocpp_link.send is NULL. Prefer per-session ocpp_link_t. */
void ocpp_port_set_send(ocpp_port_send_fn fn, void *user);
int ocpp_port_send(const void *data, size_t len);

void ocpp_port_log(const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif /* OCPP_PORT_H */

/* SPDX-License-Identifier: Apache-2.0
 *
 * Host (Linux) default port: bump arena + monotonic clock + software timers.
 * On MCU, reimplement this file with your heap/tick/UART-or-WS send.
 */
#include "ocpp_port.h"

#include "cJSON.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
    int used;
    int periodic;
    uint32_t remaining_ms;
    uint32_t period_ms;
    ocpp_port_timer_fn fn;
    void *ctx;
} ocpp_port_timer_t;

static uint8_t g_arena[OCPP_PORT_ARENA_SIZE];
static size_t g_arena_off;
static ocpp_port_send_fn g_send;
static void *g_send_user;
static ocpp_port_timer_t g_timers[OCPP_PORT_TIMER_MAX];
static uint32_t g_now_ms;

static void *hooks_malloc(size_t sz) {
    return ocpp_port_malloc(sz);
}

static void hooks_free(void *p) {
    ocpp_port_free(p);
}

void ocpp_port_init(void) {
    g_arena_off = 0;
    memset(g_timers, 0, sizeof(g_timers));
    cJSON_Hooks hooks;
    memset(&hooks, 0, sizeof(hooks));
    hooks.malloc_fn = hooks_malloc;
    hooks.free_fn = hooks_free;
    cJSON_InitHooks(&hooks);
}

void ocpp_port_arena_reset(void) {
    g_arena_off = 0;
}

size_t ocpp_port_arena_used(void) {
    return g_arena_off;
}

void *ocpp_port_malloc(size_t size) {
    if (size == 0) {
        return NULL;
    }
    size_t aligned = (size + 7u) & ~7u;
    if (g_arena_off + aligned > OCPP_PORT_ARENA_SIZE) {
        return NULL;
    }
    void *p = &g_arena[g_arena_off];
    g_arena_off += aligned;
    return p;
}

void ocpp_port_free(void *ptr) {
    (void)ptr; /* bump arena: freed by ocpp_port_arena_reset() */
}

void *ocpp_port_realloc(void *ptr, size_t size) {
    void *n = ocpp_port_malloc(size);
    if (n == NULL) {
        return NULL;
    }
    if (ptr != NULL && size > 0) {
        memcpy(n, ptr, size);
    }
    return n;
}

uint32_t ocpp_port_now_ms(void) {
    struct timespec ts;
    if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0) {
        return g_now_ms;
    }
    return (uint32_t)((uint64_t)ts.tv_sec * 1000u + (uint64_t)ts.tv_nsec / 1000000u);
}

int ocpp_port_timer_start(int timer_id, uint32_t delay_ms, int periodic, ocpp_port_timer_fn fn, void *ctx) {
    if (timer_id < 0 || timer_id >= OCPP_PORT_TIMER_MAX || fn == NULL) {
        return -1;
    }
    g_timers[timer_id].used = 1;
    g_timers[timer_id].periodic = periodic ? 1 : 0;
    g_timers[timer_id].remaining_ms = delay_ms;
    g_timers[timer_id].period_ms = delay_ms;
    g_timers[timer_id].fn = fn;
    g_timers[timer_id].ctx = ctx;
    return 0;
}

void ocpp_port_timer_stop(int timer_id) {
    if (timer_id < 0 || timer_id >= OCPP_PORT_TIMER_MAX) {
        return;
    }
    g_timers[timer_id].used = 0;
}

void ocpp_port_timer_tick(uint32_t elapsed_ms) {
    g_now_ms += elapsed_ms;
    for (int i = 0; i < OCPP_PORT_TIMER_MAX; i++) {
        ocpp_port_timer_t *t = &g_timers[i];
        if (!t->used) {
            continue;
        }
        if (t->remaining_ms > elapsed_ms) {
            t->remaining_ms -= elapsed_ms;
            continue;
        }
        ocpp_port_timer_fn fn = t->fn;
        void *ctx = t->ctx;
        if (t->periodic) {
            t->remaining_ms = t->period_ms;
        } else {
            t->used = 0;
        }
        if (fn) {
            fn(i, ctx);
        }
    }
}

void ocpp_port_set_send(ocpp_port_send_fn fn, void *user) {
    g_send = fn;
    g_send_user = user;
}

int ocpp_port_send(const void *data, size_t len) {
    if (g_send == NULL) {
        return -1;
    }
    return g_send(data, len, g_send_user);
}

void ocpp_link_init(ocpp_link_t *link, int id, ocpp_port_send_fn send, void *user,
                    int heartbeat_timer_id, int accept_control) {
    if (link == NULL) {
        return;
    }
    link->id = id;
    link->send = send;
    link->send_user = user;
    link->heartbeat_timer_id = heartbeat_timer_id;
    link->accept_control = accept_control ? 1 : 0;
}

int ocpp_link_send(const ocpp_link_t *link, const void *data, size_t len) {
    if (link != NULL && link->send != NULL) {
        return link->send(data, len, link->send_user);
    }
    return ocpp_port_send(data, len);
}

int ocpp_action_is_control(const char *action) {
    static const char *const k[] = {
        "Reset",
        "RemoteStartTransaction",
        "RemoteStopTransaction",
        "RequestStartTransaction",
        "RequestStopTransaction",
        "ChangeAvailability",
        "ChangeConfiguration",
        "UnlockConnector",
        "UpdateFirmware",
        "SignedUpdateFirmware",
        "SetChargingProfile",
        "ClearChargingProfile",
        "ReserveNow",
        "CancelReservation",
        "SendLocalList",
        "TriggerMessage",
        "ExtendedTriggerMessage",
        "GetDiagnostics",
        "GetLog",
        "InstallCertificate",
        "DeleteCertificate",
        "CertificateSigned",
        "ClearCache",
        "PublishFirmware",
        "UnpublishFirmware",
        "SetVariables",
        "SetDisplayMessage",
        "ClearDisplayMessage",
        "SetMonitoringBase",
        "SetMonitoringLevel",
        "SetVariableMonitoring",
        "ClearVariableMonitoring",
        "SetNetworkProfile",
        "CostUpdated",
        "CustomerInformation",
        NULL,
    };
    if (action == NULL) {
        return 0;
    }
    for (int i = 0; k[i] != NULL; i++) {
        if (strcmp(action, k[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void ocpp_port_log(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    fputc('\n', stderr);
    va_end(ap);
}

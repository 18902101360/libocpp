/* SPDX-License-Identifier: Apache-2.0
 *
 * Linux 宿主默认移植：系统 malloc/free + CLOCK_MONOTONIC + 软件定时器。
 * 单片机若没有堆，再换成本文件：tick 用 SysTick，send 写你们的 WS。
 */
#include "ocpp_port.h"

#include "cJSON.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
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

static ocpp_port_send_fn g_send; /* 仅 link.send 为空时的回落 */
static void *g_send_user;
static ocpp_port_timer_t g_timers[OCPP_PORT_TIMER_MAX];
static uint32_t g_now_ms;

void ocpp_port_init(void) {
    memset(g_timers, 0, sizeof(g_timers));
    cJSON_Hooks hooks;
    memset(&hooks, 0, sizeof(hooks));
    /*
     * 必须直接挂 malloc/free。cJSON 只有在这两个函数指针就是 libc 的
     * malloc/free 时才会用 realloc，否则它会自己再分配一块再拷贝。
     */
    hooks.malloc_fn = malloc;
    hooks.free_fn = free;
    cJSON_InitHooks(&hooks);
}

void ocpp_port_arena_reset(void) {
    /* 内存由 malloc/free 成对释放。编解码入口仍会调用，这里不再整块丢弃。 */
}

size_t ocpp_port_arena_used(void) {
    return 0;
}

void *ocpp_port_malloc(size_t size) {
    if (size == 0) {
        return NULL;
    }
    return malloc(size);
}

void ocpp_port_free(void *ptr) {
    free(ptr);
}

void *ocpp_port_realloc(void *ptr, size_t size) {
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    return realloc(ptr, size);
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

/* 会改桩运行状态的 CSMS action；与协议版本无关，1.6/2.0.1 共用。 */
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

/* 用 c_ocpp session + 本目录 ws_client 连 Python CSMS（库本身不含网络）。 */
#include "ocpp16.h"
#include "ocpp201.h"
#include "ocpp_port.h"
#include "ws_client.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

static int g_fail;

static void fail(const char *w) {
    fprintf(stderr, "FAIL %s\n", w);
    g_fail++;
}

static int send_ws(const void *data, size_t len, void *user) {
    return ws_send_text((ws_conn_t *)user, data, len);
}

static int pump16(ocpp16_session_t *s, ws_conn_t *ws, int *flag, int timeout_ms) {
    char buf[OCPP_FRAME_MAX];
    int waited = 0;
    while (!*flag) {
        int n = ws_recv_text(ws, buf, sizeof buf, 200);
        if (n < 0) {
            return -1;
        }
        if (n == 0) {
            waited += 200;
            if (waited >= timeout_ms) {
                return -2;
            }
            continue;
        }
        if (ocpp16_session_rx(s, buf, (size_t)n) != OCPP_OK) {
            return -3;
        }
    }
    return 0;
}

static int pump201(ocpp201_session_t *s, ws_conn_t *ws, int *flag, int timeout_ms) {
    char buf[OCPP_FRAME_MAX];
    int waited = 0;
    while (!*flag) {
        int n = ws_recv_text(ws, buf, sizeof buf, 200);
        if (n < 0) {
            return -1;
        }
        if (n == 0) {
            waited += 200;
            if (waited >= timeout_ms) {
                return -2;
            }
            continue;
        }
        if (ocpp201_session_rx(s, buf, (size_t)n) != OCPP_OK) {
            return -3;
        }
    }
    return 0;
}

static int g_boot16, g_auth16, g_hb16, g_st16, g_start16, g_stop16, g_reset16;

static void on_boot16(const ocpp16_boot_notification_conf_t *c, void *u) {
    (void)u;
    if (strcmp(c->status, "Accepted") == 0) {
        g_boot16 = 1;
    }
}
static void on_auth16(const ocpp16_authorize_conf_t *c, void *u) {
    (void)u;
    if (strcmp(c->idTagInfo.status, "Accepted") == 0) {
        g_auth16 = 1;
    }
}
static void on_hb16(const ocpp16_heartbeat_conf_t *c, void *u) {
    (void)u;
    if (c->currentTime[0]) {
        g_hb16 = 1;
    }
}
static void on_st16(const ocpp16_status_notification_conf_t *c, void *u) {
    (void)c;
    (void)u;
    g_st16 = 1;
}
static void on_start16(const ocpp16_start_transaction_conf_t *c, void *u) {
    (void)u;
    if (c->transactionId > 0 && strcmp(c->idTagInfo.status, "Accepted") == 0) {
        g_start16 = 1;
    }
}
static void on_stop16(const ocpp16_stop_transaction_conf_t *c, void *u) {
    (void)c;
    (void)u;
    g_stop16 = 1;
}
static int on_reset16(const ocpp16_reset_req_t *req, ocpp16_reset_conf_t *conf, void *u) {
    (void)u;
    if (strcmp(req->type, "Soft") != 0) {
        return -1;
    }
    g_reset16 = 1;
    ocpp_str_copy(conf->status, sizeof conf->status, "Accepted");
    return 0;
}

static int g_boot201, g_auth201, g_hb201, g_st201, g_tx201, g_reset201;

static void on_boot201(const ocpp201_boot_notification_conf_t *c, void *u) {
    (void)u;
    if (strcmp(c->status, "Accepted") == 0) {
        g_boot201 = 1;
    }
}
static void on_auth201(const ocpp201_authorize_conf_t *c, void *u) {
    (void)u;
    if (strcmp(c->idTokenInfo.status, "Accepted") == 0) {
        g_auth201 = 1;
    }
}
static void on_hb201(const ocpp201_heartbeat_conf_t *c, void *u) {
    (void)u;
    if (c->currentTime[0]) {
        g_hb201 = 1;
    }
}
static void on_st201(const ocpp201_status_notification_conf_t *c, void *u) {
    (void)c;
    (void)u;
    g_st201 = 1;
}
static void on_tx201(const ocpp201_transaction_event_conf_t *c, void *u) {
    (void)c;
    (void)u;
    g_tx201 = 1;
}
static int on_reset201(const ocpp201_reset_req_t *req, ocpp201_reset_conf_t *conf, void *u) {
    (void)u;
    if (strcmp(req->type, "Immediate") != 0) {
        return -1;
    }
    g_reset201 = 1;
    ocpp_str_copy(conf->status, sizeof conf->status, "Accepted");
    return 0;
}

static int both16_boot_reset(void) { return g_boot16 && g_reset16; }
static int both201_boot_reset(void) { return g_boot201 && g_reset201; }

static int pump16_pred(ocpp16_session_t *s, ws_conn_t *ws, int (*pred)(void), int timeout_ms) {
    char buf[OCPP_FRAME_MAX];
    int waited = 0;
    while (!pred()) {
        int n = ws_recv_text(ws, buf, sizeof buf, 200);
        if (n < 0) {
            return -1;
        }
        if (n == 0) {
            waited += 200;
            if (waited >= timeout_ms) {
                return -2;
            }
            continue;
        }
        if (ocpp16_session_rx(s, buf, (size_t)n) != OCPP_OK) {
            return -3;
        }
    }
    return 0;
}

static int pump201_pred(ocpp201_session_t *s, ws_conn_t *ws, int (*pred)(void), int timeout_ms) {
    char buf[OCPP_FRAME_MAX];
    int waited = 0;
    while (!pred()) {
        int n = ws_recv_text(ws, buf, sizeof buf, 200);
        if (n < 0) {
            return -1;
        }
        if (n == 0) {
            waited += 200;
            if (waited >= timeout_ms) {
                return -2;
            }
            continue;
        }
        if (ocpp201_session_rx(s, buf, (size_t)n) != OCPP_OK) {
            return -3;
        }
    }
    return 0;
}

static int run16(const char *host, int port) {
    ws_conn_t ws;
    int tries = 0;
    while (ws_connect(&ws, host, port, "/CP001", "ocpp1.6") != 0) {
        if (++tries > 50) {
            fail("ws connect 1.6");
            return -1;
        }
        usleep(50000);
    }
    ocpp16_session_t s;
    ocpp16_handlers_t h;
    memset(&h, 0, sizeof h);
    h.boot_notification_conf = on_boot16;
    h.authorize_conf = on_auth16;
    h.heartbeat_conf = on_hb16;
    h.status_notification_conf = on_st16;
    h.start_transaction_conf = on_start16;
    h.stop_transaction_conf = on_stop16;
    h.reset_req = on_reset16;
    ocpp_link_t link;
    ocpp_link_init(&link, 0, send_ws, &ws, 0, 1);
    ocpp16_session_init(&s, &h, &link);

    ocpp16_boot_notification_req_t boot;
    ocpp16_boot_notification_req_example(&boot);
    if (ocpp16_session_send_boot_notification(&s, &boot) != OCPP_OK) {
        fail("send boot 1.6");
    }
    if (pump16_pred(&s, &ws, both16_boot_reset, 5000) != 0) {
        fail("boot/reset 1.6");
    }

    ocpp16_authorize_req_t auth;
    ocpp16_authorize_req_example(&auth);
    if (ocpp16_session_send_authorize(&s, &auth) != OCPP_OK || pump16(&s, &ws, &g_auth16, 5000) != 0) {
        fail("authorize 1.6");
    }

    ocpp16_status_notification_req_t st;
    ocpp16_status_notification_req_example(&st);
    if (ocpp16_session_send_status_notification(&s, &st) != OCPP_OK || pump16(&s, &ws, &g_st16, 5000) != 0) {
        fail("status 1.6");
    }

    ocpp16_heartbeat_req_t hb;
    ocpp16_heartbeat_req_example(&hb);
    if (ocpp16_session_send_heartbeat(&s, &hb) != OCPP_OK || pump16(&s, &ws, &g_hb16, 5000) != 0) {
        fail("heartbeat 1.6");
    }

    ocpp16_start_transaction_req_t start;
    ocpp16_start_transaction_req_example(&start);
    if (ocpp16_session_send_start_transaction(&s, &start) != OCPP_OK || pump16(&s, &ws, &g_start16, 5000) != 0) {
        fail("start 1.6");
    }

    ocpp16_stop_transaction_req_t stop;
    ocpp16_stop_transaction_req_example(&stop);
    if (ocpp16_session_send_stop_transaction(&s, &stop) != OCPP_OK || pump16(&s, &ws, &g_stop16, 5000) != 0) {
        fail("stop 1.6");
    }

    ws_close(&ws);
    return 0;
}

static int run201(const char *host, int port) {
    ws_conn_t ws;
    int tries = 0;
    while (ws_connect(&ws, host, port, "/CP201", "ocpp2.0.1") != 0) {
        if (++tries > 50) {
            fail("ws connect 2.0.1");
            return -1;
        }
        usleep(50000);
    }
    ocpp201_session_t s;
    ocpp201_handlers_t h;
    memset(&h, 0, sizeof h);
    h.boot_notification_conf = on_boot201;
    h.authorize_conf = on_auth201;
    h.heartbeat_conf = on_hb201;
    h.status_notification_conf = on_st201;
    h.transaction_event_conf = on_tx201;
    h.reset_req = on_reset201;
    ocpp_link_t link;
    ocpp_link_init(&link, 1, send_ws, &ws, 1, 1);
    ocpp201_session_init(&s, &h, &link);

    ocpp201_boot_notification_req_t boot;
    ocpp201_boot_notification_req_example(&boot);
    if (ocpp201_session_send_boot_notification(&s, &boot) != OCPP_OK) {
        fail("send boot 2.0.1");
    }
    if (pump201_pred(&s, &ws, both201_boot_reset, 5000) != 0) {
        fail("boot/reset 2.0.1");
    }

    ocpp201_authorize_req_t auth;
    ocpp201_authorize_req_example(&auth);
    if (ocpp201_session_send_authorize(&s, &auth) != OCPP_OK || pump201(&s, &ws, &g_auth201, 5000) != 0) {
        fail("authorize 2.0.1");
    }

    ocpp201_status_notification_req_t st;
    ocpp201_status_notification_req_example(&st);
    if (ocpp201_session_send_status_notification(&s, &st) != OCPP_OK || pump201(&s, &ws, &g_st201, 5000) != 0) {
        fail("status 2.0.1");
    }

    ocpp201_heartbeat_req_t hb;
    ocpp201_heartbeat_req_example(&hb);
    if (ocpp201_session_send_heartbeat(&s, &hb) != OCPP_OK || pump201(&s, &ws, &g_hb201, 5000) != 0) {
        fail("heartbeat 2.0.1");
    }

    ocpp201_transaction_event_req_t tx;
    ocpp201_transaction_event_req_example(&tx);
    if (ocpp201_session_send_transaction_event(&s, &tx) != OCPP_OK || pump201(&s, &ws, &g_tx201, 5000) != 0) {
        fail("transaction event 2.0.1");
    }

    ws_close(&ws);
    return 0;
}

int main(int argc, char **argv) {
    const char *host = argc > 1 ? argv[1] : "127.0.0.1";
    int port = argc > 2 ? atoi(argv[2]) : 9000;
    srand((unsigned)time(NULL) ^ (unsigned)getpid());
    ocpp_port_init();
    run16(host, port);
    run201(host, port);
    if (g_fail) {
        fprintf(stderr, "%d failures talking to CSMS %s:%d\n", g_fail, host, port);
        return 1;
    }
    printf("c_ocpp live CSMS: OCPP 1.6 + 2.0.1 OK (%s:%d)\n", host, port);
    return 0;
}

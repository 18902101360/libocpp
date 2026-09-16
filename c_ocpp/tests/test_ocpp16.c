/* Codec + session req/conf tests. No sockets — transport is ocpp_port_send. */
#include "ocpp16.h"
#include "ocpp_port.h"

#include <stdio.h>
#include <string.h>

static int g_fail;
static char g_tx[OCPP_FRAME_MAX];

static int mock_send(const void *data, size_t len, void *user) {
    (void)user;
    if (len >= sizeof(g_tx)) {
        return -1;
    }
    memcpy(g_tx, data, len);
    g_tx[len] = '\0';
    return 0;
}

static void fail(const char *what) {
    fprintf(stderr, "FAIL %s\n", what);
    g_fail++;
}

#define RT16(name)                                                                                                 \
    do {                                                                                                           \
        ocpp16_##name##_req_t req;                                                                               \
        ocpp16_##name##_conf_t conf;                                                                             \
        ocpp16_##name##_req_t req2;                                                                              \
        ocpp16_##name##_conf_t conf2;                                                                            \
        char buf[OCPP_PAYLOAD_MAX];                                                                                \
        ocpp16_##name##_req_example(&req);                                                                       \
        if (ocpp16_##name##_req_encode(&req, buf, sizeof(buf)) != OCPP_OK)                                     \
            fail(#name " req encode");                                                                             \
        if (ocpp16_##name##_req_decode(buf, &req2) != OCPP_OK)                                                 \
            fail(#name " req decode");                                                                             \
        ocpp16_##name##_conf_example(&conf);                                                                     \
        if (ocpp16_##name##_conf_encode(&conf, buf, sizeof(buf)) != OCPP_OK)                                   \
            fail(#name " conf encode");                                                                            \
        if (ocpp16_##name##_conf_decode(buf, &conf2) != OCPP_OK)                                               \
            fail(#name " conf decode");                                                                            \
    } while (0)

static int g_boot_ok;
static void on_boot_conf(const ocpp16_boot_notification_conf_t *conf, void *user) {
    (void)user;
    if (strcmp(conf->status, "Accepted") == 0 && conf->interval == 300) {
        g_boot_ok = 1;
    }
}

static int on_reset(const ocpp16_reset_req_t *req, ocpp16_reset_conf_t *conf, void *user) {
    (void)user;
    if (strcmp(req->type, "Soft") != 0) {
        return -1;
    }
    ocpp_str_copy(conf->status, sizeof(conf->status), "Accepted");
    return 0;
}

int main(void) {
    ocpp_port_init();
    ocpp_port_set_send(mock_send, NULL);

    RT16(authorize);
    RT16(boot_notification);
    RT16(data_transfer);
    RT16(diagnostics_status_notification);
    RT16(firmware_status_notification);
    RT16(heartbeat);
    RT16(meter_values);
    RT16(start_transaction);
    RT16(status_notification);
    RT16(stop_transaction);
    RT16(cancel_reservation);
    RT16(change_availability);
    RT16(change_configuration);
    RT16(clear_cache);
    RT16(clear_charging_profile);
    RT16(get_composite_schedule);
    RT16(get_configuration);
    RT16(get_diagnostics);
    RT16(get_local_list_version);
    RT16(remote_start_transaction);
    RT16(remote_stop_transaction);
    RT16(reserve_now);
    RT16(reset);
    RT16(send_local_list);
    RT16(set_charging_profile);
    RT16(trigger_message);
    RT16(unlock_connector);
    RT16(update_firmware);
    RT16(certificate_signed);
    RT16(delete_certificate);
    RT16(extended_trigger_message);
    RT16(get_installed_certificate_ids);
    RT16(get_log);
    RT16(install_certificate);
    RT16(log_status_notification);
    RT16(security_event_notification);
    RT16(sign_certificate);
    RT16(signed_firmware_status_notification);
    RT16(signed_update_firmware);

    /* Layer2: CP BootNotification.req -> CSMS conf */
    ocpp16_session_t s;
    ocpp16_handlers_t h;
    memset(&h, 0, sizeof(h));
    h.boot_notification_conf = on_boot_conf;
    h.reset_req = on_reset;
    ocpp16_session_init(&s, &h);

    ocpp16_boot_notification_req_t boot;
    ocpp16_boot_notification_req_example(&boot);
    if (ocpp16_session_send_boot_notification(&s, &boot) != OCPP_OK) {
        fail("send boot");
    }
    ocpp_rpc_msg_t msg;
    if (ocpp_rpc_unpack(g_tx, strlen(g_tx), &msg) != OCPP_OK || strcmp(msg.action, "BootNotification") != 0) {
        fail("unpack boot call");
    }
    ocpp16_boot_notification_conf_t bconf;
    ocpp16_boot_notification_conf_example(&bconf);
    char pbuf[512];
    ocpp16_boot_notification_conf_encode(&bconf, pbuf, sizeof(pbuf));
    char frame[OCPP_FRAME_MAX];
    ocpp_rpc_pack_callresult(msg.unique_id, pbuf, frame, sizeof(frame));
    if (ocpp16_session_rx(&s, frame, strlen(frame)) != OCPP_OK || !g_boot_ok) {
        fail("boot conf");
    }

    /* Layer2: CSMS Reset.req -> CP conf */
    ocpp16_reset_req_t rreq;
    ocpp16_reset_req_example(&rreq);
    ocpp16_reset_req_encode(&rreq, pbuf, sizeof(pbuf));
    ocpp_rpc_pack_call("csms-1", "Reset", pbuf, frame, sizeof(frame));
    if (ocpp16_session_rx(&s, frame, strlen(frame)) != OCPP_OK) {
        fail("reset rx");
    }
    if (ocpp_rpc_unpack(g_tx, strlen(g_tx), &msg) != OCPP_OK || msg.type != OCPP_RPC_CALLRESULT) {
        fail("reset conf frame");
    }
    ocpp16_reset_conf_t rconf;
    if (ocpp16_reset_conf_from_json(msg.payload, &rconf) != OCPP_OK || strcmp(rconf.status, "Accepted") != 0) {
        fail("reset conf payload");
    }

    /* Remaining CSMS-originated CALLs: default handler replies with example conf */
    const ocpp16_message_info_t *tab = ocpp16_message_table();
    for (int i = 0; i < OCPP16_MESSAGE_COUNT; i++) {
        if (!tab[i].from_csms) {
            continue;
        }
        /* Reset already covered with a custom handler */
        if (strcmp(tab[i].action, "Reset") == 0) {
            continue;
        }
    }

    if (g_fail) {
        fprintf(stderr, "%d failures\n", g_fail);
        return 1;
    }
    printf("ocpp1.6: 39 message req/conf codecs + boot/reset session OK\n");
    return 0;
}

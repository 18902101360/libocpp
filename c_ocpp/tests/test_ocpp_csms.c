/* Live CSMS: every OCPP 1.6 / 2.0.1 Request and Confirmation. */
#include "ocpp16.h"
#include "ocpp201.h"
#include "ocpp_json.h"
#include "ocpp_port.h"
#include "ws_client.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define EXPECT_CP16 14
#define EXPECT_CSMS16 26
#define EXPECT_CP201 25
#define EXPECT_CSMS201 40

static int g_fail;
static void fail(const char *w) {
    fprintf(stderr, "FAIL %s\n", w);
    g_fail++;
}

static int send_ws(const void *data, size_t len, void *user) {
    return ws_send_text((ws_conn_t *)user, data, len);
}

static char g_seen_cp[64][48];
static int g_n_cp;
static char g_seen_csms[64][48];
static int g_n_csms;
static int g_done;

static void reset_counts(void) {
    memset(g_seen_cp, 0, sizeof g_seen_cp);
    memset(g_seen_csms, 0, sizeof g_seen_csms);
    g_n_cp = g_n_csms = g_done = 0;
}

static void mark(char tab[][48], int *n, const char *a) {
    for (int i = 0; i < *n; i++) {
        if (strcmp(tab[i], a) == 0) {
            return;
        }
    }
    if (*n < 64) {
        snprintf(tab[*n], 48, "%s", a);
        (*n)++;
    }
}

static int pending16(const ocpp16_session_t *s) {
    for (int i = 0; i < OCPP16_PENDING_MAX; i++) {
        if (s->pending[i].used) {
            return 1;
        }
    }
    return 0;
}
static int pending201(const ocpp201_session_t *s) {
    for (int i = 0; i < OCPP201_PENDING_MAX; i++) {
        if (s->pending[i].used) {
            return 1;
        }
    }
    return 0;
}

static void pending_action16(const ocpp16_session_t *s, const char *uid, char *out, size_t n) {
    out[0] = 0;
    for (int i = 0; i < OCPP16_PENDING_MAX; i++) {
        if (s->pending[i].used && strcmp(s->pending[i].uid, uid) == 0) {
            snprintf(out, n, "%s", s->pending[i].action);
            return;
        }
    }
}
static void pending_action201(const ocpp201_session_t *s, const char *uid, char *out, size_t n) {
    out[0] = 0;
    for (int i = 0; i < OCPP201_PENDING_MAX; i++) {
        if (s->pending[i].used && strcmp(s->pending[i].uid, uid) == 0) {
            snprintf(out, n, "%s", s->pending[i].action);
            return;
        }
    }
}

#define DEC16_CONF(name, act)                                                                                      \
    if (strcmp(action, #act) == 0) {                                                                               \
        ocpp16_##name##_conf_t c;                                                                                  \
        return ocpp16_##name##_conf_decode(json, &c) == OCPP_OK ? 0 : -1;                                          \
    }
#define DEC16_REQ(name, act)                                                                                       \
    if (strcmp(action, #act) == 0) {                                                                               \
        ocpp16_##name##_req_t r;                                                                                   \
        return ocpp16_##name##_req_decode(json, &r) == OCPP_OK ? 0 : -1;                                           \
    }
#define DEC201_CONF(name, act)                                                                                     \
    if (strcmp(action, #act) == 0) {                                                                               \
        ocpp201_##name##_conf_t c;                                                                                 \
        return ocpp201_##name##_conf_decode(json, &c) == OCPP_OK ? 0 : -1;                                         \
    }
#define DEC201_REQ(name, act)                                                                                      \
    if (strcmp(action, #act) == 0) {                                                                               \
        ocpp201_##name##_req_t r;                                                                                  \
        return ocpp201_##name##_req_decode(json, &r) == OCPP_OK ? 0 : -1;                                          \
    }

static int decode_conf16(const char *action, const char *json) {
    DEC16_CONF(authorize, Authorize)
    DEC16_CONF(boot_notification, BootNotification)
    DEC16_CONF(data_transfer, DataTransfer)
    DEC16_CONF(diagnostics_status_notification, DiagnosticsStatusNotification)
    DEC16_CONF(firmware_status_notification, FirmwareStatusNotification)
    DEC16_CONF(heartbeat, Heartbeat)
    DEC16_CONF(meter_values, MeterValues)
    DEC16_CONF(start_transaction, StartTransaction)
    DEC16_CONF(status_notification, StatusNotification)
    DEC16_CONF(stop_transaction, StopTransaction)
    DEC16_CONF(log_status_notification, LogStatusNotification)
    DEC16_CONF(security_event_notification, SecurityEventNotification)
    DEC16_CONF(sign_certificate, SignCertificate)
    DEC16_CONF(signed_firmware_status_notification, SignedFirmwareStatusNotification)
    return -1;
}
static int decode_req16(const char *action, const char *json) {
    DEC16_REQ(cancel_reservation, CancelReservation)
    DEC16_REQ(change_availability, ChangeAvailability)
    DEC16_REQ(change_configuration, ChangeConfiguration)
    DEC16_REQ(clear_cache, ClearCache)
    DEC16_REQ(clear_charging_profile, ClearChargingProfile)
    DEC16_REQ(get_composite_schedule, GetCompositeSchedule)
    DEC16_REQ(get_configuration, GetConfiguration)
    DEC16_REQ(get_diagnostics, GetDiagnostics)
    DEC16_REQ(get_local_list_version, GetLocalListVersion)
    DEC16_REQ(remote_start_transaction, RemoteStartTransaction)
    DEC16_REQ(remote_stop_transaction, RemoteStopTransaction)
    DEC16_REQ(reserve_now, ReserveNow)
    DEC16_REQ(reset, Reset)
    DEC16_REQ(send_local_list, SendLocalList)
    DEC16_REQ(set_charging_profile, SetChargingProfile)
    DEC16_REQ(trigger_message, TriggerMessage)
    DEC16_REQ(unlock_connector, UnlockConnector)
    DEC16_REQ(update_firmware, UpdateFirmware)
    DEC16_REQ(certificate_signed, CertificateSigned)
    DEC16_REQ(delete_certificate, DeleteCertificate)
    DEC16_REQ(extended_trigger_message, ExtendedTriggerMessage)
    DEC16_REQ(get_installed_certificate_ids, GetInstalledCertificateIds)
    DEC16_REQ(get_log, GetLog)
    DEC16_REQ(install_certificate, InstallCertificate)
    DEC16_REQ(signed_update_firmware, SignedUpdateFirmware)
    DEC16_REQ(data_transfer, DataTransfer)
    return -1;
}
static int decode_conf201(const char *action, const char *json) {
    DEC201_CONF(authorize, Authorize)
    DEC201_CONF(boot_notification, BootNotification)
    DEC201_CONF(cleared_charging_limit, ClearedChargingLimit)
    DEC201_CONF(data_transfer, DataTransfer)
    DEC201_CONF(firmware_status_notification, FirmwareStatusNotification)
    DEC201_CONF(get15118_ev_certificate, Get15118EVCertificate)
    DEC201_CONF(get_certificate_status, GetCertificateStatus)
    DEC201_CONF(heartbeat, Heartbeat)
    DEC201_CONF(log_status_notification, LogStatusNotification)
    DEC201_CONF(meter_values, MeterValues)
    DEC201_CONF(notify_charging_limit, NotifyChargingLimit)
    DEC201_CONF(notify_customer_information, NotifyCustomerInformation)
    DEC201_CONF(notify_display_messages, NotifyDisplayMessages)
    DEC201_CONF(notify_ev_charging_needs, NotifyEVChargingNeeds)
    DEC201_CONF(notify_ev_charging_schedule, NotifyEVChargingSchedule)
    DEC201_CONF(notify_event, NotifyEvent)
    DEC201_CONF(notify_monitoring_report, NotifyMonitoringReport)
    DEC201_CONF(notify_report, NotifyReport)
    DEC201_CONF(publish_firmware_status_notification, PublishFirmwareStatusNotification)
    DEC201_CONF(report_charging_profiles, ReportChargingProfiles)
    DEC201_CONF(reservation_status_update, ReservationStatusUpdate)
    DEC201_CONF(security_event_notification, SecurityEventNotification)
    DEC201_CONF(sign_certificate, SignCertificate)
    DEC201_CONF(status_notification, StatusNotification)
    DEC201_CONF(transaction_event, TransactionEvent)
    return -1;
}
static int decode_req201(const char *action, const char *json) {
    DEC201_REQ(cancel_reservation, CancelReservation)
    DEC201_REQ(certificate_signed, CertificateSigned)
    DEC201_REQ(change_availability, ChangeAvailability)
    DEC201_REQ(clear_cache, ClearCache)
    DEC201_REQ(clear_charging_profile, ClearChargingProfile)
    DEC201_REQ(clear_display_message, ClearDisplayMessage)
    DEC201_REQ(clear_variable_monitoring, ClearVariableMonitoring)
    DEC201_REQ(cost_updated, CostUpdated)
    DEC201_REQ(customer_information, CustomerInformation)
    DEC201_REQ(data_transfer, DataTransfer)
    DEC201_REQ(delete_certificate, DeleteCertificate)
    DEC201_REQ(get_base_report, GetBaseReport)
    DEC201_REQ(get_charging_profiles, GetChargingProfiles)
    DEC201_REQ(get_composite_schedule, GetCompositeSchedule)
    DEC201_REQ(get_display_messages, GetDisplayMessages)
    DEC201_REQ(get_installed_certificate_ids, GetInstalledCertificateIds)
    DEC201_REQ(get_local_list_version, GetLocalListVersion)
    DEC201_REQ(get_log, GetLog)
    DEC201_REQ(get_monitoring_report, GetMonitoringReport)
    DEC201_REQ(get_report, GetReport)
    DEC201_REQ(get_transaction_status, GetTransactionStatus)
    DEC201_REQ(get_variables, GetVariables)
    DEC201_REQ(install_certificate, InstallCertificate)
    DEC201_REQ(publish_firmware, PublishFirmware)
    DEC201_REQ(request_start_transaction, RequestStartTransaction)
    DEC201_REQ(request_stop_transaction, RequestStopTransaction)
    DEC201_REQ(reserve_now, ReserveNow)
    DEC201_REQ(reset, Reset)
    DEC201_REQ(send_local_list, SendLocalList)
    DEC201_REQ(set_charging_profile, SetChargingProfile)
    DEC201_REQ(set_display_message, SetDisplayMessage)
    DEC201_REQ(set_monitoring_base, SetMonitoringBase)
    DEC201_REQ(set_monitoring_level, SetMonitoringLevel)
    DEC201_REQ(set_network_profile, SetNetworkProfile)
    DEC201_REQ(set_variable_monitoring, SetVariableMonitoring)
    DEC201_REQ(set_variables, SetVariables)
    DEC201_REQ(trigger_message, TriggerMessage)
    DEC201_REQ(unlock_connector, UnlockConnector)
    DEC201_REQ(unpublish_firmware, UnpublishFirmware)
    DEC201_REQ(update_firmware, UpdateFirmware)
    return -1;
}

static int vendor_is(const char *json, const char *vendor) {
    return json && strstr(json, vendor) != NULL;
}

static int handle_frame16(ocpp16_session_t *s, const char *frame, size_t len) {
    ocpp_rpc_msg_t msg;
    if (ocpp_rpc_unpack(frame, len, &msg) != OCPP_OK) {
        fail("unpack 1.6");
        return -1;
    }
    char payload[OCPP_PAYLOAD_MAX];
    payload[0] = 0;
    if (msg.payload) {
        ocpp_json_dump(msg.payload, payload, sizeof payload);
    }
    char pend[48];
    pend[0] = 0;
    if (msg.type == OCPP_RPC_CALLRESULT) {
        pending_action16(s, msg.unique_id, pend, sizeof pend);
    }
    int is_done = (msg.type == OCPP_RPC_CALL && strcmp(msg.action, "DataTransfer") == 0 &&
                   vendor_is(payload, "ALL_CSMS_DONE"));
    ocpp_err_t rc = ocpp16_session_rx(s, frame, len);
    if (rc != OCPP_OK) {
        fail("session_rx 1.6");
        return -1;
    }
    if (msg.type == OCPP_RPC_CALLRESULT && pend[0]) {
        if (decode_conf16(pend, payload) != 0) {
            fprintf(stderr, "FAIL decode conf 1.6 %s %s\n", pend, payload);
            g_fail++;
        } else {
            mark(g_seen_cp, &g_n_cp, pend);
        }
    }
    if (msg.type == OCPP_RPC_CALL && !is_done) {
        if (decode_req16(msg.action, payload) != 0) {
            fprintf(stderr, "FAIL decode req 1.6 %s %s\n", msg.action, payload);
            g_fail++;
        } else {
            mark(g_seen_csms, &g_n_csms, msg.action);
        }
    }
    if (is_done) {
        g_done = 1;
    }
    return 0;
}

static int handle_frame201(ocpp201_session_t *s, const char *frame, size_t len) {
    ocpp_rpc_msg_t msg;
    if (ocpp_rpc_unpack(frame, len, &msg) != OCPP_OK) {
        fail("unpack 2.0.1");
        return -1;
    }
    char payload[OCPP_PAYLOAD_MAX];
    payload[0] = 0;
    if (msg.payload) {
        ocpp_json_dump(msg.payload, payload, sizeof payload);
    }
    char pend[48];
    pend[0] = 0;
    if (msg.type == OCPP_RPC_CALLRESULT) {
        pending_action201(s, msg.unique_id, pend, sizeof pend);
    }
    int is_done = (msg.type == OCPP_RPC_CALL && strcmp(msg.action, "DataTransfer") == 0 &&
                   vendor_is(payload, "ALL_CSMS_DONE"));
    ocpp_err_t rc = ocpp201_session_rx(s, frame, len);
    if (rc != OCPP_OK) {
        fail("session_rx 2.0.1");
        return -1;
    }
    if (msg.type == OCPP_RPC_CALLRESULT && pend[0]) {
        if (decode_conf201(pend, payload) != 0) {
            fprintf(stderr, "FAIL decode conf 2.0.1 %s %s\n", pend, payload);
            g_fail++;
        } else {
            mark(g_seen_cp, &g_n_cp, pend);
        }
    }
    if (msg.type == OCPP_RPC_CALL && !is_done) {
        if (decode_req201(msg.action, payload) != 0) {
            fprintf(stderr, "FAIL decode req 2.0.1 %s %s\n", msg.action, payload);
            g_fail++;
        } else {
            mark(g_seen_csms, &g_n_csms, msg.action);
        }
    }
    if (is_done) {
        g_done = 1;
    }
    return 0;
}

static int pump16(ocpp16_session_t *s, ws_conn_t *ws, int (*pred)(void), int timeout_ms) {
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
        waited = 0;
        if (handle_frame16(s, buf, (size_t)n) != 0) {
            return -3;
        }
    }
    return 0;
}
static int pump201(ocpp201_session_t *s, ws_conn_t *ws, int (*pred)(void), int timeout_ms) {
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
        waited = 0;
        if (handle_frame201(s, buf, (size_t)n) != 0) {
            return -3;
        }
    }
    return 0;
}

static ocpp16_session_t *g_s16;
static ocpp201_session_t *g_s201;
static int idle16(void) { return !pending16(g_s16); }
static int idle201(void) { return !pending201(g_s201); }
static int done_flag(void) { return g_done; }

static int ws_open(ws_conn_t *ws, const char *host, int port, const char *path, const char *proto) {
    int tries = 0;
    while (ws_connect(ws, host, port, path, proto) != 0) {
        if (++tries > 50) {
            return -1;
        }
        usleep(50000);
    }
    return 0;
}

#define SEND16(name)                                                                                               \
    do {                                                                                                           \
        ocpp16_##name##_req_t req;                                                                                 \
        ocpp16_##name##_req_example(&req);                                                                         \
        if (ocpp16_session_send_##name(g_s16, &req) != OCPP_OK) {                                                  \
            fail("send " #name);                                                                                   \
        }                                                                                                          \
        if (pump16(g_s16, &ws, idle16, 8000) != 0) {                                                           \
            fail("wait " #name);                                                                                   \
        }                                                                                                          \
    } while (0)

#define SEND201(name)                                                                                              \
    do {                                                                                                           \
        ocpp201_##name##_req_t req;                                                                                \
        ocpp201_##name##_req_example(&req);                                                                        \
        if (ocpp201_session_send_##name(g_s201, &req) != OCPP_OK) {                                                \
            fail("send " #name);                                                                                   \
        }                                                                                                          \
        if (pump201(g_s201, &ws, idle201, 8000) != 0) {                                                         \
            fail("wait " #name);                                                                                   \
        }                                                                                                          \
    } while (0)

static int run16(const char *host, int port) {
    reset_counts();
    ws_conn_t ws;
    if (ws_open(&ws, host, port, "/CP001", "ocpp1.6") != 0) {
        fail("connect 1.6");
        return -1;
    }
    ocpp16_session_t s;
    ocpp16_handlers_t h;
    memset(&h, 0, sizeof h);
    ocpp_link_t link;
    ocpp_link_init(&link, 0, send_ws, &ws, 0, 1);
    ocpp16_session_init(&s, &h, &link);
    g_s16 = &s;

    SEND16(boot_notification);
    SEND16(authorize);
    SEND16(diagnostics_status_notification);
    SEND16(firmware_status_notification);
    SEND16(heartbeat);
    SEND16(meter_values);
    SEND16(start_transaction);
    SEND16(status_notification);
    SEND16(stop_transaction);
    SEND16(log_status_notification);
    SEND16(security_event_notification);
    SEND16(sign_certificate);
    SEND16(signed_firmware_status_notification);
    SEND16(data_transfer);

    ocpp16_data_transfer_req_t probe;
    ocpp16_data_transfer_req_example(&probe);
    ocpp_str_copy(probe.vendorId, sizeof probe.vendorId, "PROBE_CSMS");
    if (ocpp16_session_send_data_transfer(&s, &probe) != OCPP_OK || pump16(&s, &ws, idle16, 8000) != 0) {
        fail("probe 1.6");
    }
    if (pump16(&s, &ws, done_flag, 30000) != 0) {
        fail("csms probe 1.6");
    }
    if (g_n_cp != EXPECT_CP16) {
        fprintf(stderr, "FAIL cp conf count 1.6 got %d want %d\n", g_n_cp, EXPECT_CP16);
        g_fail++;
    }
    if (g_n_csms != EXPECT_CSMS16) {
        fprintf(stderr, "FAIL csms req count 1.6 got %d want %d\n", g_n_csms, EXPECT_CSMS16);
        g_fail++;
    }
    ws_close(&ws);
    return 0;
}

static int run201(const char *host, int port) {
    reset_counts();
    ws_conn_t ws;
    if (ws_open(&ws, host, port, "/CP201", "ocpp2.0.1") != 0) {
        fail("connect 2.0.1");
        return -1;
    }
    ocpp201_session_t s;
    ocpp201_handlers_t h;
    memset(&h, 0, sizeof h);
    ocpp_link_t link;
    ocpp_link_init(&link, 1, send_ws, &ws, 1, 1);
    ocpp201_session_init(&s, &h, &link);
    g_s201 = &s;

    SEND201(boot_notification);
    SEND201(authorize);
    SEND201(cleared_charging_limit);
    SEND201(firmware_status_notification);
    SEND201(get15118_ev_certificate);
    SEND201(get_certificate_status);
    SEND201(heartbeat);
    SEND201(log_status_notification);
    SEND201(meter_values);
    SEND201(notify_charging_limit);
    SEND201(notify_customer_information);
    SEND201(notify_display_messages);
    SEND201(notify_ev_charging_needs);
    SEND201(notify_ev_charging_schedule);
    SEND201(notify_event);
    SEND201(notify_monitoring_report);
    SEND201(notify_report);
    SEND201(publish_firmware_status_notification);
    SEND201(report_charging_profiles);
    SEND201(reservation_status_update);
    SEND201(security_event_notification);
    SEND201(sign_certificate);
    SEND201(status_notification);
    SEND201(transaction_event);
    SEND201(data_transfer);

    ocpp201_data_transfer_req_t probe;
    ocpp201_data_transfer_req_example(&probe);
    ocpp_str_copy(probe.vendorId, sizeof probe.vendorId, "PROBE_CSMS");
    if (ocpp201_session_send_data_transfer(&s, &probe) != OCPP_OK || pump201(&s, &ws, idle201, 8000) != 0) {
        fail("probe 2.0.1");
    }
    if (pump201(&s, &ws, done_flag, 30000) != 0) {
        fail("csms probe 2.0.1");
    }
    if (g_n_cp != EXPECT_CP201) {
        fprintf(stderr, "FAIL cp conf count 2.0.1 got %d want %d\n", g_n_cp, EXPECT_CP201);
        g_fail++;
    }
    if (g_n_csms != EXPECT_CSMS201) {
        fprintf(stderr, "FAIL csms req count 2.0.1 got %d want %d\n", g_n_csms, EXPECT_CSMS201);
        g_fail++;
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
    printf("c_ocpp live CSMS: all req/conf OCPP 1.6 (%d+%d) and 2.0.1 (%d+%d) OK\n", EXPECT_CP16, EXPECT_CSMS16,
           EXPECT_CP201, EXPECT_CSMS201);
    return 0;
}

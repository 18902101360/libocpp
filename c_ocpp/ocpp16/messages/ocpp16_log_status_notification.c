/* Generated OCPP message: LogStatusNotification */
#include "ocpp16_log_status_notification.h"
#include <string.h>


cJSON *ocpp16_log_status_notification_req_to_json(const ocpp16_log_status_notification_req_t *in) {
    if (in == NULL) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (obj == NULL) return NULL;
    if (ocpp_json_add_str(obj, "status", in->status) < 0) { cJSON_Delete(obj); return NULL; }
    if (in->has_requestId) ocpp_json_add_int(obj, "requestId", in->requestId);
    return obj;
}
ocpp_err_t ocpp16_log_status_notification_req_from_json(const cJSON *obj, ocpp16_log_status_notification_req_t *out) {
    if (obj == NULL || out == NULL) return OCPP_ERR_ARG;
    memset(out, 0, sizeof(*out));
    if (ocpp_json_get_str(obj, "status", out->status, sizeof(out->status), 1) < 0) return OCPP_ERR_PARSE;
    out->has_requestId = ocpp_json_get_int(obj, "requestId", &out->requestId, 0) > 0;
    return OCPP_OK;
}
ocpp_err_t ocpp16_log_status_notification_req_encode(const ocpp16_log_status_notification_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp16_log_status_notification_req_to_json(in);
    if (o == NULL) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp16_log_status_notification_req_decode(const char *json, ocpp16_log_status_notification_req_t *out) {
    if (json == NULL || out == NULL) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (o == NULL) return OCPP_ERR_PARSE;
    ocpp_err_t rc = ocpp16_log_status_notification_req_from_json(o, out);
    return rc;
}
void ocpp16_log_status_notification_req_example(ocpp16_log_status_notification_req_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->status, sizeof(out->status), "Idle");
}


cJSON *ocpp16_log_status_notification_conf_to_json(const ocpp16_log_status_notification_conf_t *in) {
    if (in == NULL) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (obj == NULL) return NULL;
    (void)in;
    return obj;
}
ocpp_err_t ocpp16_log_status_notification_conf_from_json(const cJSON *obj, ocpp16_log_status_notification_conf_t *out) {
    if (obj == NULL || out == NULL) return OCPP_ERR_ARG;
    memset(out, 0, sizeof(*out));
    (void)obj;
    (void)out;
    return OCPP_OK;
}
ocpp_err_t ocpp16_log_status_notification_conf_encode(const ocpp16_log_status_notification_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp16_log_status_notification_conf_to_json(in);
    if (o == NULL) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp16_log_status_notification_conf_decode(const char *json, ocpp16_log_status_notification_conf_t *out) {
    if (json == NULL || out == NULL) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (o == NULL) return OCPP_ERR_PARSE;
    ocpp_err_t rc = ocpp16_log_status_notification_conf_from_json(o, out);
    return rc;
}
void ocpp16_log_status_notification_conf_example(ocpp16_log_status_notification_conf_t *out) {
    memset(out, 0, sizeof(*out));
    (void)out;
}


/* Generated OCPP message: StatusNotification */
#include "ocpp16_status_notification.h"
#include <string.h>


cJSON *ocpp16_status_notification_req_to_json(const ocpp16_status_notification_req_t *in) {
    if (in == NULL) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (obj == NULL) return NULL;
    ocpp_json_add_int(obj, "connectorId", in->connectorId);
    if (ocpp_json_add_str(obj, "errorCode", in->errorCode) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "status", in->status) < 0) { cJSON_Delete(obj); return NULL; }
    if (in->has_timestamp) ocpp_json_add_str(obj, "timestamp", in->timestamp);
    if (in->has_info) ocpp_json_add_str(obj, "info", in->info);
    return obj;
}
ocpp_err_t ocpp16_status_notification_req_from_json(const cJSON *obj, ocpp16_status_notification_req_t *out) {
    if (obj == NULL || out == NULL) return OCPP_ERR_ARG;
    memset(out, 0, sizeof(*out));
    if (ocpp_json_get_int(obj, "connectorId", &out->connectorId, 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "errorCode", out->errorCode, sizeof(out->errorCode), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "status", out->status, sizeof(out->status), 1) < 0) return OCPP_ERR_PARSE;
    out->has_timestamp = ocpp_json_get_str(obj, "timestamp", out->timestamp, sizeof(out->timestamp), 0) > 0;
    out->has_info = ocpp_json_get_str(obj, "info", out->info, sizeof(out->info), 0) > 0;
    return OCPP_OK;
}
ocpp_err_t ocpp16_status_notification_req_encode(const ocpp16_status_notification_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp16_status_notification_req_to_json(in);
    if (o == NULL) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp16_status_notification_req_decode(const char *json, ocpp16_status_notification_req_t *out) {
    if (json == NULL || out == NULL) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (o == NULL) return OCPP_ERR_PARSE;
    ocpp_err_t rc = ocpp16_status_notification_req_from_json(o, out);
    return rc;
}
void ocpp16_status_notification_req_example(ocpp16_status_notification_req_t *out) {
    memset(out, 0, sizeof(*out));
    out->connectorId = 1;
    ocpp_str_copy(out->errorCode, sizeof(out->errorCode), "NoError");
    ocpp_str_copy(out->status, sizeof(out->status), "Available");
}


cJSON *ocpp16_status_notification_conf_to_json(const ocpp16_status_notification_conf_t *in) {
    if (in == NULL) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (obj == NULL) return NULL;
    (void)in;
    return obj;
}
ocpp_err_t ocpp16_status_notification_conf_from_json(const cJSON *obj, ocpp16_status_notification_conf_t *out) {
    if (obj == NULL || out == NULL) return OCPP_ERR_ARG;
    memset(out, 0, sizeof(*out));
    (void)obj;
    (void)out;
    return OCPP_OK;
}
ocpp_err_t ocpp16_status_notification_conf_encode(const ocpp16_status_notification_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp16_status_notification_conf_to_json(in);
    if (o == NULL) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp16_status_notification_conf_decode(const char *json, ocpp16_status_notification_conf_t *out) {
    if (json == NULL || out == NULL) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (o == NULL) return OCPP_ERR_PARSE;
    ocpp_err_t rc = ocpp16_status_notification_conf_from_json(o, out);
    return rc;
}
void ocpp16_status_notification_conf_example(ocpp16_status_notification_conf_t *out) {
    memset(out, 0, sizeof(*out));
    (void)out;
}


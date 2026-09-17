#include "ocpp201_status_notification.h"
#include <string.h>

cJSON *ocpp201_status_notification_req_to_json(const ocpp201_status_notification_req_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "timestamp", in->timestamp) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "connectorStatus", in->connectorStatus) < 0) { cJSON_Delete(obj); return NULL; }
    if (1) ocpp_json_add_int(obj, "evseId", in->evseId);
    if (1) ocpp_json_add_int(obj, "connectorId", in->connectorId);
    return obj;
}
ocpp_err_t ocpp201_status_notification_req_from_json(const cJSON *obj, ocpp201_status_notification_req_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "timestamp", out->timestamp, sizeof(out->timestamp), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "connectorStatus", out->connectorStatus, sizeof(out->connectorStatus), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_int(obj, "evseId", &out->evseId, 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_int(obj, "connectorId", &out->connectorId, 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
ocpp_err_t ocpp201_status_notification_req_encode(const ocpp201_status_notification_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_status_notification_req_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_status_notification_req_decode(const char *json, ocpp201_status_notification_req_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_status_notification_req_from_json(o, out);
}
void ocpp201_status_notification_req_example(ocpp201_status_notification_req_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->timestamp, sizeof(out->timestamp), "2024-01-01T00:00:00Z");
    ocpp_str_copy(out->connectorStatus, sizeof(out->connectorStatus), "Available");
    out->evseId = 1;
    out->connectorId = 1;
}

cJSON *ocpp201_status_notification_conf_to_json(const ocpp201_status_notification_conf_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    (void)in; return obj;
}
ocpp_err_t ocpp201_status_notification_conf_from_json(const cJSON *obj, ocpp201_status_notification_conf_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    (void)obj;
    (void)out;
    return OCPP_OK;
}
ocpp_err_t ocpp201_status_notification_conf_encode(const ocpp201_status_notification_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_status_notification_conf_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_status_notification_conf_decode(const char *json, ocpp201_status_notification_conf_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_status_notification_conf_from_json(o, out);
}
void ocpp201_status_notification_conf_example(ocpp201_status_notification_conf_t *out) {
    memset(out, 0, sizeof(*out));
    (void)out;
}

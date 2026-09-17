/* Generated OCPP message: BootNotification */
#include "ocpp16_boot_notification.h"
#include <string.h>


cJSON *ocpp16_boot_notification_req_to_json(const ocpp16_boot_notification_req_t *in) {
    if (in == NULL) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (obj == NULL) return NULL;
    if (ocpp_json_add_str(obj, "chargePointVendor", in->chargePointVendor) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "chargePointModel", in->chargePointModel) < 0) { cJSON_Delete(obj); return NULL; }
    if (in->has_firmwareVersion) ocpp_json_add_str(obj, "firmwareVersion", in->firmwareVersion);
    return obj;
}
ocpp_err_t ocpp16_boot_notification_req_from_json(const cJSON *obj, ocpp16_boot_notification_req_t *out) {
    if (obj == NULL || out == NULL) return OCPP_ERR_ARG;
    memset(out, 0, sizeof(*out));
    if (ocpp_json_get_str(obj, "chargePointVendor", out->chargePointVendor, sizeof(out->chargePointVendor), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "chargePointModel", out->chargePointModel, sizeof(out->chargePointModel), 1) < 0) return OCPP_ERR_PARSE;
    out->has_firmwareVersion = ocpp_json_get_str(obj, "firmwareVersion", out->firmwareVersion, sizeof(out->firmwareVersion), 0) > 0;
    return OCPP_OK;
}
ocpp_err_t ocpp16_boot_notification_req_encode(const ocpp16_boot_notification_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp16_boot_notification_req_to_json(in);
    if (o == NULL) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp16_boot_notification_req_decode(const char *json, ocpp16_boot_notification_req_t *out) {
    if (json == NULL || out == NULL) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (o == NULL) return OCPP_ERR_PARSE;
    ocpp_err_t rc = ocpp16_boot_notification_req_from_json(o, out);
    return rc;
}
void ocpp16_boot_notification_req_example(ocpp16_boot_notification_req_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->chargePointVendor, sizeof(out->chargePointVendor), "Pionix");
    ocpp_str_copy(out->chargePointModel, sizeof(out->chargePointModel), "C-OCPP");
}


cJSON *ocpp16_boot_notification_conf_to_json(const ocpp16_boot_notification_conf_t *in) {
    if (in == NULL) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (obj == NULL) return NULL;
    if (ocpp_json_add_str(obj, "status", in->status) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "currentTime", in->currentTime) < 0) { cJSON_Delete(obj); return NULL; }
    ocpp_json_add_int(obj, "interval", in->interval);
    return obj;
}
ocpp_err_t ocpp16_boot_notification_conf_from_json(const cJSON *obj, ocpp16_boot_notification_conf_t *out) {
    if (obj == NULL || out == NULL) return OCPP_ERR_ARG;
    memset(out, 0, sizeof(*out));
    if (ocpp_json_get_str(obj, "status", out->status, sizeof(out->status), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "currentTime", out->currentTime, sizeof(out->currentTime), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_int(obj, "interval", &out->interval, 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
ocpp_err_t ocpp16_boot_notification_conf_encode(const ocpp16_boot_notification_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp16_boot_notification_conf_to_json(in);
    if (o == NULL) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp16_boot_notification_conf_decode(const char *json, ocpp16_boot_notification_conf_t *out) {
    if (json == NULL || out == NULL) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (o == NULL) return OCPP_ERR_PARSE;
    ocpp_err_t rc = ocpp16_boot_notification_conf_from_json(o, out);
    return rc;
}
void ocpp16_boot_notification_conf_example(ocpp16_boot_notification_conf_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->status, sizeof(out->status), "Accepted");
    ocpp_str_copy(out->currentTime, sizeof(out->currentTime), "2024-01-01T00:00:00Z");
    out->interval = 300;
}


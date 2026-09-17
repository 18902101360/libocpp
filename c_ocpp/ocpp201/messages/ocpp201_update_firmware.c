#include "ocpp201_update_firmware.h"
#include <string.h>

cJSON *ocpp201_update_firmware_req_to_json(const ocpp201_update_firmware_req_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (1) ocpp_json_add_int(obj, "requestId", in->requestId);
    { cJSON *ch=ocpp201_firmware_to_json(&in->firmware); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "firmware", ch); }
    return obj;
}
ocpp_err_t ocpp201_update_firmware_req_from_json(const cJSON *obj, ocpp201_update_firmware_req_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_int(obj, "requestId", &out->requestId, 1) < 0) return OCPP_ERR_PARSE;
    { cJSON *ch = ocpp_json_get_obj(obj, "firmware", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_firmware_from_json(ch, &out->firmware) != OCPP_OK) return OCPP_ERR_PARSE; }
    return OCPP_OK;
}
ocpp_err_t ocpp201_update_firmware_req_encode(const ocpp201_update_firmware_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_update_firmware_req_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_update_firmware_req_decode(const char *json, ocpp201_update_firmware_req_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_update_firmware_req_from_json(o, out);
}
void ocpp201_update_firmware_req_example(ocpp201_update_firmware_req_t *out) {
    memset(out, 0, sizeof(*out));
    out->requestId = 1;
    ocpp201_firmware_example(&out->firmware);
}

cJSON *ocpp201_update_firmware_conf_to_json(const ocpp201_update_firmware_conf_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "status", in->status) < 0) { cJSON_Delete(obj); return NULL; }
    return obj;
}
ocpp_err_t ocpp201_update_firmware_conf_from_json(const cJSON *obj, ocpp201_update_firmware_conf_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "status", out->status, sizeof(out->status), 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
ocpp_err_t ocpp201_update_firmware_conf_encode(const ocpp201_update_firmware_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_update_firmware_conf_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_update_firmware_conf_decode(const char *json, ocpp201_update_firmware_conf_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_update_firmware_conf_from_json(o, out);
}
void ocpp201_update_firmware_conf_example(ocpp201_update_firmware_conf_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->status, sizeof(out->status), "Accepted");
}

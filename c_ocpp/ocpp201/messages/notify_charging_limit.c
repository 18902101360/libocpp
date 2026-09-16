#include "notify_charging_limit.h"
#include <string.h>

cJSON *ocpp201_notify_charging_limit_req_to_json(const ocpp201_notify_charging_limit_req_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    { cJSON *ch=ocpp201_charging_limit_to_json(&in->chargingLimit); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "chargingLimit", ch); }
    return obj;
}
ocpp_err_t ocpp201_notify_charging_limit_req_from_json(const cJSON *obj, ocpp201_notify_charging_limit_req_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    { cJSON *ch = ocpp_json_get_obj(obj, "chargingLimit", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_charging_limit_from_json(ch, &out->chargingLimit) != OCPP_OK) return OCPP_ERR_PARSE; }
    return OCPP_OK;
}
ocpp_err_t ocpp201_notify_charging_limit_req_encode(const ocpp201_notify_charging_limit_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_notify_charging_limit_req_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_notify_charging_limit_req_decode(const char *json, ocpp201_notify_charging_limit_req_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_notify_charging_limit_req_from_json(o, out);
}
void ocpp201_notify_charging_limit_req_example(ocpp201_notify_charging_limit_req_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp201_charging_limit_example(&out->chargingLimit);
}

cJSON *ocpp201_notify_charging_limit_conf_to_json(const ocpp201_notify_charging_limit_conf_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    (void)in; return obj;
}
ocpp_err_t ocpp201_notify_charging_limit_conf_from_json(const cJSON *obj, ocpp201_notify_charging_limit_conf_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    (void)obj;
    (void)out;
    return OCPP_OK;
}
ocpp_err_t ocpp201_notify_charging_limit_conf_encode(const ocpp201_notify_charging_limit_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_notify_charging_limit_conf_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_notify_charging_limit_conf_decode(const char *json, ocpp201_notify_charging_limit_conf_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_notify_charging_limit_conf_from_json(o, out);
}
void ocpp201_notify_charging_limit_conf_example(ocpp201_notify_charging_limit_conf_t *out) {
    memset(out, 0, sizeof(*out));
    (void)out;
}

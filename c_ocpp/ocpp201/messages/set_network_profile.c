#include "set_network_profile.h"
#include <string.h>

cJSON *ocpp201_set_network_profile_req_to_json(const ocpp201_set_network_profile_req_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (1) ocpp_json_add_int(obj, "configurationSlot", in->configurationSlot);
    { cJSON *ch=ocpp201_network_connection_to_json(&in->connectionData); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "connectionData", ch); }
    return obj;
}
ocpp_err_t ocpp201_set_network_profile_req_from_json(const cJSON *obj, ocpp201_set_network_profile_req_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_int(obj, "configurationSlot", &out->configurationSlot, 1) < 0) return OCPP_ERR_PARSE;
    { cJSON *ch = ocpp_json_get_obj(obj, "connectionData", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_network_connection_from_json(ch, &out->connectionData) != OCPP_OK) return OCPP_ERR_PARSE; }
    return OCPP_OK;
}
ocpp_err_t ocpp201_set_network_profile_req_encode(const ocpp201_set_network_profile_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_set_network_profile_req_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_set_network_profile_req_decode(const char *json, ocpp201_set_network_profile_req_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_set_network_profile_req_from_json(o, out);
}
void ocpp201_set_network_profile_req_example(ocpp201_set_network_profile_req_t *out) {
    memset(out, 0, sizeof(*out));
    out->configurationSlot = 1;
    ocpp201_network_connection_example(&out->connectionData);
}

cJSON *ocpp201_set_network_profile_conf_to_json(const ocpp201_set_network_profile_conf_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "status", in->status) < 0) { cJSON_Delete(obj); return NULL; }
    return obj;
}
ocpp_err_t ocpp201_set_network_profile_conf_from_json(const cJSON *obj, ocpp201_set_network_profile_conf_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "status", out->status, sizeof(out->status), 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
ocpp_err_t ocpp201_set_network_profile_conf_encode(const ocpp201_set_network_profile_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_set_network_profile_conf_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_set_network_profile_conf_decode(const char *json, ocpp201_set_network_profile_conf_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_set_network_profile_conf_from_json(o, out);
}
void ocpp201_set_network_profile_conf_example(ocpp201_set_network_profile_conf_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->status, sizeof(out->status), "Accepted");
}

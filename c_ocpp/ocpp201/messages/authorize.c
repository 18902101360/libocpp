#include "authorize.h"
#include <string.h>

cJSON *ocpp201_authorize_req_to_json(const ocpp201_authorize_req_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    { cJSON *ch=ocpp201_id_token_to_json(&in->idToken); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "idToken", ch); }
    return obj;
}
ocpp_err_t ocpp201_authorize_req_from_json(const cJSON *obj, ocpp201_authorize_req_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    { cJSON *ch = ocpp_json_get_obj(obj, "idToken", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_id_token_from_json(ch, &out->idToken) != OCPP_OK) return OCPP_ERR_PARSE; }
    return OCPP_OK;
}
ocpp_err_t ocpp201_authorize_req_encode(const ocpp201_authorize_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_authorize_req_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_authorize_req_decode(const char *json, ocpp201_authorize_req_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_authorize_req_from_json(o, out);
}
void ocpp201_authorize_req_example(ocpp201_authorize_req_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp201_id_token_example(&out->idToken);
}

cJSON *ocpp201_authorize_conf_to_json(const ocpp201_authorize_conf_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    { cJSON *ch=ocpp201_id_token_info_to_json(&in->idTokenInfo); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "idTokenInfo", ch); }
    return obj;
}
ocpp_err_t ocpp201_authorize_conf_from_json(const cJSON *obj, ocpp201_authorize_conf_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    { cJSON *ch = ocpp_json_get_obj(obj, "idTokenInfo", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_id_token_info_from_json(ch, &out->idTokenInfo) != OCPP_OK) return OCPP_ERR_PARSE; }
    return OCPP_OK;
}
ocpp_err_t ocpp201_authorize_conf_encode(const ocpp201_authorize_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_authorize_conf_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_authorize_conf_decode(const char *json, ocpp201_authorize_conf_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_authorize_conf_from_json(o, out);
}
void ocpp201_authorize_conf_example(ocpp201_authorize_conf_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp201_id_token_info_example(&out->idTokenInfo);
}

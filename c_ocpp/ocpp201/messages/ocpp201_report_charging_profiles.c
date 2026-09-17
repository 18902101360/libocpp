#include "ocpp201_report_charging_profiles.h"
#include <string.h>

cJSON *ocpp201_report_charging_profiles_req_to_json(const ocpp201_report_charging_profiles_req_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (1) ocpp_json_add_int(obj, "requestId", in->requestId);
    if (ocpp_json_add_str(obj, "chargingLimitSource", in->chargingLimitSource) < 0) { cJSON_Delete(obj); return NULL; }
    if (1) ocpp_json_add_int(obj, "evseId", in->evseId);
    { cJSON *arr=cJSON_CreateArray(); int n=in->chargingProfile_count; if(n>2) n=2; for(int i=0;i<n;i++){ cJSON *ch=ocpp201_charging_profile_to_json(&in->chargingProfile[i]); if(ch) cJSON_AddItemToArray(arr,ch); } cJSON_AddItemToObject(obj,"chargingProfile",arr); }
    return obj;
}
ocpp_err_t ocpp201_report_charging_profiles_req_from_json(const cJSON *obj, ocpp201_report_charging_profiles_req_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_int(obj, "requestId", &out->requestId, 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "chargingLimitSource", out->chargingLimitSource, sizeof(out->chargingLimitSource), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_int(obj, "evseId", &out->evseId, 1) < 0) return OCPP_ERR_PARSE;
    { cJSON *arr = ocpp_json_get_arr(obj, "chargingProfile", 1); out->chargingProfile_count=0; if (!arr) return OCPP_ERR_PARSE; if (arr) { int n=cJSON_GetArraySize(arr); if (n>2) n=2; for (int i=0;i<n;i++) { if (ocpp201_charging_profile_from_json(cJSON_GetArrayItem(arr,i), &out->chargingProfile[i])!=OCPP_OK) return OCPP_ERR_PARSE; out->chargingProfile_count++; } } }
    return OCPP_OK;
}
ocpp_err_t ocpp201_report_charging_profiles_req_encode(const ocpp201_report_charging_profiles_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_report_charging_profiles_req_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_report_charging_profiles_req_decode(const char *json, ocpp201_report_charging_profiles_req_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_report_charging_profiles_req_from_json(o, out);
}
void ocpp201_report_charging_profiles_req_example(ocpp201_report_charging_profiles_req_t *out) {
    memset(out, 0, sizeof(*out));
    out->requestId = 1;
    ocpp_str_copy(out->chargingLimitSource, sizeof(out->chargingLimitSource), "CSO");
    out->evseId = 1;
    out->chargingProfile_count = 1;
    ocpp201_charging_profile_example(&out->chargingProfile[0]);
}

cJSON *ocpp201_report_charging_profiles_conf_to_json(const ocpp201_report_charging_profiles_conf_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    (void)in; return obj;
}
ocpp_err_t ocpp201_report_charging_profiles_conf_from_json(const cJSON *obj, ocpp201_report_charging_profiles_conf_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    (void)obj;
    (void)out;
    return OCPP_OK;
}
ocpp_err_t ocpp201_report_charging_profiles_conf_encode(const ocpp201_report_charging_profiles_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_report_charging_profiles_conf_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_report_charging_profiles_conf_decode(const char *json, ocpp201_report_charging_profiles_conf_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_report_charging_profiles_conf_from_json(o, out);
}
void ocpp201_report_charging_profiles_conf_example(ocpp201_report_charging_profiles_conf_t *out) {
    memset(out, 0, sizeof(*out));
    (void)out;
}

#include "ocpp201_clear_variable_monitoring.h"
#include <string.h>

cJSON *ocpp201_clear_variable_monitoring_req_to_json(const ocpp201_clear_variable_monitoring_req_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    (void)in; return obj;
}
ocpp_err_t ocpp201_clear_variable_monitoring_req_from_json(const cJSON *obj, ocpp201_clear_variable_monitoring_req_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    (void)obj;
    (void)out;
    return OCPP_OK;
}
ocpp_err_t ocpp201_clear_variable_monitoring_req_encode(const ocpp201_clear_variable_monitoring_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_clear_variable_monitoring_req_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_clear_variable_monitoring_req_decode(const char *json, ocpp201_clear_variable_monitoring_req_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_clear_variable_monitoring_req_from_json(o, out);
}
void ocpp201_clear_variable_monitoring_req_example(ocpp201_clear_variable_monitoring_req_t *out) {
    memset(out, 0, sizeof(*out));
    (void)out;
}

cJSON *ocpp201_clear_variable_monitoring_conf_to_json(const ocpp201_clear_variable_monitoring_conf_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    { cJSON *arr=cJSON_CreateArray(); int n=in->clearMonitoringResult_count; if(n>4) n=4; for(int i=0;i<n;i++){ cJSON *ch=ocpp201_clear_mon_result_to_json(&in->clearMonitoringResult[i]); if(ch) cJSON_AddItemToArray(arr,ch); } cJSON_AddItemToObject(obj,"clearMonitoringResult",arr); }
    return obj;
}
ocpp_err_t ocpp201_clear_variable_monitoring_conf_from_json(const cJSON *obj, ocpp201_clear_variable_monitoring_conf_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    { cJSON *arr = ocpp_json_get_arr(obj, "clearMonitoringResult", 1); out->clearMonitoringResult_count=0; if (!arr) return OCPP_ERR_PARSE; if (arr) { int n=cJSON_GetArraySize(arr); if (n>4) n=4; for (int i=0;i<n;i++) { if (ocpp201_clear_mon_result_from_json(cJSON_GetArrayItem(arr,i), &out->clearMonitoringResult[i])!=OCPP_OK) return OCPP_ERR_PARSE; out->clearMonitoringResult_count++; } } }
    return OCPP_OK;
}
ocpp_err_t ocpp201_clear_variable_monitoring_conf_encode(const ocpp201_clear_variable_monitoring_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_clear_variable_monitoring_conf_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_clear_variable_monitoring_conf_decode(const char *json, ocpp201_clear_variable_monitoring_conf_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_clear_variable_monitoring_conf_from_json(o, out);
}
void ocpp201_clear_variable_monitoring_conf_example(ocpp201_clear_variable_monitoring_conf_t *out) {
    memset(out, 0, sizeof(*out));
    out->clearMonitoringResult_count = 1;
    ocpp201_clear_mon_result_example(&out->clearMonitoringResult[0]);
}

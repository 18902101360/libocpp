#include "get_variables.h"
#include <string.h>

cJSON *ocpp201_get_variables_req_to_json(const ocpp201_get_variables_req_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    { cJSON *arr=cJSON_CreateArray(); int n=in->getVariableData_count; if(n>4) n=4; for(int i=0;i<n;i++){ cJSON *ch=ocpp201_get_var_data_to_json(&in->getVariableData[i]); if(ch) cJSON_AddItemToArray(arr,ch); } cJSON_AddItemToObject(obj,"getVariableData",arr); }
    return obj;
}
ocpp_err_t ocpp201_get_variables_req_from_json(const cJSON *obj, ocpp201_get_variables_req_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    { cJSON *arr = ocpp_json_get_arr(obj, "getVariableData", 1); out->getVariableData_count=0; if (!arr) return OCPP_ERR_PARSE; if (arr) { int n=cJSON_GetArraySize(arr); if (n>4) n=4; for (int i=0;i<n;i++) { if (ocpp201_get_var_data_from_json(cJSON_GetArrayItem(arr,i), &out->getVariableData[i])!=OCPP_OK) return OCPP_ERR_PARSE; out->getVariableData_count++; } } }
    return OCPP_OK;
}
ocpp_err_t ocpp201_get_variables_req_encode(const ocpp201_get_variables_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_get_variables_req_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_get_variables_req_decode(const char *json, ocpp201_get_variables_req_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_get_variables_req_from_json(o, out);
}
void ocpp201_get_variables_req_example(ocpp201_get_variables_req_t *out) {
    memset(out, 0, sizeof(*out));
    out->getVariableData_count = 1;
    ocpp201_get_var_data_example(&out->getVariableData[0]);
}

cJSON *ocpp201_get_variables_conf_to_json(const ocpp201_get_variables_conf_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    { cJSON *arr=cJSON_CreateArray(); int n=in->getVariableResult_count; if(n>4) n=4; for(int i=0;i<n;i++){ cJSON *ch=ocpp201_get_var_result_to_json(&in->getVariableResult[i]); if(ch) cJSON_AddItemToArray(arr,ch); } cJSON_AddItemToObject(obj,"getVariableResult",arr); }
    return obj;
}
ocpp_err_t ocpp201_get_variables_conf_from_json(const cJSON *obj, ocpp201_get_variables_conf_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    { cJSON *arr = ocpp_json_get_arr(obj, "getVariableResult", 1); out->getVariableResult_count=0; if (!arr) return OCPP_ERR_PARSE; if (arr) { int n=cJSON_GetArraySize(arr); if (n>4) n=4; for (int i=0;i<n;i++) { if (ocpp201_get_var_result_from_json(cJSON_GetArrayItem(arr,i), &out->getVariableResult[i])!=OCPP_OK) return OCPP_ERR_PARSE; out->getVariableResult_count++; } } }
    return OCPP_OK;
}
ocpp_err_t ocpp201_get_variables_conf_encode(const ocpp201_get_variables_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_get_variables_conf_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_get_variables_conf_decode(const char *json, ocpp201_get_variables_conf_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_get_variables_conf_from_json(o, out);
}
void ocpp201_get_variables_conf_example(ocpp201_get_variables_conf_t *out) {
    memset(out, 0, sizeof(*out));
    out->getVariableResult_count = 1;
    ocpp201_get_var_result_example(&out->getVariableResult[0]);
}

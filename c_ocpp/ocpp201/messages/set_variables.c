#include "set_variables.h"
#include <string.h>

cJSON *ocpp201_set_variables_req_to_json(const ocpp201_set_variables_req_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    { cJSON *arr=cJSON_CreateArray(); int n=in->setVariableData_count; if(n>4) n=4; for(int i=0;i<n;i++){ cJSON *ch=ocpp201_set_var_data_to_json(&in->setVariableData[i]); if(ch) cJSON_AddItemToArray(arr,ch); } cJSON_AddItemToObject(obj,"setVariableData",arr); }
    return obj;
}
ocpp_err_t ocpp201_set_variables_req_from_json(const cJSON *obj, ocpp201_set_variables_req_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    { cJSON *arr = ocpp_json_get_arr(obj, "setVariableData", 1); out->setVariableData_count=0; if (!arr) return OCPP_ERR_PARSE; if (arr) { int n=cJSON_GetArraySize(arr); if (n>4) n=4; for (int i=0;i<n;i++) { if (ocpp201_set_var_data_from_json(cJSON_GetArrayItem(arr,i), &out->setVariableData[i])!=OCPP_OK) return OCPP_ERR_PARSE; out->setVariableData_count++; } } }
    return OCPP_OK;
}
ocpp_err_t ocpp201_set_variables_req_encode(const ocpp201_set_variables_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_set_variables_req_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_set_variables_req_decode(const char *json, ocpp201_set_variables_req_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_set_variables_req_from_json(o, out);
}
void ocpp201_set_variables_req_example(ocpp201_set_variables_req_t *out) {
    memset(out, 0, sizeof(*out));
    out->setVariableData_count = 1;
    ocpp201_set_var_data_example(&out->setVariableData[0]);
}

cJSON *ocpp201_set_variables_conf_to_json(const ocpp201_set_variables_conf_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    { cJSON *arr=cJSON_CreateArray(); int n=in->setVariableResult_count; if(n>4) n=4; for(int i=0;i<n;i++){ cJSON *ch=ocpp201_set_var_result_to_json(&in->setVariableResult[i]); if(ch) cJSON_AddItemToArray(arr,ch); } cJSON_AddItemToObject(obj,"setVariableResult",arr); }
    return obj;
}
ocpp_err_t ocpp201_set_variables_conf_from_json(const cJSON *obj, ocpp201_set_variables_conf_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    { cJSON *arr = ocpp_json_get_arr(obj, "setVariableResult", 1); out->setVariableResult_count=0; if (!arr) return OCPP_ERR_PARSE; if (arr) { int n=cJSON_GetArraySize(arr); if (n>4) n=4; for (int i=0;i<n;i++) { if (ocpp201_set_var_result_from_json(cJSON_GetArrayItem(arr,i), &out->setVariableResult[i])!=OCPP_OK) return OCPP_ERR_PARSE; out->setVariableResult_count++; } } }
    return OCPP_OK;
}
ocpp_err_t ocpp201_set_variables_conf_encode(const ocpp201_set_variables_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_set_variables_conf_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_set_variables_conf_decode(const char *json, ocpp201_set_variables_conf_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_set_variables_conf_from_json(o, out);
}
void ocpp201_set_variables_conf_example(ocpp201_set_variables_conf_t *out) {
    memset(out, 0, sizeof(*out));
    out->setVariableResult_count = 1;
    ocpp201_set_var_result_example(&out->setVariableResult[0]);
}

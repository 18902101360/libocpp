#include "ocpp201_types.h"
#include "ocpp_json.h"
#include <string.h>

cJSON *ocpp201_status_info_to_json(const ocpp201_status_info_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "reasonCode", in->reasonCode) < 0) { cJSON_Delete(obj); return NULL; }
    if (in->has_additionalInfo) ocpp_json_add_str(obj, "additionalInfo", in->additionalInfo);
    return obj;
}
ocpp_err_t ocpp201_status_info_from_json(const cJSON *obj, ocpp201_status_info_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "reasonCode", out->reasonCode, sizeof(out->reasonCode), 1) < 0) return OCPP_ERR_PARSE;
    out->has_additionalInfo = ocpp_json_get_str(obj, "additionalInfo", out->additionalInfo, sizeof(out->additionalInfo), 0) > 0;
    return OCPP_OK;
}
void ocpp201_status_info_example(ocpp201_status_info_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->reasonCode, sizeof(out->reasonCode), "Accepted");
}

cJSON *ocpp201_id_token_to_json(const ocpp201_id_token_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "idToken", in->idToken) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "type", in->type) < 0) { cJSON_Delete(obj); return NULL; }
    return obj;
}
ocpp_err_t ocpp201_id_token_from_json(const cJSON *obj, ocpp201_id_token_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "idToken", out->idToken, sizeof(out->idToken), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "type", out->type, sizeof(out->type), 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
void ocpp201_id_token_example(ocpp201_id_token_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->idToken, sizeof(out->idToken), "TAG001");
    ocpp_str_copy(out->type, sizeof(out->type), "ISO14443");
}

cJSON *ocpp201_id_token_info_to_json(const ocpp201_id_token_info_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "status", in->status) < 0) { cJSON_Delete(obj); return NULL; }
    return obj;
}
ocpp_err_t ocpp201_id_token_info_from_json(const cJSON *obj, ocpp201_id_token_info_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "status", out->status, sizeof(out->status), 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
void ocpp201_id_token_info_example(ocpp201_id_token_info_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->status, sizeof(out->status), "Accepted");
}

cJSON *ocpp201_charging_station_to_json(const ocpp201_charging_station_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "model", in->model) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "vendorName", in->vendorName) < 0) { cJSON_Delete(obj); return NULL; }
    if (in->has_serialNumber) ocpp_json_add_str(obj, "serialNumber", in->serialNumber);
    if (in->has_firmwareVersion) ocpp_json_add_str(obj, "firmwareVersion", in->firmwareVersion);
    return obj;
}
ocpp_err_t ocpp201_charging_station_from_json(const cJSON *obj, ocpp201_charging_station_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "model", out->model, sizeof(out->model), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "vendorName", out->vendorName, sizeof(out->vendorName), 1) < 0) return OCPP_ERR_PARSE;
    out->has_serialNumber = ocpp_json_get_str(obj, "serialNumber", out->serialNumber, sizeof(out->serialNumber), 0) > 0;
    out->has_firmwareVersion = ocpp_json_get_str(obj, "firmwareVersion", out->firmwareVersion, sizeof(out->firmwareVersion), 0) > 0;
    return OCPP_OK;
}
void ocpp201_charging_station_example(ocpp201_charging_station_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->model, sizeof(out->model), "C-OCPP");
    ocpp_str_copy(out->vendorName, sizeof(out->vendorName), "Pionix");
}

cJSON *ocpp201_evse_to_json(const ocpp201_evse_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (1) ocpp_json_add_int(obj, "id", in->id);
    if (in->has_connectorId) ocpp_json_add_int(obj, "connectorId", in->connectorId);
    return obj;
}
ocpp_err_t ocpp201_evse_from_json(const cJSON *obj, ocpp201_evse_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_int(obj, "id", &out->id, 1) < 0) return OCPP_ERR_PARSE;
    out->has_connectorId = ocpp_json_get_int(obj, "connectorId", &out->connectorId, 0) > 0;
    return OCPP_OK;
}
void ocpp201_evse_example(ocpp201_evse_t *out) {
    memset(out, 0, sizeof(*out));
    out->id = 1;
}

cJSON *ocpp201_component_to_json(const ocpp201_component_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "name", in->name) < 0) { cJSON_Delete(obj); return NULL; }
    if (in->has_instance) ocpp_json_add_str(obj, "instance", in->instance);
    return obj;
}
ocpp_err_t ocpp201_component_from_json(const cJSON *obj, ocpp201_component_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "name", out->name, sizeof(out->name), 1) < 0) return OCPP_ERR_PARSE;
    out->has_instance = ocpp_json_get_str(obj, "instance", out->instance, sizeof(out->instance), 0) > 0;
    return OCPP_OK;
}
void ocpp201_component_example(ocpp201_component_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->name, sizeof(out->name), "OCPPCommCtrlr");
}

cJSON *ocpp201_variable_to_json(const ocpp201_variable_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "name", in->name) < 0) { cJSON_Delete(obj); return NULL; }
    if (in->has_instance) ocpp_json_add_str(obj, "instance", in->instance);
    return obj;
}
ocpp_err_t ocpp201_variable_from_json(const cJSON *obj, ocpp201_variable_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "name", out->name, sizeof(out->name), 1) < 0) return OCPP_ERR_PARSE;
    out->has_instance = ocpp_json_get_str(obj, "instance", out->instance, sizeof(out->instance), 0) > 0;
    return OCPP_OK;
}
void ocpp201_variable_example(ocpp201_variable_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->name, sizeof(out->name), "HeartbeatInterval");
}

cJSON *ocpp201_sampled_value_to_json(const ocpp201_sampled_value_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (1) ocpp_json_add_double(obj, "value", in->value);
    if (in->has_measurand) ocpp_json_add_str(obj, "measurand", in->measurand);
    return obj;
}
ocpp_err_t ocpp201_sampled_value_from_json(const cJSON *obj, ocpp201_sampled_value_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_double(obj, "value", &out->value, 1) < 0) return OCPP_ERR_PARSE;
    out->has_measurand = ocpp_json_get_str(obj, "measurand", out->measurand, sizeof(out->measurand), 0) > 0;
    return OCPP_OK;
}
void ocpp201_sampled_value_example(ocpp201_sampled_value_t *out) {
    memset(out, 0, sizeof(*out));
    out->value = 1234.0;
    out->has_measurand = 1;
    ocpp_str_copy(out->measurand, sizeof(out->measurand), "Energy.Active.Import.Register");
}

cJSON *ocpp201_meter_value_to_json(const ocpp201_meter_value_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "timestamp", in->timestamp) < 0) { cJSON_Delete(obj); return NULL; }
    { cJSON *arr=cJSON_CreateArray(); int n=in->sampledValue_count; if(n>8) n=8; for(int i=0;i<n;i++){ cJSON *ch=ocpp201_sampled_value_to_json(&in->sampledValue[i]); if(ch) cJSON_AddItemToArray(arr,ch); } cJSON_AddItemToObject(obj,"sampledValue",arr); }
    return obj;
}
ocpp_err_t ocpp201_meter_value_from_json(const cJSON *obj, ocpp201_meter_value_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "timestamp", out->timestamp, sizeof(out->timestamp), 1) < 0) return OCPP_ERR_PARSE;
    { cJSON *arr = ocpp_json_get_arr(obj, "sampledValue", 1); out->sampledValue_count=0; if (!arr) return OCPP_ERR_PARSE; if (arr) { int n=cJSON_GetArraySize(arr); if (n>8) n=8; for (int i=0;i<n;i++) { if (ocpp201_sampled_value_from_json(cJSON_GetArrayItem(arr,i), &out->sampledValue[i])!=OCPP_OK) return OCPP_ERR_PARSE; out->sampledValue_count++; } } }
    return OCPP_OK;
}
void ocpp201_meter_value_example(ocpp201_meter_value_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->timestamp, sizeof(out->timestamp), "2024-01-01T00:00:00Z");
    out->sampledValue_count = 1;
    ocpp201_sampled_value_example(&out->sampledValue[0]);
}

cJSON *ocpp201_cs_period_to_json(const ocpp201_cs_period_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (1) ocpp_json_add_int(obj, "startPeriod", in->startPeriod);
    if (1) ocpp_json_add_double(obj, "limit", in->limit);
    return obj;
}
ocpp_err_t ocpp201_cs_period_from_json(const cJSON *obj, ocpp201_cs_period_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_int(obj, "startPeriod", &out->startPeriod, 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_double(obj, "limit", &out->limit, 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
void ocpp201_cs_period_example(ocpp201_cs_period_t *out) {
    memset(out, 0, sizeof(*out));
    out->startPeriod = 0;
    out->limit = 16.0;
}

cJSON *ocpp201_charging_schedule_to_json(const ocpp201_charging_schedule_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (1) ocpp_json_add_int(obj, "id", in->id);
    if (ocpp_json_add_str(obj, "chargingRateUnit", in->chargingRateUnit) < 0) { cJSON_Delete(obj); return NULL; }
    { cJSON *arr=cJSON_CreateArray(); int n=in->chargingSchedulePeriod_count; if(n>8) n=8; for(int i=0;i<n;i++){ cJSON *ch=ocpp201_cs_period_to_json(&in->chargingSchedulePeriod[i]); if(ch) cJSON_AddItemToArray(arr,ch); } cJSON_AddItemToObject(obj,"chargingSchedulePeriod",arr); }
    return obj;
}
ocpp_err_t ocpp201_charging_schedule_from_json(const cJSON *obj, ocpp201_charging_schedule_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_int(obj, "id", &out->id, 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "chargingRateUnit", out->chargingRateUnit, sizeof(out->chargingRateUnit), 1) < 0) return OCPP_ERR_PARSE;
    { cJSON *arr = ocpp_json_get_arr(obj, "chargingSchedulePeriod", 1); out->chargingSchedulePeriod_count=0; if (!arr) return OCPP_ERR_PARSE; if (arr) { int n=cJSON_GetArraySize(arr); if (n>8) n=8; for (int i=0;i<n;i++) { if (ocpp201_cs_period_from_json(cJSON_GetArrayItem(arr,i), &out->chargingSchedulePeriod[i])!=OCPP_OK) return OCPP_ERR_PARSE; out->chargingSchedulePeriod_count++; } } }
    return OCPP_OK;
}
void ocpp201_charging_schedule_example(ocpp201_charging_schedule_t *out) {
    memset(out, 0, sizeof(*out));
    out->id = 1;
    ocpp_str_copy(out->chargingRateUnit, sizeof(out->chargingRateUnit), "A");
    out->chargingSchedulePeriod_count = 1;
    ocpp201_cs_period_example(&out->chargingSchedulePeriod[0]);
}

cJSON *ocpp201_charging_profile_to_json(const ocpp201_charging_profile_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (1) ocpp_json_add_int(obj, "id", in->id);
    if (1) ocpp_json_add_int(obj, "stackLevel", in->stackLevel);
    if (ocpp_json_add_str(obj, "chargingProfilePurpose", in->chargingProfilePurpose) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "chargingProfileKind", in->chargingProfileKind) < 0) { cJSON_Delete(obj); return NULL; }
    { cJSON *arr=cJSON_CreateArray(); int n=in->chargingSchedule_count; if(n>2) n=2; for(int i=0;i<n;i++){ cJSON *ch=ocpp201_charging_schedule_to_json(&in->chargingSchedule[i]); if(ch) cJSON_AddItemToArray(arr,ch); } cJSON_AddItemToObject(obj,"chargingSchedule",arr); }
    return obj;
}
ocpp_err_t ocpp201_charging_profile_from_json(const cJSON *obj, ocpp201_charging_profile_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_int(obj, "id", &out->id, 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_int(obj, "stackLevel", &out->stackLevel, 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "chargingProfilePurpose", out->chargingProfilePurpose, sizeof(out->chargingProfilePurpose), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "chargingProfileKind", out->chargingProfileKind, sizeof(out->chargingProfileKind), 1) < 0) return OCPP_ERR_PARSE;
    { cJSON *arr = ocpp_json_get_arr(obj, "chargingSchedule", 1); out->chargingSchedule_count=0; if (!arr) return OCPP_ERR_PARSE; if (arr) { int n=cJSON_GetArraySize(arr); if (n>2) n=2; for (int i=0;i<n;i++) { if (ocpp201_charging_schedule_from_json(cJSON_GetArrayItem(arr,i), &out->chargingSchedule[i])!=OCPP_OK) return OCPP_ERR_PARSE; out->chargingSchedule_count++; } } }
    return OCPP_OK;
}
void ocpp201_charging_profile_example(ocpp201_charging_profile_t *out) {
    memset(out, 0, sizeof(*out));
    out->id = 1;
    out->stackLevel = 0;
    ocpp_str_copy(out->chargingProfilePurpose, sizeof(out->chargingProfilePurpose), "TxDefaultProfile");
    ocpp_str_copy(out->chargingProfileKind, sizeof(out->chargingProfileKind), "Absolute");
    out->chargingSchedule_count = 1;
    ocpp201_charging_schedule_example(&out->chargingSchedule[0]);
}

cJSON *ocpp201_ocsp_to_json(const ocpp201_ocsp_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "hashAlgorithm", in->hashAlgorithm) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "issuerNameHash", in->issuerNameHash) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "issuerKeyHash", in->issuerKeyHash) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "serialNumber", in->serialNumber) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "responderURL", in->responderURL) < 0) { cJSON_Delete(obj); return NULL; }
    return obj;
}
ocpp_err_t ocpp201_ocsp_from_json(const cJSON *obj, ocpp201_ocsp_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "hashAlgorithm", out->hashAlgorithm, sizeof(out->hashAlgorithm), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "issuerNameHash", out->issuerNameHash, sizeof(out->issuerNameHash), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "issuerKeyHash", out->issuerKeyHash, sizeof(out->issuerKeyHash), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "serialNumber", out->serialNumber, sizeof(out->serialNumber), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "responderURL", out->responderURL, sizeof(out->responderURL), 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
void ocpp201_ocsp_example(ocpp201_ocsp_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->hashAlgorithm, sizeof(out->hashAlgorithm), "SHA256");
    ocpp_str_copy(out->issuerNameHash, sizeof(out->issuerNameHash), "aa");
    ocpp_str_copy(out->issuerKeyHash, sizeof(out->issuerKeyHash), "bb");
    ocpp_str_copy(out->serialNumber, sizeof(out->serialNumber), "1");
    ocpp_str_copy(out->responderURL, sizeof(out->responderURL), "http://ocsp.example");
}

cJSON *ocpp201_cert_hash_to_json(const ocpp201_cert_hash_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "hashAlgorithm", in->hashAlgorithm) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "issuerNameHash", in->issuerNameHash) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "issuerKeyHash", in->issuerKeyHash) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "serialNumber", in->serialNumber) < 0) { cJSON_Delete(obj); return NULL; }
    return obj;
}
ocpp_err_t ocpp201_cert_hash_from_json(const cJSON *obj, ocpp201_cert_hash_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "hashAlgorithm", out->hashAlgorithm, sizeof(out->hashAlgorithm), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "issuerNameHash", out->issuerNameHash, sizeof(out->issuerNameHash), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "issuerKeyHash", out->issuerKeyHash, sizeof(out->issuerKeyHash), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "serialNumber", out->serialNumber, sizeof(out->serialNumber), 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
void ocpp201_cert_hash_example(ocpp201_cert_hash_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->hashAlgorithm, sizeof(out->hashAlgorithm), "SHA256");
    ocpp_str_copy(out->issuerNameHash, sizeof(out->issuerNameHash), "aa");
    ocpp_str_copy(out->issuerKeyHash, sizeof(out->issuerKeyHash), "bb");
    ocpp_str_copy(out->serialNumber, sizeof(out->serialNumber), "1");
}

cJSON *ocpp201_log_params_to_json(const ocpp201_log_params_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "remoteLocation", in->remoteLocation) < 0) { cJSON_Delete(obj); return NULL; }
    return obj;
}
ocpp_err_t ocpp201_log_params_from_json(const cJSON *obj, ocpp201_log_params_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "remoteLocation", out->remoteLocation, sizeof(out->remoteLocation), 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
void ocpp201_log_params_example(ocpp201_log_params_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->remoteLocation, sizeof(out->remoteLocation), "ftp://example/log");
}

cJSON *ocpp201_firmware_to_json(const ocpp201_firmware_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "location", in->location) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "retrieveDateTime", in->retrieveDateTime) < 0) { cJSON_Delete(obj); return NULL; }
    return obj;
}
ocpp_err_t ocpp201_firmware_from_json(const cJSON *obj, ocpp201_firmware_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "location", out->location, sizeof(out->location), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "retrieveDateTime", out->retrieveDateTime, sizeof(out->retrieveDateTime), 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
void ocpp201_firmware_example(ocpp201_firmware_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->location, sizeof(out->location), "https://example/fw.bin");
    ocpp_str_copy(out->retrieveDateTime, sizeof(out->retrieveDateTime), "2024-01-01T00:00:00Z");
}

cJSON *ocpp201_network_connection_to_json(const ocpp201_network_connection_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "ocppVersion", in->ocppVersion) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "ocppTransport", in->ocppTransport) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "ocppCsmsUrl", in->ocppCsmsUrl) < 0) { cJSON_Delete(obj); return NULL; }
    if (1) ocpp_json_add_int(obj, "messageTimeout", in->messageTimeout);
    if (1) ocpp_json_add_int(obj, "securityProfile", in->securityProfile);
    if (ocpp_json_add_str(obj, "ocppInterface", in->ocppInterface) < 0) { cJSON_Delete(obj); return NULL; }
    return obj;
}
ocpp_err_t ocpp201_network_connection_from_json(const cJSON *obj, ocpp201_network_connection_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "ocppVersion", out->ocppVersion, sizeof(out->ocppVersion), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "ocppTransport", out->ocppTransport, sizeof(out->ocppTransport), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "ocppCsmsUrl", out->ocppCsmsUrl, sizeof(out->ocppCsmsUrl), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_int(obj, "messageTimeout", &out->messageTimeout, 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_int(obj, "securityProfile", &out->securityProfile, 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "ocppInterface", out->ocppInterface, sizeof(out->ocppInterface), 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
void ocpp201_network_connection_example(ocpp201_network_connection_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->ocppVersion, sizeof(out->ocppVersion), "OCPP20");
    ocpp_str_copy(out->ocppTransport, sizeof(out->ocppTransport), "JSON");
    ocpp_str_copy(out->ocppCsmsUrl, sizeof(out->ocppCsmsUrl), "ws://127.0.0.1:9000");
    out->messageTimeout = 30;
    out->securityProfile = 1;
    ocpp_str_copy(out->ocppInterface, sizeof(out->ocppInterface), "Wired0");
}

cJSON *ocpp201_message_content_to_json(const ocpp201_message_content_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "format", in->format) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "content", in->content) < 0) { cJSON_Delete(obj); return NULL; }
    return obj;
}
ocpp_err_t ocpp201_message_content_from_json(const cJSON *obj, ocpp201_message_content_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "format", out->format, sizeof(out->format), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "content", out->content, sizeof(out->content), 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
void ocpp201_message_content_example(ocpp201_message_content_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->format, sizeof(out->format), "UTF8");
    ocpp_str_copy(out->content, sizeof(out->content), "Hello");
}

cJSON *ocpp201_display_message_to_json(const ocpp201_display_message_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (1) ocpp_json_add_int(obj, "id", in->id);
    if (ocpp_json_add_str(obj, "priority", in->priority) < 0) { cJSON_Delete(obj); return NULL; }
    { cJSON *ch=ocpp201_message_content_to_json(&in->message); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "message", ch); }
    return obj;
}
ocpp_err_t ocpp201_display_message_from_json(const cJSON *obj, ocpp201_display_message_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_int(obj, "id", &out->id, 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "priority", out->priority, sizeof(out->priority), 1) < 0) return OCPP_ERR_PARSE;
    { cJSON *ch = ocpp_json_get_obj(obj, "message", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_message_content_from_json(ch, &out->message) != OCPP_OK) return OCPP_ERR_PARSE; }
    return OCPP_OK;
}
void ocpp201_display_message_example(ocpp201_display_message_t *out) {
    memset(out, 0, sizeof(*out));
    out->id = 1;
    ocpp_str_copy(out->priority, sizeof(out->priority), "NormalCycle");
    ocpp201_message_content_example(&out->message);
}

cJSON *ocpp201_get_var_data_to_json(const ocpp201_get_var_data_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    { cJSON *ch=ocpp201_component_to_json(&in->component); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "component", ch); }
    { cJSON *ch=ocpp201_variable_to_json(&in->variable); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "variable", ch); }
    return obj;
}
ocpp_err_t ocpp201_get_var_data_from_json(const cJSON *obj, ocpp201_get_var_data_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    { cJSON *ch = ocpp_json_get_obj(obj, "component", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_component_from_json(ch, &out->component) != OCPP_OK) return OCPP_ERR_PARSE; }
    { cJSON *ch = ocpp_json_get_obj(obj, "variable", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_variable_from_json(ch, &out->variable) != OCPP_OK) return OCPP_ERR_PARSE; }
    return OCPP_OK;
}
void ocpp201_get_var_data_example(ocpp201_get_var_data_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp201_component_example(&out->component);
    ocpp201_variable_example(&out->variable);
}

cJSON *ocpp201_get_var_result_to_json(const ocpp201_get_var_result_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "attributeStatus", in->attributeStatus) < 0) { cJSON_Delete(obj); return NULL; }
    { cJSON *ch=ocpp201_component_to_json(&in->component); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "component", ch); }
    { cJSON *ch=ocpp201_variable_to_json(&in->variable); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "variable", ch); }
    if (in->has_attributeValue) ocpp_json_add_str(obj, "attributeValue", in->attributeValue);
    return obj;
}
ocpp_err_t ocpp201_get_var_result_from_json(const cJSON *obj, ocpp201_get_var_result_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "attributeStatus", out->attributeStatus, sizeof(out->attributeStatus), 1) < 0) return OCPP_ERR_PARSE;
    { cJSON *ch = ocpp_json_get_obj(obj, "component", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_component_from_json(ch, &out->component) != OCPP_OK) return OCPP_ERR_PARSE; }
    { cJSON *ch = ocpp_json_get_obj(obj, "variable", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_variable_from_json(ch, &out->variable) != OCPP_OK) return OCPP_ERR_PARSE; }
    out->has_attributeValue = ocpp_json_get_str(obj, "attributeValue", out->attributeValue, sizeof(out->attributeValue), 0) > 0;
    return OCPP_OK;
}
void ocpp201_get_var_result_example(ocpp201_get_var_result_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->attributeStatus, sizeof(out->attributeStatus), "Accepted");
    ocpp201_component_example(&out->component);
    ocpp201_variable_example(&out->variable);
    out->has_attributeValue = 1;
    ocpp_str_copy(out->attributeValue, sizeof(out->attributeValue), "300");
}

cJSON *ocpp201_set_var_data_to_json(const ocpp201_set_var_data_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "attributeValue", in->attributeValue) < 0) { cJSON_Delete(obj); return NULL; }
    { cJSON *ch=ocpp201_component_to_json(&in->component); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "component", ch); }
    { cJSON *ch=ocpp201_variable_to_json(&in->variable); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "variable", ch); }
    return obj;
}
ocpp_err_t ocpp201_set_var_data_from_json(const cJSON *obj, ocpp201_set_var_data_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "attributeValue", out->attributeValue, sizeof(out->attributeValue), 1) < 0) return OCPP_ERR_PARSE;
    { cJSON *ch = ocpp_json_get_obj(obj, "component", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_component_from_json(ch, &out->component) != OCPP_OK) return OCPP_ERR_PARSE; }
    { cJSON *ch = ocpp_json_get_obj(obj, "variable", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_variable_from_json(ch, &out->variable) != OCPP_OK) return OCPP_ERR_PARSE; }
    return OCPP_OK;
}
void ocpp201_set_var_data_example(ocpp201_set_var_data_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->attributeValue, sizeof(out->attributeValue), "300");
    ocpp201_component_example(&out->component);
    ocpp201_variable_example(&out->variable);
}

cJSON *ocpp201_set_var_result_to_json(const ocpp201_set_var_result_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "attributeStatus", in->attributeStatus) < 0) { cJSON_Delete(obj); return NULL; }
    { cJSON *ch=ocpp201_component_to_json(&in->component); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "component", ch); }
    { cJSON *ch=ocpp201_variable_to_json(&in->variable); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "variable", ch); }
    return obj;
}
ocpp_err_t ocpp201_set_var_result_from_json(const cJSON *obj, ocpp201_set_var_result_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "attributeStatus", out->attributeStatus, sizeof(out->attributeStatus), 1) < 0) return OCPP_ERR_PARSE;
    { cJSON *ch = ocpp_json_get_obj(obj, "component", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_component_from_json(ch, &out->component) != OCPP_OK) return OCPP_ERR_PARSE; }
    { cJSON *ch = ocpp_json_get_obj(obj, "variable", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_variable_from_json(ch, &out->variable) != OCPP_OK) return OCPP_ERR_PARSE; }
    return OCPP_OK;
}
void ocpp201_set_var_result_example(ocpp201_set_var_result_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->attributeStatus, sizeof(out->attributeStatus), "Accepted");
    ocpp201_component_example(&out->component);
    ocpp201_variable_example(&out->variable);
}

cJSON *ocpp201_charging_limit_to_json(const ocpp201_charging_limit_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "chargingLimitSource", in->chargingLimitSource) < 0) { cJSON_Delete(obj); return NULL; }
    return obj;
}
ocpp_err_t ocpp201_charging_limit_from_json(const cJSON *obj, ocpp201_charging_limit_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "chargingLimitSource", out->chargingLimitSource, sizeof(out->chargingLimitSource), 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
void ocpp201_charging_limit_example(ocpp201_charging_limit_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->chargingLimitSource, sizeof(out->chargingLimitSource), "EMS");
}

cJSON *ocpp201_charging_needs_to_json(const ocpp201_charging_needs_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "requestedEnergyTransfer", in->requestedEnergyTransfer) < 0) { cJSON_Delete(obj); return NULL; }
    return obj;
}
ocpp_err_t ocpp201_charging_needs_from_json(const cJSON *obj, ocpp201_charging_needs_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "requestedEnergyTransfer", out->requestedEnergyTransfer, sizeof(out->requestedEnergyTransfer), 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
void ocpp201_charging_needs_example(ocpp201_charging_needs_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->requestedEnergyTransfer, sizeof(out->requestedEnergyTransfer), "AC_single_phase");
}

cJSON *ocpp201_event_data_to_json(const ocpp201_event_data_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (1) ocpp_json_add_int(obj, "eventId", in->eventId);
    if (ocpp_json_add_str(obj, "timestamp", in->timestamp) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "trigger", in->trigger) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "actualValue", in->actualValue) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "eventNotificationType", in->eventNotificationType) < 0) { cJSON_Delete(obj); return NULL; }
    { cJSON *ch=ocpp201_component_to_json(&in->component); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "component", ch); }
    { cJSON *ch=ocpp201_variable_to_json(&in->variable); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "variable", ch); }
    return obj;
}
ocpp_err_t ocpp201_event_data_from_json(const cJSON *obj, ocpp201_event_data_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_int(obj, "eventId", &out->eventId, 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "timestamp", out->timestamp, sizeof(out->timestamp), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "trigger", out->trigger, sizeof(out->trigger), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "actualValue", out->actualValue, sizeof(out->actualValue), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "eventNotificationType", out->eventNotificationType, sizeof(out->eventNotificationType), 1) < 0) return OCPP_ERR_PARSE;
    { cJSON *ch = ocpp_json_get_obj(obj, "component", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_component_from_json(ch, &out->component) != OCPP_OK) return OCPP_ERR_PARSE; }
    { cJSON *ch = ocpp_json_get_obj(obj, "variable", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_variable_from_json(ch, &out->variable) != OCPP_OK) return OCPP_ERR_PARSE; }
    return OCPP_OK;
}
void ocpp201_event_data_example(ocpp201_event_data_t *out) {
    memset(out, 0, sizeof(*out));
    out->eventId = 1;
    ocpp_str_copy(out->timestamp, sizeof(out->timestamp), "2024-01-01T00:00:00Z");
    ocpp_str_copy(out->trigger, sizeof(out->trigger), "Alerting");
    ocpp_str_copy(out->actualValue, sizeof(out->actualValue), "1");
    ocpp_str_copy(out->eventNotificationType, sizeof(out->eventNotificationType), "HardWiredNotification");
    ocpp201_component_example(&out->component);
    ocpp201_variable_example(&out->variable);
}

cJSON *ocpp201_transaction_info_to_json(const ocpp201_transaction_info_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "transactionId", in->transactionId) < 0) { cJSON_Delete(obj); return NULL; }
    return obj;
}
ocpp_err_t ocpp201_transaction_info_from_json(const cJSON *obj, ocpp201_transaction_info_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "transactionId", out->transactionId, sizeof(out->transactionId), 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
void ocpp201_transaction_info_example(ocpp201_transaction_info_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->transactionId, sizeof(out->transactionId), "tx-1");
}

cJSON *ocpp201_monitor_data_to_json(const ocpp201_monitor_data_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (1) ocpp_json_add_double(obj, "value", in->value);
    if (ocpp_json_add_str(obj, "type", in->type) < 0) { cJSON_Delete(obj); return NULL; }
    if (1) ocpp_json_add_int(obj, "severity", in->severity);
    { cJSON *ch=ocpp201_component_to_json(&in->component); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "component", ch); }
    { cJSON *ch=ocpp201_variable_to_json(&in->variable); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "variable", ch); }
    return obj;
}
ocpp_err_t ocpp201_monitor_data_from_json(const cJSON *obj, ocpp201_monitor_data_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_double(obj, "value", &out->value, 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "type", out->type, sizeof(out->type), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_int(obj, "severity", &out->severity, 1) < 0) return OCPP_ERR_PARSE;
    { cJSON *ch = ocpp_json_get_obj(obj, "component", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_component_from_json(ch, &out->component) != OCPP_OK) return OCPP_ERR_PARSE; }
    { cJSON *ch = ocpp_json_get_obj(obj, "variable", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_variable_from_json(ch, &out->variable) != OCPP_OK) return OCPP_ERR_PARSE; }
    return OCPP_OK;
}
void ocpp201_monitor_data_example(ocpp201_monitor_data_t *out) {
    memset(out, 0, sizeof(*out));
    out->value = 1.0;
    ocpp_str_copy(out->type, sizeof(out->type), "UpperThreshold");
    out->severity = 3;
    ocpp201_component_example(&out->component);
    ocpp201_variable_example(&out->variable);
}

cJSON *ocpp201_monitor_result_to_json(const ocpp201_monitor_result_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "status", in->status) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "type", in->type) < 0) { cJSON_Delete(obj); return NULL; }
    if (1) ocpp_json_add_int(obj, "severity", in->severity);
    { cJSON *ch=ocpp201_component_to_json(&in->component); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "component", ch); }
    { cJSON *ch=ocpp201_variable_to_json(&in->variable); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "variable", ch); }
    return obj;
}
ocpp_err_t ocpp201_monitor_result_from_json(const cJSON *obj, ocpp201_monitor_result_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "status", out->status, sizeof(out->status), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "type", out->type, sizeof(out->type), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_int(obj, "severity", &out->severity, 1) < 0) return OCPP_ERR_PARSE;
    { cJSON *ch = ocpp_json_get_obj(obj, "component", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_component_from_json(ch, &out->component) != OCPP_OK) return OCPP_ERR_PARSE; }
    { cJSON *ch = ocpp_json_get_obj(obj, "variable", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_variable_from_json(ch, &out->variable) != OCPP_OK) return OCPP_ERR_PARSE; }
    return OCPP_OK;
}
void ocpp201_monitor_result_example(ocpp201_monitor_result_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->status, sizeof(out->status), "Accepted");
    ocpp_str_copy(out->type, sizeof(out->type), "UpperThreshold");
    out->severity = 3;
    ocpp201_component_example(&out->component);
    ocpp201_variable_example(&out->variable);
}

cJSON *ocpp201_clear_mon_result_to_json(const ocpp201_clear_mon_result_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "status", in->status) < 0) { cJSON_Delete(obj); return NULL; }
    if (1) ocpp_json_add_int(obj, "id", in->id);
    return obj;
}
ocpp_err_t ocpp201_clear_mon_result_from_json(const cJSON *obj, ocpp201_clear_mon_result_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "status", out->status, sizeof(out->status), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_int(obj, "id", &out->id, 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
void ocpp201_clear_mon_result_example(ocpp201_clear_mon_result_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->status, sizeof(out->status), "Accepted");
    out->id = 1;
}

cJSON *ocpp201_charging_profile_criterion_to_json(const ocpp201_charging_profile_criterion_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (in->has_chargingProfilePurpose) ocpp_json_add_str(obj, "chargingProfilePurpose", in->chargingProfilePurpose);
    return obj;
}
ocpp_err_t ocpp201_charging_profile_criterion_from_json(const cJSON *obj, ocpp201_charging_profile_criterion_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    out->has_chargingProfilePurpose = ocpp_json_get_str(obj, "chargingProfilePurpose", out->chargingProfilePurpose, sizeof(out->chargingProfilePurpose), 0) > 0;
    return OCPP_OK;
}
void ocpp201_charging_profile_criterion_example(ocpp201_charging_profile_criterion_t *out) {
    memset(out, 0, sizeof(*out));
    out->has_chargingProfilePurpose = 1;
    ocpp_str_copy(out->chargingProfilePurpose, sizeof(out->chargingProfilePurpose), "TxProfile");
}

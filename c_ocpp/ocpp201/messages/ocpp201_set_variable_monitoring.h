#ifndef OCPP201_SET_VARIABLE_MONITORING_H
#define OCPP201_SET_VARIABLE_MONITORING_H
#include "ocpp201_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"
#ifdef __cplusplus
extern "C" {
#endif
#define OCPP201_SET_VARIABLE_MONITORING_ACTION "SetVariableMonitoring"
typedef struct ocpp201_set_variable_monitoring_req {
    int setMonitoringData_count;
    ocpp201_monitor_data_t setMonitoringData[4];
} ocpp201_set_variable_monitoring_req_t;
typedef struct ocpp201_set_variable_monitoring_conf {
    int setMonitoringResult_count;
    ocpp201_monitor_result_t setMonitoringResult[4];
} ocpp201_set_variable_monitoring_conf_t;
cJSON *ocpp201_set_variable_monitoring_req_to_json(const ocpp201_set_variable_monitoring_req_t *in);
ocpp_err_t ocpp201_set_variable_monitoring_req_from_json(const cJSON *obj, ocpp201_set_variable_monitoring_req_t *out);
ocpp_err_t ocpp201_set_variable_monitoring_req_encode(const ocpp201_set_variable_monitoring_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_set_variable_monitoring_req_decode(const char *json, ocpp201_set_variable_monitoring_req_t *out);
void ocpp201_set_variable_monitoring_req_example(ocpp201_set_variable_monitoring_req_t *out);
cJSON *ocpp201_set_variable_monitoring_conf_to_json(const ocpp201_set_variable_monitoring_conf_t *in);
ocpp_err_t ocpp201_set_variable_monitoring_conf_from_json(const cJSON *obj, ocpp201_set_variable_monitoring_conf_t *out);
ocpp_err_t ocpp201_set_variable_monitoring_conf_encode(const ocpp201_set_variable_monitoring_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_set_variable_monitoring_conf_decode(const char *json, ocpp201_set_variable_monitoring_conf_t *out);
void ocpp201_set_variable_monitoring_conf_example(ocpp201_set_variable_monitoring_conf_t *out);
#ifdef __cplusplus
}
#endif
#endif

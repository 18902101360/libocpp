#ifndef OCPP201_CLEAR_VARIABLE_MONITORING_H
#define OCPP201_CLEAR_VARIABLE_MONITORING_H
#include "ocpp201_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"
#ifdef __cplusplus
extern "C" {
#endif
#define OCPP201_CLEAR_VARIABLE_MONITORING_ACTION "ClearVariableMonitoring"
typedef struct ocpp201_clear_variable_monitoring_req {
    int unused;
} ocpp201_clear_variable_monitoring_req_t;
typedef struct ocpp201_clear_variable_monitoring_conf {
    int clearMonitoringResult_count;
    ocpp201_clear_mon_result_t clearMonitoringResult[4];
} ocpp201_clear_variable_monitoring_conf_t;
cJSON *ocpp201_clear_variable_monitoring_req_to_json(const ocpp201_clear_variable_monitoring_req_t *in);
ocpp_err_t ocpp201_clear_variable_monitoring_req_from_json(const cJSON *obj, ocpp201_clear_variable_monitoring_req_t *out);
ocpp_err_t ocpp201_clear_variable_monitoring_req_encode(const ocpp201_clear_variable_monitoring_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_clear_variable_monitoring_req_decode(const char *json, ocpp201_clear_variable_monitoring_req_t *out);
void ocpp201_clear_variable_monitoring_req_example(ocpp201_clear_variable_monitoring_req_t *out);
cJSON *ocpp201_clear_variable_monitoring_conf_to_json(const ocpp201_clear_variable_monitoring_conf_t *in);
ocpp_err_t ocpp201_clear_variable_monitoring_conf_from_json(const cJSON *obj, ocpp201_clear_variable_monitoring_conf_t *out);
ocpp_err_t ocpp201_clear_variable_monitoring_conf_encode(const ocpp201_clear_variable_monitoring_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_clear_variable_monitoring_conf_decode(const char *json, ocpp201_clear_variable_monitoring_conf_t *out);
void ocpp201_clear_variable_monitoring_conf_example(ocpp201_clear_variable_monitoring_conf_t *out);
#ifdef __cplusplus
}
#endif
#endif

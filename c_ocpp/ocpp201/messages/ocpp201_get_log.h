#ifndef OCPP201_GET_LOG_H
#define OCPP201_GET_LOG_H
#include "ocpp201_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"
#ifdef __cplusplus
extern "C" {
#endif
#define OCPP201_GET_LOG_ACTION "GetLog"
typedef struct ocpp201_get_log_req {
    char logType[21];
    int requestId;
    ocpp201_log_params_t log;
} ocpp201_get_log_req_t;
typedef struct ocpp201_get_log_conf {
    char status[17];
} ocpp201_get_log_conf_t;
cJSON *ocpp201_get_log_req_to_json(const ocpp201_get_log_req_t *in);
ocpp_err_t ocpp201_get_log_req_from_json(const cJSON *obj, ocpp201_get_log_req_t *out);
ocpp_err_t ocpp201_get_log_req_encode(const ocpp201_get_log_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_get_log_req_decode(const char *json, ocpp201_get_log_req_t *out);
void ocpp201_get_log_req_example(ocpp201_get_log_req_t *out);
cJSON *ocpp201_get_log_conf_to_json(const ocpp201_get_log_conf_t *in);
ocpp_err_t ocpp201_get_log_conf_from_json(const cJSON *obj, ocpp201_get_log_conf_t *out);
ocpp_err_t ocpp201_get_log_conf_encode(const ocpp201_get_log_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_get_log_conf_decode(const char *json, ocpp201_get_log_conf_t *out);
void ocpp201_get_log_conf_example(ocpp201_get_log_conf_t *out);
#ifdef __cplusplus
}
#endif
#endif

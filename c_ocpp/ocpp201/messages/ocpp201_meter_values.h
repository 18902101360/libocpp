#ifndef OCPP201_METER_VALUES_H
#define OCPP201_METER_VALUES_H
#include "ocpp201_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"
#ifdef __cplusplus
extern "C" {
#endif
#define OCPP201_METER_VALUES_ACTION "MeterValues"
typedef struct ocpp201_meter_values_req {
    int evseId;
    int meterValue_count;
    ocpp201_meter_value_t meterValue[4];
} ocpp201_meter_values_req_t;
typedef struct ocpp201_meter_values_conf {
    int unused;
} ocpp201_meter_values_conf_t;
cJSON *ocpp201_meter_values_req_to_json(const ocpp201_meter_values_req_t *in);
ocpp_err_t ocpp201_meter_values_req_from_json(const cJSON *obj, ocpp201_meter_values_req_t *out);
ocpp_err_t ocpp201_meter_values_req_encode(const ocpp201_meter_values_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_meter_values_req_decode(const char *json, ocpp201_meter_values_req_t *out);
void ocpp201_meter_values_req_example(ocpp201_meter_values_req_t *out);
cJSON *ocpp201_meter_values_conf_to_json(const ocpp201_meter_values_conf_t *in);
ocpp_err_t ocpp201_meter_values_conf_from_json(const cJSON *obj, ocpp201_meter_values_conf_t *out);
ocpp_err_t ocpp201_meter_values_conf_encode(const ocpp201_meter_values_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_meter_values_conf_decode(const char *json, ocpp201_meter_values_conf_t *out);
void ocpp201_meter_values_conf_example(ocpp201_meter_values_conf_t *out);
#ifdef __cplusplus
}
#endif
#endif

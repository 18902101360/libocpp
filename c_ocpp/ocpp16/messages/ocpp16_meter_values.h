/* Generated OCPP message: MeterValues */
#ifndef OCPP16_METER_VALUES_H
#define OCPP16_METER_VALUES_H

#include "ocpp16_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP16_METER_VALUES_ACTION "MeterValues"

typedef struct ocpp16_meter_values_req {
    int connectorId;
    int meterValue_count;
    ocpp16_meter_value_t meterValue[4];
    int has_transactionId;
    int transactionId;
} ocpp16_meter_values_req_t;

typedef struct ocpp16_meter_values_conf {
    int unused;
} ocpp16_meter_values_conf_t;

cJSON *ocpp16_meter_values_req_to_json(const ocpp16_meter_values_req_t *in);
ocpp_err_t ocpp16_meter_values_req_from_json(const cJSON *obj, ocpp16_meter_values_req_t *out);
ocpp_err_t ocpp16_meter_values_req_encode(const ocpp16_meter_values_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_meter_values_req_decode(const char *json, ocpp16_meter_values_req_t *out);
void ocpp16_meter_values_req_example(ocpp16_meter_values_req_t *out);

cJSON *ocpp16_meter_values_conf_to_json(const ocpp16_meter_values_conf_t *in);
ocpp_err_t ocpp16_meter_values_conf_from_json(const cJSON *obj, ocpp16_meter_values_conf_t *out);
ocpp_err_t ocpp16_meter_values_conf_encode(const ocpp16_meter_values_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_meter_values_conf_decode(const char *json, ocpp16_meter_values_conf_t *out);
void ocpp16_meter_values_conf_example(ocpp16_meter_values_conf_t *out);

#ifdef __cplusplus
}
#endif

#endif

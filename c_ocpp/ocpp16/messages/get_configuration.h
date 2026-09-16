/* Generated OCPP message: GetConfiguration */
#ifndef OCPP16_GET_CONFIGURATION_H
#define OCPP16_GET_CONFIGURATION_H

#include "ocpp16_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP16_GET_CONFIGURATION_ACTION "GetConfiguration"

typedef struct ocpp16_get_configuration_req {
    int unused;
} ocpp16_get_configuration_req_t;

typedef struct ocpp16_get_configuration_conf {
    int configurationKey_count;
    ocpp16_key_value_t configurationKey[8];
} ocpp16_get_configuration_conf_t;

cJSON *ocpp16_get_configuration_req_to_json(const ocpp16_get_configuration_req_t *in);
ocpp_err_t ocpp16_get_configuration_req_from_json(const cJSON *obj, ocpp16_get_configuration_req_t *out);
ocpp_err_t ocpp16_get_configuration_req_encode(const ocpp16_get_configuration_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_get_configuration_req_decode(const char *json, ocpp16_get_configuration_req_t *out);
void ocpp16_get_configuration_req_example(ocpp16_get_configuration_req_t *out);

cJSON *ocpp16_get_configuration_conf_to_json(const ocpp16_get_configuration_conf_t *in);
ocpp_err_t ocpp16_get_configuration_conf_from_json(const cJSON *obj, ocpp16_get_configuration_conf_t *out);
ocpp_err_t ocpp16_get_configuration_conf_encode(const ocpp16_get_configuration_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_get_configuration_conf_decode(const char *json, ocpp16_get_configuration_conf_t *out);
void ocpp16_get_configuration_conf_example(ocpp16_get_configuration_conf_t *out);

#ifdef __cplusplus
}
#endif

#endif

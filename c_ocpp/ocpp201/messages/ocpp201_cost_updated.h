#ifndef OCPP201_COST_UPDATED_H
#define OCPP201_COST_UPDATED_H
#include "ocpp201_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"
#ifdef __cplusplus
extern "C" {
#endif
#define OCPP201_COST_UPDATED_ACTION "CostUpdated"
typedef struct ocpp201_cost_updated_req {
    double totalCost;
    char transactionId[37];
} ocpp201_cost_updated_req_t;
typedef struct ocpp201_cost_updated_conf {
    int unused;
} ocpp201_cost_updated_conf_t;
cJSON *ocpp201_cost_updated_req_to_json(const ocpp201_cost_updated_req_t *in);
ocpp_err_t ocpp201_cost_updated_req_from_json(const cJSON *obj, ocpp201_cost_updated_req_t *out);
ocpp_err_t ocpp201_cost_updated_req_encode(const ocpp201_cost_updated_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_cost_updated_req_decode(const char *json, ocpp201_cost_updated_req_t *out);
void ocpp201_cost_updated_req_example(ocpp201_cost_updated_req_t *out);
cJSON *ocpp201_cost_updated_conf_to_json(const ocpp201_cost_updated_conf_t *in);
ocpp_err_t ocpp201_cost_updated_conf_from_json(const cJSON *obj, ocpp201_cost_updated_conf_t *out);
ocpp_err_t ocpp201_cost_updated_conf_encode(const ocpp201_cost_updated_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_cost_updated_conf_decode(const char *json, ocpp201_cost_updated_conf_t *out);
void ocpp201_cost_updated_conf_example(ocpp201_cost_updated_conf_t *out);
#ifdef __cplusplus
}
#endif
#endif

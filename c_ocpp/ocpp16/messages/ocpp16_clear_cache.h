/* Generated OCPP message: ClearCache */
#ifndef OCPP16_CLEAR_CACHE_H
#define OCPP16_CLEAR_CACHE_H

#include "ocpp16_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP16_CLEAR_CACHE_ACTION "ClearCache"

typedef struct ocpp16_clear_cache_req {
    int unused;
} ocpp16_clear_cache_req_t;

typedef struct ocpp16_clear_cache_conf {
    char status[17];
} ocpp16_clear_cache_conf_t;

cJSON *ocpp16_clear_cache_req_to_json(const ocpp16_clear_cache_req_t *in);
ocpp_err_t ocpp16_clear_cache_req_from_json(const cJSON *obj, ocpp16_clear_cache_req_t *out);
ocpp_err_t ocpp16_clear_cache_req_encode(const ocpp16_clear_cache_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_clear_cache_req_decode(const char *json, ocpp16_clear_cache_req_t *out);
void ocpp16_clear_cache_req_example(ocpp16_clear_cache_req_t *out);

cJSON *ocpp16_clear_cache_conf_to_json(const ocpp16_clear_cache_conf_t *in);
ocpp_err_t ocpp16_clear_cache_conf_from_json(const cJSON *obj, ocpp16_clear_cache_conf_t *out);
ocpp_err_t ocpp16_clear_cache_conf_encode(const ocpp16_clear_cache_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_clear_cache_conf_decode(const char *json, ocpp16_clear_cache_conf_t *out);
void ocpp16_clear_cache_conf_example(ocpp16_clear_cache_conf_t *out);

#ifdef __cplusplus
}
#endif

#endif

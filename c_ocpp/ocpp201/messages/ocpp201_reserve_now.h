#ifndef OCPP201_RESERVE_NOW_H
#define OCPP201_RESERVE_NOW_H
#include "ocpp201_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"
#ifdef __cplusplus
extern "C" {
#endif
#define OCPP201_RESERVE_NOW_ACTION "ReserveNow"
typedef struct ocpp201_reserve_now_req {
    int id;
    char expiryDateTime[33];
    ocpp201_id_token_t idToken;
} ocpp201_reserve_now_req_t;
typedef struct ocpp201_reserve_now_conf {
    char status[17];
} ocpp201_reserve_now_conf_t;
cJSON *ocpp201_reserve_now_req_to_json(const ocpp201_reserve_now_req_t *in);
ocpp_err_t ocpp201_reserve_now_req_from_json(const cJSON *obj, ocpp201_reserve_now_req_t *out);
ocpp_err_t ocpp201_reserve_now_req_encode(const ocpp201_reserve_now_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_reserve_now_req_decode(const char *json, ocpp201_reserve_now_req_t *out);
void ocpp201_reserve_now_req_example(ocpp201_reserve_now_req_t *out);
cJSON *ocpp201_reserve_now_conf_to_json(const ocpp201_reserve_now_conf_t *in);
ocpp_err_t ocpp201_reserve_now_conf_from_json(const cJSON *obj, ocpp201_reserve_now_conf_t *out);
ocpp_err_t ocpp201_reserve_now_conf_encode(const ocpp201_reserve_now_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_reserve_now_conf_decode(const char *json, ocpp201_reserve_now_conf_t *out);
void ocpp201_reserve_now_conf_example(ocpp201_reserve_now_conf_t *out);
#ifdef __cplusplus
}
#endif
#endif

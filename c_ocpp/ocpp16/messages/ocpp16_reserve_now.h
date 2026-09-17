/* Generated OCPP message: ReserveNow */
#ifndef OCPP16_RESERVE_NOW_H
#define OCPP16_RESERVE_NOW_H

#include "ocpp16_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP16_RESERVE_NOW_ACTION "ReserveNow"

typedef struct ocpp16_reserve_now_req {
    int connectorId;
    char expiryDate[33];
    char idTag[22];
    int reservationId;
} ocpp16_reserve_now_req_t;

typedef struct ocpp16_reserve_now_conf {
    char status[17];
} ocpp16_reserve_now_conf_t;

cJSON *ocpp16_reserve_now_req_to_json(const ocpp16_reserve_now_req_t *in);
ocpp_err_t ocpp16_reserve_now_req_from_json(const cJSON *obj, ocpp16_reserve_now_req_t *out);
ocpp_err_t ocpp16_reserve_now_req_encode(const ocpp16_reserve_now_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_reserve_now_req_decode(const char *json, ocpp16_reserve_now_req_t *out);
void ocpp16_reserve_now_req_example(ocpp16_reserve_now_req_t *out);

cJSON *ocpp16_reserve_now_conf_to_json(const ocpp16_reserve_now_conf_t *in);
ocpp_err_t ocpp16_reserve_now_conf_from_json(const cJSON *obj, ocpp16_reserve_now_conf_t *out);
ocpp_err_t ocpp16_reserve_now_conf_encode(const ocpp16_reserve_now_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_reserve_now_conf_decode(const char *json, ocpp16_reserve_now_conf_t *out);
void ocpp16_reserve_now_conf_example(ocpp16_reserve_now_conf_t *out);

#ifdef __cplusplus
}
#endif

#endif

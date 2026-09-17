/* Generated OCPP message: SendLocalList */
#ifndef OCPP16_SEND_LOCAL_LIST_H
#define OCPP16_SEND_LOCAL_LIST_H

#include "ocpp16_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP16_SEND_LOCAL_LIST_ACTION "SendLocalList"

typedef struct ocpp16_send_local_list_req {
    int listVersion;
    char updateType[17];
    int localAuthorizationList_count;
    ocpp16_auth_data_t localAuthorizationList[8];
} ocpp16_send_local_list_req_t;

typedef struct ocpp16_send_local_list_conf {
    char status[25];
} ocpp16_send_local_list_conf_t;

cJSON *ocpp16_send_local_list_req_to_json(const ocpp16_send_local_list_req_t *in);
ocpp_err_t ocpp16_send_local_list_req_from_json(const cJSON *obj, ocpp16_send_local_list_req_t *out);
ocpp_err_t ocpp16_send_local_list_req_encode(const ocpp16_send_local_list_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_send_local_list_req_decode(const char *json, ocpp16_send_local_list_req_t *out);
void ocpp16_send_local_list_req_example(ocpp16_send_local_list_req_t *out);

cJSON *ocpp16_send_local_list_conf_to_json(const ocpp16_send_local_list_conf_t *in);
ocpp_err_t ocpp16_send_local_list_conf_from_json(const cJSON *obj, ocpp16_send_local_list_conf_t *out);
ocpp_err_t ocpp16_send_local_list_conf_encode(const ocpp16_send_local_list_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_send_local_list_conf_decode(const char *json, ocpp16_send_local_list_conf_t *out);
void ocpp16_send_local_list_conf_example(ocpp16_send_local_list_conf_t *out);

#ifdef __cplusplus
}
#endif

#endif

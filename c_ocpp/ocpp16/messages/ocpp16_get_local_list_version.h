/* Generated OCPP message: GetLocalListVersion */
#ifndef OCPP16_GET_LOCAL_LIST_VERSION_H
#define OCPP16_GET_LOCAL_LIST_VERSION_H

#include "ocpp16_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP16_GET_LOCAL_LIST_VERSION_ACTION "GetLocalListVersion"

typedef struct ocpp16_get_local_list_version_req {
    int unused;
} ocpp16_get_local_list_version_req_t;

typedef struct ocpp16_get_local_list_version_conf {
    int listVersion;
} ocpp16_get_local_list_version_conf_t;

cJSON *ocpp16_get_local_list_version_req_to_json(const ocpp16_get_local_list_version_req_t *in);
ocpp_err_t ocpp16_get_local_list_version_req_from_json(const cJSON *obj, ocpp16_get_local_list_version_req_t *out);
ocpp_err_t ocpp16_get_local_list_version_req_encode(const ocpp16_get_local_list_version_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_get_local_list_version_req_decode(const char *json, ocpp16_get_local_list_version_req_t *out);
void ocpp16_get_local_list_version_req_example(ocpp16_get_local_list_version_req_t *out);

cJSON *ocpp16_get_local_list_version_conf_to_json(const ocpp16_get_local_list_version_conf_t *in);
ocpp_err_t ocpp16_get_local_list_version_conf_from_json(const cJSON *obj, ocpp16_get_local_list_version_conf_t *out);
ocpp_err_t ocpp16_get_local_list_version_conf_encode(const ocpp16_get_local_list_version_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_get_local_list_version_conf_decode(const char *json, ocpp16_get_local_list_version_conf_t *out);
void ocpp16_get_local_list_version_conf_example(ocpp16_get_local_list_version_conf_t *out);

#ifdef __cplusplus
}
#endif

#endif

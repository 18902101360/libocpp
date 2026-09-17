/* Generated OCPP message: Authorize */
#ifndef OCPP16_AUTHORIZE_H
#define OCPP16_AUTHORIZE_H

#include "ocpp16_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP16_AUTHORIZE_ACTION "Authorize"

typedef struct ocpp16_authorize_req {
    char idTag[22];
} ocpp16_authorize_req_t;

typedef struct ocpp16_authorize_conf {
    ocpp16_id_tag_info_t idTagInfo;
} ocpp16_authorize_conf_t;

cJSON *ocpp16_authorize_req_to_json(const ocpp16_authorize_req_t *in);
ocpp_err_t ocpp16_authorize_req_from_json(const cJSON *obj, ocpp16_authorize_req_t *out);
ocpp_err_t ocpp16_authorize_req_encode(const ocpp16_authorize_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_authorize_req_decode(const char *json, ocpp16_authorize_req_t *out);
void ocpp16_authorize_req_example(ocpp16_authorize_req_t *out);

cJSON *ocpp16_authorize_conf_to_json(const ocpp16_authorize_conf_t *in);
ocpp_err_t ocpp16_authorize_conf_from_json(const cJSON *obj, ocpp16_authorize_conf_t *out);
ocpp_err_t ocpp16_authorize_conf_encode(const ocpp16_authorize_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_authorize_conf_decode(const char *json, ocpp16_authorize_conf_t *out);
void ocpp16_authorize_conf_example(ocpp16_authorize_conf_t *out);

#ifdef __cplusplus
}
#endif

#endif

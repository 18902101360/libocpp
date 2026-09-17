/* Generated OCPP message: SignCertificate */
#ifndef OCPP16_SIGN_CERTIFICATE_H
#define OCPP16_SIGN_CERTIFICATE_H

#include "ocpp16_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP16_SIGN_CERTIFICATE_ACTION "SignCertificate"

typedef struct ocpp16_sign_certificate_req {
    char csr[801];
} ocpp16_sign_certificate_req_t;

typedef struct ocpp16_sign_certificate_conf {
    char status[17];
} ocpp16_sign_certificate_conf_t;

cJSON *ocpp16_sign_certificate_req_to_json(const ocpp16_sign_certificate_req_t *in);
ocpp_err_t ocpp16_sign_certificate_req_from_json(const cJSON *obj, ocpp16_sign_certificate_req_t *out);
ocpp_err_t ocpp16_sign_certificate_req_encode(const ocpp16_sign_certificate_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_sign_certificate_req_decode(const char *json, ocpp16_sign_certificate_req_t *out);
void ocpp16_sign_certificate_req_example(ocpp16_sign_certificate_req_t *out);

cJSON *ocpp16_sign_certificate_conf_to_json(const ocpp16_sign_certificate_conf_t *in);
ocpp_err_t ocpp16_sign_certificate_conf_from_json(const cJSON *obj, ocpp16_sign_certificate_conf_t *out);
ocpp_err_t ocpp16_sign_certificate_conf_encode(const ocpp16_sign_certificate_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_sign_certificate_conf_decode(const char *json, ocpp16_sign_certificate_conf_t *out);
void ocpp16_sign_certificate_conf_example(ocpp16_sign_certificate_conf_t *out);

#ifdef __cplusplus
}
#endif

#endif

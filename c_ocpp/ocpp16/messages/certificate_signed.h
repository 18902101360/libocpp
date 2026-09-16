/* Generated OCPP message: CertificateSigned */
#ifndef OCPP16_CERTIFICATE_SIGNED_H
#define OCPP16_CERTIFICATE_SIGNED_H

#include "ocpp16_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP16_CERTIFICATE_SIGNED_ACTION "CertificateSigned"

typedef struct ocpp16_certificate_signed_req {
    char certificateChain[801];
} ocpp16_certificate_signed_req_t;

typedef struct ocpp16_certificate_signed_conf {
    char status[17];
} ocpp16_certificate_signed_conf_t;

cJSON *ocpp16_certificate_signed_req_to_json(const ocpp16_certificate_signed_req_t *in);
ocpp_err_t ocpp16_certificate_signed_req_from_json(const cJSON *obj, ocpp16_certificate_signed_req_t *out);
ocpp_err_t ocpp16_certificate_signed_req_encode(const ocpp16_certificate_signed_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_certificate_signed_req_decode(const char *json, ocpp16_certificate_signed_req_t *out);
void ocpp16_certificate_signed_req_example(ocpp16_certificate_signed_req_t *out);

cJSON *ocpp16_certificate_signed_conf_to_json(const ocpp16_certificate_signed_conf_t *in);
ocpp_err_t ocpp16_certificate_signed_conf_from_json(const cJSON *obj, ocpp16_certificate_signed_conf_t *out);
ocpp_err_t ocpp16_certificate_signed_conf_encode(const ocpp16_certificate_signed_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_certificate_signed_conf_decode(const char *json, ocpp16_certificate_signed_conf_t *out);
void ocpp16_certificate_signed_conf_example(ocpp16_certificate_signed_conf_t *out);

#ifdef __cplusplus
}
#endif

#endif

#ifndef OCPP201_CERTIFICATE_SIGNED_H
#define OCPP201_CERTIFICATE_SIGNED_H
#include "ocpp201_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"
#ifdef __cplusplus
extern "C" {
#endif
#define OCPP201_CERTIFICATE_SIGNED_ACTION "CertificateSigned"
typedef struct ocpp201_certificate_signed_req {
    char certificateChain[801];
} ocpp201_certificate_signed_req_t;
typedef struct ocpp201_certificate_signed_conf {
    char status[17];
} ocpp201_certificate_signed_conf_t;
cJSON *ocpp201_certificate_signed_req_to_json(const ocpp201_certificate_signed_req_t *in);
ocpp_err_t ocpp201_certificate_signed_req_from_json(const cJSON *obj, ocpp201_certificate_signed_req_t *out);
ocpp_err_t ocpp201_certificate_signed_req_encode(const ocpp201_certificate_signed_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_certificate_signed_req_decode(const char *json, ocpp201_certificate_signed_req_t *out);
void ocpp201_certificate_signed_req_example(ocpp201_certificate_signed_req_t *out);
cJSON *ocpp201_certificate_signed_conf_to_json(const ocpp201_certificate_signed_conf_t *in);
ocpp_err_t ocpp201_certificate_signed_conf_from_json(const cJSON *obj, ocpp201_certificate_signed_conf_t *out);
ocpp_err_t ocpp201_certificate_signed_conf_encode(const ocpp201_certificate_signed_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_certificate_signed_conf_decode(const char *json, ocpp201_certificate_signed_conf_t *out);
void ocpp201_certificate_signed_conf_example(ocpp201_certificate_signed_conf_t *out);
#ifdef __cplusplus
}
#endif
#endif

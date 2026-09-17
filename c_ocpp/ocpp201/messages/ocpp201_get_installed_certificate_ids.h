#ifndef OCPP201_GET_INSTALLED_CERTIFICATE_IDS_H
#define OCPP201_GET_INSTALLED_CERTIFICATE_IDS_H
#include "ocpp201_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"
#ifdef __cplusplus
extern "C" {
#endif
#define OCPP201_GET_INSTALLED_CERTIFICATE_IDS_ACTION "GetInstalledCertificateIds"
typedef struct ocpp201_get_installed_certificate_ids_req {
    int unused;
} ocpp201_get_installed_certificate_ids_req_t;
typedef struct ocpp201_get_installed_certificate_ids_conf {
    char status[17];
} ocpp201_get_installed_certificate_ids_conf_t;
cJSON *ocpp201_get_installed_certificate_ids_req_to_json(const ocpp201_get_installed_certificate_ids_req_t *in);
ocpp_err_t ocpp201_get_installed_certificate_ids_req_from_json(const cJSON *obj, ocpp201_get_installed_certificate_ids_req_t *out);
ocpp_err_t ocpp201_get_installed_certificate_ids_req_encode(const ocpp201_get_installed_certificate_ids_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_get_installed_certificate_ids_req_decode(const char *json, ocpp201_get_installed_certificate_ids_req_t *out);
void ocpp201_get_installed_certificate_ids_req_example(ocpp201_get_installed_certificate_ids_req_t *out);
cJSON *ocpp201_get_installed_certificate_ids_conf_to_json(const ocpp201_get_installed_certificate_ids_conf_t *in);
ocpp_err_t ocpp201_get_installed_certificate_ids_conf_from_json(const cJSON *obj, ocpp201_get_installed_certificate_ids_conf_t *out);
ocpp_err_t ocpp201_get_installed_certificate_ids_conf_encode(const ocpp201_get_installed_certificate_ids_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_get_installed_certificate_ids_conf_decode(const char *json, ocpp201_get_installed_certificate_ids_conf_t *out);
void ocpp201_get_installed_certificate_ids_conf_example(ocpp201_get_installed_certificate_ids_conf_t *out);
#ifdef __cplusplus
}
#endif
#endif

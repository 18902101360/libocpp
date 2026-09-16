/* SPDX-License-Identifier: Apache-2.0 */
#ifndef OCPP_ERR_H
#define OCPP_ERR_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum ocpp_err {
    OCPP_OK = 0,
    OCPP_ERR_ARG = -1,
    OCPP_ERR_NOMEM = -2,
    OCPP_ERR_PARSE = -3,
    OCPP_ERR_STATE = -4,
    OCPP_ERR_IO = -5,
    OCPP_ERR_OVERFLOW = -6,
    OCPP_ERR_NOTFOUND = -7,
    OCPP_ERR_PROTOCOL = -8
} ocpp_err_t;

#ifdef __cplusplus
}
#endif

#endif

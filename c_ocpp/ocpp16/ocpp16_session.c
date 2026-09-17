#include "ocpp16_session.h"
#include "ocpp_port.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* BootNotification.conf 之后按 interval 周期发 Heartbeat。 */
static void heartbeat_timer(int id, void *ctx) {
    ocpp16_session_t *s = (ocpp16_session_t *)ctx;
    (void)id;
    ocpp16_heartbeat_req_t req;
    ocpp16_heartbeat_req_example(&req);
    ocpp16_session_send_heartbeat(s, &req);
}

void ocpp16_session_bind(ocpp16_session_t *s, const ocpp_link_t *link) {
    if (link) {
        s->link = *link;
    }
}

void ocpp16_session_init(ocpp16_session_t *s, const ocpp16_handlers_t *h, const ocpp_link_t *link) {
    memset(s, 0, sizeof(*s));
    s->seq = 1;
    s->heartbeat_interval_s = 300;
    s->link.accept_control = 1;
    s->link.heartbeat_timer_id = OCPP_PORT_TIMER_HEARTBEAT;
    if (h) s->handlers = *h;
    ocpp16_session_bind(s, link);
}

static int session_tx(ocpp16_session_t *s) {
    return ocpp_link_send(&s->link, s->frame, strlen(s->frame));
}

/* 记录发出的 CALL，等 CALLRESULT 用 uniqueId 找回 action。 */
static int pending_add(ocpp16_session_t *s, const char *uid, const char *action) {
    for (int i = 0; i < OCPP16_PENDING_MAX; i++) if (!s->pending[i].used) {
        s->pending[i].used = 1;
        ocpp_str_copy(s->pending[i].uid, sizeof(s->pending[i].uid), uid);
        ocpp_str_copy(s->pending[i].action, sizeof(s->pending[i].action), action);
        return 0;
    }
    return -1;
}

ocpp_err_t ocpp16_session_call(ocpp16_session_t *s, const char *action, const char *payload_json) {
    char uid[16];
    snprintf(uid, sizeof(uid), "%u", s->seq++);
    ocpp_err_t rc = ocpp_rpc_pack_call(uid, action, payload_json, s->frame, sizeof(s->frame));
    if (rc != OCPP_OK) return rc;
    if (pending_add(s, uid, action) != 0) return OCPP_ERR_OVERFLOW;
    if (session_tx(s) != 0) return OCPP_ERR_IO;
    return OCPP_OK;
}

ocpp_err_t ocpp16_session_send_authorize(ocpp16_session_t *s, const ocpp16_authorize_req_t *req) {
    ocpp_err_t rc = ocpp16_authorize_req_encode(req, s->payload, sizeof(s->payload));
    if (rc != OCPP_OK) return rc;
    return ocpp16_session_call(s, "Authorize", s->payload);
}

ocpp_err_t ocpp16_session_send_boot_notification(ocpp16_session_t *s, const ocpp16_boot_notification_req_t *req) {
    ocpp_err_t rc = ocpp16_boot_notification_req_encode(req, s->payload, sizeof(s->payload));
    if (rc != OCPP_OK) return rc;
    return ocpp16_session_call(s, "BootNotification", s->payload);
}

ocpp_err_t ocpp16_session_send_data_transfer(ocpp16_session_t *s, const ocpp16_data_transfer_req_t *req) {
    ocpp_err_t rc = ocpp16_data_transfer_req_encode(req, s->payload, sizeof(s->payload));
    if (rc != OCPP_OK) return rc;
    return ocpp16_session_call(s, "DataTransfer", s->payload);
}

ocpp_err_t ocpp16_session_send_diagnostics_status_notification(ocpp16_session_t *s, const ocpp16_diagnostics_status_notification_req_t *req) {
    ocpp_err_t rc = ocpp16_diagnostics_status_notification_req_encode(req, s->payload, sizeof(s->payload));
    if (rc != OCPP_OK) return rc;
    return ocpp16_session_call(s, "DiagnosticsStatusNotification", s->payload);
}

ocpp_err_t ocpp16_session_send_firmware_status_notification(ocpp16_session_t *s, const ocpp16_firmware_status_notification_req_t *req) {
    ocpp_err_t rc = ocpp16_firmware_status_notification_req_encode(req, s->payload, sizeof(s->payload));
    if (rc != OCPP_OK) return rc;
    return ocpp16_session_call(s, "FirmwareStatusNotification", s->payload);
}

ocpp_err_t ocpp16_session_send_heartbeat(ocpp16_session_t *s, const ocpp16_heartbeat_req_t *req) {
    ocpp_err_t rc = ocpp16_heartbeat_req_encode(req, s->payload, sizeof(s->payload));
    if (rc != OCPP_OK) return rc;
    return ocpp16_session_call(s, "Heartbeat", s->payload);
}

ocpp_err_t ocpp16_session_send_meter_values(ocpp16_session_t *s, const ocpp16_meter_values_req_t *req) {
    ocpp_err_t rc = ocpp16_meter_values_req_encode(req, s->payload, sizeof(s->payload));
    if (rc != OCPP_OK) return rc;
    return ocpp16_session_call(s, "MeterValues", s->payload);
}

ocpp_err_t ocpp16_session_send_start_transaction(ocpp16_session_t *s, const ocpp16_start_transaction_req_t *req) {
    ocpp_err_t rc = ocpp16_start_transaction_req_encode(req, s->payload, sizeof(s->payload));
    if (rc != OCPP_OK) return rc;
    return ocpp16_session_call(s, "StartTransaction", s->payload);
}

ocpp_err_t ocpp16_session_send_status_notification(ocpp16_session_t *s, const ocpp16_status_notification_req_t *req) {
    ocpp_err_t rc = ocpp16_status_notification_req_encode(req, s->payload, sizeof(s->payload));
    if (rc != OCPP_OK) return rc;
    return ocpp16_session_call(s, "StatusNotification", s->payload);
}

ocpp_err_t ocpp16_session_send_stop_transaction(ocpp16_session_t *s, const ocpp16_stop_transaction_req_t *req) {
    ocpp_err_t rc = ocpp16_stop_transaction_req_encode(req, s->payload, sizeof(s->payload));
    if (rc != OCPP_OK) return rc;
    return ocpp16_session_call(s, "StopTransaction", s->payload);
}

ocpp_err_t ocpp16_session_send_log_status_notification(ocpp16_session_t *s, const ocpp16_log_status_notification_req_t *req) {
    ocpp_err_t rc = ocpp16_log_status_notification_req_encode(req, s->payload, sizeof(s->payload));
    if (rc != OCPP_OK) return rc;
    return ocpp16_session_call(s, "LogStatusNotification", s->payload);
}

ocpp_err_t ocpp16_session_send_security_event_notification(ocpp16_session_t *s, const ocpp16_security_event_notification_req_t *req) {
    ocpp_err_t rc = ocpp16_security_event_notification_req_encode(req, s->payload, sizeof(s->payload));
    if (rc != OCPP_OK) return rc;
    return ocpp16_session_call(s, "SecurityEventNotification", s->payload);
}

ocpp_err_t ocpp16_session_send_sign_certificate(ocpp16_session_t *s, const ocpp16_sign_certificate_req_t *req) {
    ocpp_err_t rc = ocpp16_sign_certificate_req_encode(req, s->payload, sizeof(s->payload));
    if (rc != OCPP_OK) return rc;
    return ocpp16_session_call(s, "SignCertificate", s->payload);
}

ocpp_err_t ocpp16_session_send_signed_firmware_status_notification(ocpp16_session_t *s, const ocpp16_signed_firmware_status_notification_req_t *req) {
    ocpp_err_t rc = ocpp16_signed_firmware_status_notification_req_encode(req, s->payload, sizeof(s->payload));
    if (rc != OCPP_OK) return rc;
    return ocpp16_session_call(s, "SignedFirmwareStatusNotification", s->payload);
}

/* CSMS→桩 CALL：decode → handler（可改 conf）→ CALLRESULT；handler 非 0 则 InternalError。 */
static ocpp_err_t handle_call(ocpp16_session_t *s, ocpp_rpc_msg_t *msg) {
    /* 遥测链路：不跑 handler，避免第二家 CSMS Reset/启停。 */
    if (!s->link.accept_control && ocpp_action_is_control(msg->action)) {
        ocpp_rpc_pack_callerror(msg->unique_id, "SecurityError", "this link does not accept control", s->frame, sizeof(s->frame));
        session_tx(s);
        return OCPP_OK;
    }
    if (strcmp(msg->action, "DataTransfer") == 0) {
        ocpp16_data_transfer_req_t req; ocpp16_data_transfer_conf_t conf;
        ocpp16_data_transfer_req_from_json(msg->payload, &req);
        ocpp16_data_transfer_conf_example(&conf);
        if (s->handlers.data_transfer_req) {
            if (s->handlers.data_transfer_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_data_transfer_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "CancelReservation") == 0) {
        ocpp16_cancel_reservation_req_t req; ocpp16_cancel_reservation_conf_t conf;
        ocpp16_cancel_reservation_req_from_json(msg->payload, &req);
        ocpp16_cancel_reservation_conf_example(&conf);
        if (s->handlers.cancel_reservation_req) {
            if (s->handlers.cancel_reservation_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_cancel_reservation_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "ChangeAvailability") == 0) {
        ocpp16_change_availability_req_t req; ocpp16_change_availability_conf_t conf;
        ocpp16_change_availability_req_from_json(msg->payload, &req);
        ocpp16_change_availability_conf_example(&conf);
        if (s->handlers.change_availability_req) {
            if (s->handlers.change_availability_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_change_availability_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "ChangeConfiguration") == 0) {
        ocpp16_change_configuration_req_t req; ocpp16_change_configuration_conf_t conf;
        ocpp16_change_configuration_req_from_json(msg->payload, &req);
        ocpp16_change_configuration_conf_example(&conf);
        if (s->handlers.change_configuration_req) {
            if (s->handlers.change_configuration_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_change_configuration_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "ClearCache") == 0) {
        ocpp16_clear_cache_req_t req; ocpp16_clear_cache_conf_t conf;
        ocpp16_clear_cache_req_from_json(msg->payload, &req);
        ocpp16_clear_cache_conf_example(&conf);
        if (s->handlers.clear_cache_req) {
            if (s->handlers.clear_cache_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_clear_cache_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "ClearChargingProfile") == 0) {
        ocpp16_clear_charging_profile_req_t req; ocpp16_clear_charging_profile_conf_t conf;
        ocpp16_clear_charging_profile_req_from_json(msg->payload, &req);
        ocpp16_clear_charging_profile_conf_example(&conf);
        if (s->handlers.clear_charging_profile_req) {
            if (s->handlers.clear_charging_profile_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_clear_charging_profile_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "GetCompositeSchedule") == 0) {
        ocpp16_get_composite_schedule_req_t req; ocpp16_get_composite_schedule_conf_t conf;
        ocpp16_get_composite_schedule_req_from_json(msg->payload, &req);
        ocpp16_get_composite_schedule_conf_example(&conf);
        if (s->handlers.get_composite_schedule_req) {
            if (s->handlers.get_composite_schedule_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_get_composite_schedule_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "GetConfiguration") == 0) {
        ocpp16_get_configuration_req_t req; ocpp16_get_configuration_conf_t conf;
        ocpp16_get_configuration_req_from_json(msg->payload, &req);
        ocpp16_get_configuration_conf_example(&conf);
        if (s->handlers.get_configuration_req) {
            if (s->handlers.get_configuration_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_get_configuration_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "GetDiagnostics") == 0) {
        ocpp16_get_diagnostics_req_t req; ocpp16_get_diagnostics_conf_t conf;
        ocpp16_get_diagnostics_req_from_json(msg->payload, &req);
        ocpp16_get_diagnostics_conf_example(&conf);
        if (s->handlers.get_diagnostics_req) {
            if (s->handlers.get_diagnostics_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_get_diagnostics_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "GetLocalListVersion") == 0) {
        ocpp16_get_local_list_version_req_t req; ocpp16_get_local_list_version_conf_t conf;
        ocpp16_get_local_list_version_req_from_json(msg->payload, &req);
        ocpp16_get_local_list_version_conf_example(&conf);
        if (s->handlers.get_local_list_version_req) {
            if (s->handlers.get_local_list_version_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_get_local_list_version_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "RemoteStartTransaction") == 0) {
        ocpp16_remote_start_transaction_req_t req; ocpp16_remote_start_transaction_conf_t conf;
        ocpp16_remote_start_transaction_req_from_json(msg->payload, &req);
        ocpp16_remote_start_transaction_conf_example(&conf);
        if (s->handlers.remote_start_transaction_req) {
            if (s->handlers.remote_start_transaction_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_remote_start_transaction_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "RemoteStopTransaction") == 0) {
        ocpp16_remote_stop_transaction_req_t req; ocpp16_remote_stop_transaction_conf_t conf;
        ocpp16_remote_stop_transaction_req_from_json(msg->payload, &req);
        ocpp16_remote_stop_transaction_conf_example(&conf);
        if (s->handlers.remote_stop_transaction_req) {
            if (s->handlers.remote_stop_transaction_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_remote_stop_transaction_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "ReserveNow") == 0) {
        ocpp16_reserve_now_req_t req; ocpp16_reserve_now_conf_t conf;
        ocpp16_reserve_now_req_from_json(msg->payload, &req);
        ocpp16_reserve_now_conf_example(&conf);
        if (s->handlers.reserve_now_req) {
            if (s->handlers.reserve_now_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_reserve_now_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "Reset") == 0) {
        ocpp16_reset_req_t req; ocpp16_reset_conf_t conf;
        ocpp16_reset_req_from_json(msg->payload, &req);
        ocpp16_reset_conf_example(&conf);
        if (s->handlers.reset_req) {
            if (s->handlers.reset_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_reset_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "SendLocalList") == 0) {
        ocpp16_send_local_list_req_t req; ocpp16_send_local_list_conf_t conf;
        ocpp16_send_local_list_req_from_json(msg->payload, &req);
        ocpp16_send_local_list_conf_example(&conf);
        if (s->handlers.send_local_list_req) {
            if (s->handlers.send_local_list_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_send_local_list_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "SetChargingProfile") == 0) {
        ocpp16_set_charging_profile_req_t req; ocpp16_set_charging_profile_conf_t conf;
        ocpp16_set_charging_profile_req_from_json(msg->payload, &req);
        ocpp16_set_charging_profile_conf_example(&conf);
        if (s->handlers.set_charging_profile_req) {
            if (s->handlers.set_charging_profile_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_set_charging_profile_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "TriggerMessage") == 0) {
        ocpp16_trigger_message_req_t req; ocpp16_trigger_message_conf_t conf;
        ocpp16_trigger_message_req_from_json(msg->payload, &req);
        ocpp16_trigger_message_conf_example(&conf);
        if (s->handlers.trigger_message_req) {
            if (s->handlers.trigger_message_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_trigger_message_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "UnlockConnector") == 0) {
        ocpp16_unlock_connector_req_t req; ocpp16_unlock_connector_conf_t conf;
        ocpp16_unlock_connector_req_from_json(msg->payload, &req);
        ocpp16_unlock_connector_conf_example(&conf);
        if (s->handlers.unlock_connector_req) {
            if (s->handlers.unlock_connector_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_unlock_connector_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "UpdateFirmware") == 0) {
        ocpp16_update_firmware_req_t req; ocpp16_update_firmware_conf_t conf;
        ocpp16_update_firmware_req_from_json(msg->payload, &req);
        ocpp16_update_firmware_conf_example(&conf);
        if (s->handlers.update_firmware_req) {
            if (s->handlers.update_firmware_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_update_firmware_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "CertificateSigned") == 0) {
        ocpp16_certificate_signed_req_t req; ocpp16_certificate_signed_conf_t conf;
        ocpp16_certificate_signed_req_from_json(msg->payload, &req);
        ocpp16_certificate_signed_conf_example(&conf);
        if (s->handlers.certificate_signed_req) {
            if (s->handlers.certificate_signed_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_certificate_signed_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "DeleteCertificate") == 0) {
        ocpp16_delete_certificate_req_t req; ocpp16_delete_certificate_conf_t conf;
        ocpp16_delete_certificate_req_from_json(msg->payload, &req);
        ocpp16_delete_certificate_conf_example(&conf);
        if (s->handlers.delete_certificate_req) {
            if (s->handlers.delete_certificate_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_delete_certificate_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "ExtendedTriggerMessage") == 0) {
        ocpp16_extended_trigger_message_req_t req; ocpp16_extended_trigger_message_conf_t conf;
        ocpp16_extended_trigger_message_req_from_json(msg->payload, &req);
        ocpp16_extended_trigger_message_conf_example(&conf);
        if (s->handlers.extended_trigger_message_req) {
            if (s->handlers.extended_trigger_message_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_extended_trigger_message_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "GetInstalledCertificateIds") == 0) {
        ocpp16_get_installed_certificate_ids_req_t req; ocpp16_get_installed_certificate_ids_conf_t conf;
        ocpp16_get_installed_certificate_ids_req_from_json(msg->payload, &req);
        ocpp16_get_installed_certificate_ids_conf_example(&conf);
        if (s->handlers.get_installed_certificate_ids_req) {
            if (s->handlers.get_installed_certificate_ids_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_get_installed_certificate_ids_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "GetLog") == 0) {
        ocpp16_get_log_req_t req; ocpp16_get_log_conf_t conf;
        ocpp16_get_log_req_from_json(msg->payload, &req);
        ocpp16_get_log_conf_example(&conf);
        if (s->handlers.get_log_req) {
            if (s->handlers.get_log_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_get_log_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "InstallCertificate") == 0) {
        ocpp16_install_certificate_req_t req; ocpp16_install_certificate_conf_t conf;
        ocpp16_install_certificate_req_from_json(msg->payload, &req);
        ocpp16_install_certificate_conf_example(&conf);
        if (s->handlers.install_certificate_req) {
            if (s->handlers.install_certificate_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_install_certificate_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    else if (strcmp(msg->action, "SignedUpdateFirmware") == 0) {
        ocpp16_signed_update_firmware_req_t req; ocpp16_signed_update_firmware_conf_t conf;
        ocpp16_signed_update_firmware_req_from_json(msg->payload, &req);
        ocpp16_signed_update_firmware_conf_example(&conf);
        if (s->handlers.signed_update_firmware_req) {
            if (s->handlers.signed_update_firmware_req(&req, &conf, s->handlers.user) != 0) {
                ocpp_rpc_pack_callerror(msg->unique_id, "InternalError", "handler", s->frame, sizeof(s->frame));
                session_tx(s); return OCPP_OK;
            }
        }
        ocpp16_signed_update_firmware_conf_encode(&conf, s->payload, sizeof(s->payload));
        ocpp_rpc_pack_callresult(msg->unique_id, s->payload, s->frame, sizeof(s->frame));
        if (session_tx(s) != 0) return OCPP_ERR_IO;
        return OCPP_OK;
    }
    ocpp_rpc_pack_callerror(msg->unique_id, "NotImplemented", msg->action, s->frame, sizeof(s->frame));
    session_tx(s);
    return OCPP_OK;
}

/* 桩发出 CALL 的 CALLRESULT：按 pending.action 分发 *_conf 回调。Boot 成功则启心跳。 */
static void handle_result(ocpp16_session_t *s, const char *action, const cJSON *payload) {
    if (strcmp(action, "Authorize") == 0) {
        ocpp16_authorize_conf_t conf; ocpp16_authorize_conf_from_json(payload, &conf);
        if (s->handlers.authorize_conf) s->handlers.authorize_conf(&conf, s->handlers.user);
        return;
    }
    else if (strcmp(action, "BootNotification") == 0) {
        ocpp16_boot_notification_conf_t conf; ocpp16_boot_notification_conf_from_json(payload, &conf);
        s->registered = 1;
        if (conf.interval > 0) s->heartbeat_interval_s = conf.interval;
        if (s->link.heartbeat_timer_id >= 0) {
            ocpp_port_timer_start(s->link.heartbeat_timer_id, (uint32_t)s->heartbeat_interval_s * 1000u, 1, heartbeat_timer, s);
        }
        if (s->handlers.boot_notification_conf) s->handlers.boot_notification_conf(&conf, s->handlers.user);
        return;
    }
    else if (strcmp(action, "DataTransfer") == 0) {
        ocpp16_data_transfer_conf_t conf; ocpp16_data_transfer_conf_from_json(payload, &conf);
        if (s->handlers.data_transfer_conf) s->handlers.data_transfer_conf(&conf, s->handlers.user);
        return;
    }
    else if (strcmp(action, "DiagnosticsStatusNotification") == 0) {
        ocpp16_diagnostics_status_notification_conf_t conf; ocpp16_diagnostics_status_notification_conf_from_json(payload, &conf);
        if (s->handlers.diagnostics_status_notification_conf) s->handlers.diagnostics_status_notification_conf(&conf, s->handlers.user);
        return;
    }
    else if (strcmp(action, "FirmwareStatusNotification") == 0) {
        ocpp16_firmware_status_notification_conf_t conf; ocpp16_firmware_status_notification_conf_from_json(payload, &conf);
        if (s->handlers.firmware_status_notification_conf) s->handlers.firmware_status_notification_conf(&conf, s->handlers.user);
        return;
    }
    else if (strcmp(action, "Heartbeat") == 0) {
        ocpp16_heartbeat_conf_t conf; ocpp16_heartbeat_conf_from_json(payload, &conf);
        if (s->handlers.heartbeat_conf) s->handlers.heartbeat_conf(&conf, s->handlers.user);
        return;
    }
    else if (strcmp(action, "MeterValues") == 0) {
        ocpp16_meter_values_conf_t conf; ocpp16_meter_values_conf_from_json(payload, &conf);
        if (s->handlers.meter_values_conf) s->handlers.meter_values_conf(&conf, s->handlers.user);
        return;
    }
    else if (strcmp(action, "StartTransaction") == 0) {
        ocpp16_start_transaction_conf_t conf; ocpp16_start_transaction_conf_from_json(payload, &conf);
        if (s->handlers.start_transaction_conf) s->handlers.start_transaction_conf(&conf, s->handlers.user);
        return;
    }
    else if (strcmp(action, "StatusNotification") == 0) {
        ocpp16_status_notification_conf_t conf; ocpp16_status_notification_conf_from_json(payload, &conf);
        if (s->handlers.status_notification_conf) s->handlers.status_notification_conf(&conf, s->handlers.user);
        return;
    }
    else if (strcmp(action, "StopTransaction") == 0) {
        ocpp16_stop_transaction_conf_t conf; ocpp16_stop_transaction_conf_from_json(payload, &conf);
        if (s->handlers.stop_transaction_conf) s->handlers.stop_transaction_conf(&conf, s->handlers.user);
        return;
    }
    else if (strcmp(action, "LogStatusNotification") == 0) {
        ocpp16_log_status_notification_conf_t conf; ocpp16_log_status_notification_conf_from_json(payload, &conf);
        if (s->handlers.log_status_notification_conf) s->handlers.log_status_notification_conf(&conf, s->handlers.user);
        return;
    }
    else if (strcmp(action, "SecurityEventNotification") == 0) {
        ocpp16_security_event_notification_conf_t conf; ocpp16_security_event_notification_conf_from_json(payload, &conf);
        if (s->handlers.security_event_notification_conf) s->handlers.security_event_notification_conf(&conf, s->handlers.user);
        return;
    }
    else if (strcmp(action, "SignCertificate") == 0) {
        ocpp16_sign_certificate_conf_t conf; ocpp16_sign_certificate_conf_from_json(payload, &conf);
        if (s->handlers.sign_certificate_conf) s->handlers.sign_certificate_conf(&conf, s->handlers.user);
        return;
    }
    else if (strcmp(action, "SignedFirmwareStatusNotification") == 0) {
        ocpp16_signed_firmware_status_notification_conf_t conf; ocpp16_signed_firmware_status_notification_conf_from_json(payload, &conf);
        if (s->handlers.signed_firmware_status_notification_conf) s->handlers.signed_firmware_status_notification_conf(&conf, s->handlers.user);
        return;
    }
}

ocpp_err_t ocpp16_session_rx(ocpp16_session_t *s, const char *frame, size_t len) {
    ocpp_port_arena_reset(); /* 本帧独占 arena；不要与其它 session 并行 rx */
    ocpp_rpc_msg_t msg;
    ocpp_err_t rc = ocpp_rpc_unpack(frame, len, &msg);
    if (rc != OCPP_OK) return rc;
    if (msg.type == OCPP_RPC_CALL) return handle_call(s, &msg);
    if (msg.type == OCPP_RPC_CALLRESULT) {
        for (int i = 0; i < OCPP16_PENDING_MAX; i++) {
            if (s->pending[i].used && strcmp(s->pending[i].uid, msg.unique_id) == 0) {
                s->pending[i].used = 0;
                handle_result(s, s->pending[i].action, msg.payload);
                return OCPP_OK;
            }
        }
        return OCPP_ERR_NOTFOUND;
    }
    return OCPP_OK;
}

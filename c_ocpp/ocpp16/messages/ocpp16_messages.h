#ifndef OCPP16_MESSAGES_H
#define OCPP16_MESSAGES_H
/* OCPP 1.6 message index */

#include "ocpp16/messages/ocpp16_authorize.h"
#include "ocpp16/messages/ocpp16_boot_notification.h"
#include "ocpp16/messages/ocpp16_data_transfer.h"
#include "ocpp16/messages/ocpp16_diagnostics_status_notification.h"
#include "ocpp16/messages/ocpp16_firmware_status_notification.h"
#include "ocpp16/messages/ocpp16_heartbeat.h"
#include "ocpp16/messages/ocpp16_meter_values.h"
#include "ocpp16/messages/ocpp16_start_transaction.h"
#include "ocpp16/messages/ocpp16_status_notification.h"
#include "ocpp16/messages/ocpp16_stop_transaction.h"
#include "ocpp16/messages/ocpp16_cancel_reservation.h"
#include "ocpp16/messages/ocpp16_change_availability.h"
#include "ocpp16/messages/ocpp16_change_configuration.h"
#include "ocpp16/messages/ocpp16_clear_cache.h"
#include "ocpp16/messages/ocpp16_clear_charging_profile.h"
#include "ocpp16/messages/ocpp16_get_composite_schedule.h"
#include "ocpp16/messages/ocpp16_get_configuration.h"
#include "ocpp16/messages/ocpp16_get_diagnostics.h"
#include "ocpp16/messages/ocpp16_get_local_list_version.h"
#include "ocpp16/messages/ocpp16_remote_start_transaction.h"
#include "ocpp16/messages/ocpp16_remote_stop_transaction.h"
#include "ocpp16/messages/ocpp16_reserve_now.h"
#include "ocpp16/messages/ocpp16_reset.h"
#include "ocpp16/messages/ocpp16_send_local_list.h"
#include "ocpp16/messages/ocpp16_set_charging_profile.h"
#include "ocpp16/messages/ocpp16_trigger_message.h"
#include "ocpp16/messages/ocpp16_unlock_connector.h"
#include "ocpp16/messages/ocpp16_update_firmware.h"
#include "ocpp16/messages/ocpp16_certificate_signed.h"
#include "ocpp16/messages/ocpp16_delete_certificate.h"
#include "ocpp16/messages/ocpp16_extended_trigger_message.h"
#include "ocpp16/messages/ocpp16_get_installed_certificate_ids.h"
#include "ocpp16/messages/ocpp16_get_log.h"
#include "ocpp16/messages/ocpp16_install_certificate.h"
#include "ocpp16/messages/ocpp16_log_status_notification.h"
#include "ocpp16/messages/ocpp16_security_event_notification.h"
#include "ocpp16/messages/ocpp16_sign_certificate.h"
#include "ocpp16/messages/ocpp16_signed_firmware_status_notification.h"
#include "ocpp16/messages/ocpp16_signed_update_firmware.h"

#define OCPP16_MESSAGE_COUNT 39

typedef struct ocpp16_message_info {
    const char *action;
    int from_cp; /* 1 = CP originates CALL */
    int from_csms;
} ocpp16_message_info_t;

const ocpp16_message_info_t *ocpp16_message_table(void);

#endif

#ifndef OCPP16_MESSAGES_H
#define OCPP16_MESSAGES_H
/* OCPP 1.6 message index */

#include "authorize.h"
#include "boot_notification.h"
#include "data_transfer.h"
#include "diagnostics_status_notification.h"
#include "firmware_status_notification.h"
#include "heartbeat.h"
#include "meter_values.h"
#include "start_transaction.h"
#include "status_notification.h"
#include "stop_transaction.h"
#include "cancel_reservation.h"
#include "change_availability.h"
#include "change_configuration.h"
#include "clear_cache.h"
#include "clear_charging_profile.h"
#include "get_composite_schedule.h"
#include "get_configuration.h"
#include "get_diagnostics.h"
#include "get_local_list_version.h"
#include "remote_start_transaction.h"
#include "remote_stop_transaction.h"
#include "reserve_now.h"
#include "reset.h"
#include "send_local_list.h"
#include "set_charging_profile.h"
#include "trigger_message.h"
#include "unlock_connector.h"
#include "update_firmware.h"
#include "certificate_signed.h"
#include "delete_certificate.h"
#include "extended_trigger_message.h"
#include "get_installed_certificate_ids.h"
#include "get_log.h"
#include "install_certificate.h"
#include "log_status_notification.h"
#include "security_event_notification.h"
#include "sign_certificate.h"
#include "signed_firmware_status_notification.h"
#include "signed_update_firmware.h"

#define OCPP16_MESSAGE_COUNT 39

typedef struct ocpp16_message_info {
    const char *action;
    int from_cp; /* 1 = CP originates CALL */
    int from_csms;
} ocpp16_message_info_t;

const ocpp16_message_info_t *ocpp16_message_table(void);

#endif

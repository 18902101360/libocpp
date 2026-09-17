#ifndef OCPP16_MESSAGES_H
#define OCPP16_MESSAGES_H
/* OCPP 1.6 message index */

#include "ocpp16/messages/authorize.h"
#include "ocpp16/messages/boot_notification.h"
#include "ocpp16/messages/data_transfer.h"
#include "ocpp16/messages/diagnostics_status_notification.h"
#include "ocpp16/messages/firmware_status_notification.h"
#include "ocpp16/messages/heartbeat.h"
#include "ocpp16/messages/meter_values.h"
#include "ocpp16/messages/start_transaction.h"
#include "ocpp16/messages/status_notification.h"
#include "ocpp16/messages/stop_transaction.h"
#include "ocpp16/messages/cancel_reservation.h"
#include "ocpp16/messages/change_availability.h"
#include "ocpp16/messages/change_configuration.h"
#include "ocpp16/messages/clear_cache.h"
#include "ocpp16/messages/clear_charging_profile.h"
#include "ocpp16/messages/get_composite_schedule.h"
#include "ocpp16/messages/get_configuration.h"
#include "ocpp16/messages/get_diagnostics.h"
#include "ocpp16/messages/get_local_list_version.h"
#include "ocpp16/messages/remote_start_transaction.h"
#include "ocpp16/messages/remote_stop_transaction.h"
#include "ocpp16/messages/reserve_now.h"
#include "ocpp16/messages/reset.h"
#include "ocpp16/messages/send_local_list.h"
#include "ocpp16/messages/set_charging_profile.h"
#include "ocpp16/messages/trigger_message.h"
#include "ocpp16/messages/unlock_connector.h"
#include "ocpp16/messages/update_firmware.h"
#include "ocpp16/messages/certificate_signed.h"
#include "ocpp16/messages/delete_certificate.h"
#include "ocpp16/messages/extended_trigger_message.h"
#include "ocpp16/messages/get_installed_certificate_ids.h"
#include "ocpp16/messages/get_log.h"
#include "ocpp16/messages/install_certificate.h"
#include "ocpp16/messages/log_status_notification.h"
#include "ocpp16/messages/security_event_notification.h"
#include "ocpp16/messages/sign_certificate.h"
#include "ocpp16/messages/signed_firmware_status_notification.h"
#include "ocpp16/messages/signed_update_firmware.h"

#define OCPP16_MESSAGE_COUNT 39

typedef struct ocpp16_message_info {
    const char *action;
    int from_cp; /* 1 = CP originates CALL */
    int from_csms;
} ocpp16_message_info_t;

const ocpp16_message_info_t *ocpp16_message_table(void);

#endif

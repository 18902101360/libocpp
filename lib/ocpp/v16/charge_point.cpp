// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest
#include <thread>

#include <everest/logging.hpp>
#include <ocpp/v16/charge_point.hpp>
#include <ocpp/v16/charge_point_configuration.hpp>
#include <ocpp/v16/charge_point_impl.hpp>

namespace ocpp {
namespace v16 {

ChargePoint::ChargePoint(const std::string& config, const fs::path& share_path, const fs::path& user_config_path,
                         const fs::path& database_path, const fs::path& sql_init_path, const fs::path& message_log_path,
                         const std::shared_ptr<EvseSecurity> evse_security,
                         const std::optional<SecurityConfiguration> security_configuration) {
    this->charge_point =
        std::make_unique<ChargePointImpl>(config, share_path, user_config_path, database_path, sql_init_path,
                                          message_log_path, evse_security, security_configuration);
}

ChargePoint::~ChargePoint() = default;

/**
 * ChargePoint::update_chargepoint_information - update chargepoint information
 * @vendor: 传入的 vendor
 * @model: 传入的 model
 * @serialnumber: 传入的 serialnumber
 * @chargebox_serialnumber: 传入的 chargebox_serialnumber
 * @firmware_version: 传入的 firmware_version
 */
void ChargePoint::update_chargepoint_information(const std::string& vendor, const std::string& model,
                                                 const std::optional<std::string>& serialnumber,
                                                 const std::optional<std::string>& chargebox_serialnumber,
                                                 const std::optional<std::string>& firmware_version) {
    this->charge_point->update_chargepoint_information(vendor, model, serialnumber, chargebox_serialnumber,
                                                       firmware_version);
}

/**
 * ChargePoint::update_modem_information - update modem information
 * @iccid: 传入的 iccid
 * @imsi: 传入的 imsi
 */
void ChargePoint::update_modem_information(const std::optional<std::string>& iccid,
                                           const std::optional<std::string>& imsi) {
    this->charge_point->update_modem_information(iccid, imsi);
}

/**
 * ChargePoint::update_meter_information - update meter information
 * @meter_serialnumber: 传入的 meter_serialnumber
 * @meter_type: 传入的 meter_type
 */
void ChargePoint::update_meter_information(const std::optional<std::string>& meter_serialnumber,
                                           const std::optional<std::string>& meter_type) {
    this->charge_point->update_meter_information(meter_serialnumber, meter_type);
}

/**
 * ChargePoint::init - init
 * @connector_status_map: 传入的 connector_status_map
 * @resuming_session_ids: 传入的 resuming_session_ids
 *
 * 返回 bool。
 */
bool ChargePoint::init(const std::map<int, ChargePointStatus>& connector_status_map,
                       const std::set<std::string>& resuming_session_ids) {
    return this->charge_point->init(connector_status_map, resuming_session_ids);
}

/**
 * ChargePoint::start - start
 * @connector_status_map: 传入的 connector_status_map
 * @bootreason: 传入的 bootreason
 * @resuming_session_ids: 传入的 resuming_session_ids
 *
 * 返回 bool。
 */
bool ChargePoint::start(const std::map<int, ChargePointStatus>& connector_status_map, BootReasonEnum bootreason,
                        const std::set<std::string>& resuming_session_ids) {
    return this->charge_point->start(connector_status_map, bootreason, resuming_session_ids);
}

/**
 * ChargePoint::restart - restart
 * @connector_status_map: 传入的 connector_status_map
 * @bootreason: 传入的 bootreason
 *
 * 返回 bool。
 */
bool ChargePoint::restart(const std::map<int, ChargePointStatus>& connector_status_map, BootReasonEnum bootreason) {
    return this->charge_point->restart(connector_status_map, bootreason);
}

/**
 * ChargePoint::stop - stop
 *
 * 返回 bool。
 */
bool ChargePoint::stop() {
    return this->charge_point->stop();
}

/**
 * ChargePoint::connect_websocket - connect websocket
 */
void ChargePoint::connect_websocket() {
    this->charge_point->connect_websocket();
}

/**
 * ChargePoint::disconnect_websocket - disconnect websocket
 */
void ChargePoint::disconnect_websocket() {
    this->charge_point->disconnect_websocket();
}

/**
 * ChargePoint::call_set_connection_timeout - call set connection timeout
 */
void ChargePoint::call_set_connection_timeout() {
    this->charge_point->call_set_connection_timeout();
}

/**
 * ChargePoint::authorize_id_token - authorize id token
 * @id_token: 传入的 id_token
 *
 * 返回 EnhancedIdTagInfo。
 */
EnhancedIdTagInfo ChargePoint::authorize_id_token(CiString<20> id_token) {
    return this->charge_point->authorize_id_token(id_token);
}

/**
 * ChargePoint::data_transfer_pnc_authorize - data transfer pnc authorize
 * @emaid: 传入的 emaid
 * @certificate: 传入的 certificate
 * @iso15118_certificate_hash_data: 传入的 iso15118_certificate_hash_data
 *
 * 返回 ocpp::v2::AuthorizeResponse。
 */
ocpp::v2::AuthorizeResponse ChargePoint::data_transfer_pnc_authorize(

    const std::string& emaid, const std::optional<std::string>& certificate,
    const std::optional<std::vector<ocpp::v2::OCSPRequestData>>& iso15118_certificate_hash_data) {
    return this->charge_point->data_transfer_pnc_authorize(emaid, certificate, iso15118_certificate_hash_data);
}

/**
 * ChargePoint::data_transfer_pnc_get_15118_ev_certificate - data transfer pnc get 15118 ev certificate
 * @connector_id: 传入的 connector_id
 * @exi_request: 传入的 exi_request
 * @iso15118_schema_version: 传入的 iso15118_schema_version
 * @certificate_action: 传入的 certificate_action
 */
void ChargePoint::data_transfer_pnc_get_15118_ev_certificate(
    const std::int32_t connector_id, const std::string& exi_request, const std::string& iso15118_schema_version,
    const ocpp::v2::CertificateActionEnum& certificate_action) {

    this->charge_point->data_transfer_pnc_get_15118_ev_certificate(connector_id, exi_request, iso15118_schema_version,
                                                                   certificate_action);
}

/**
 * ChargePoint::data_transfer - data transfer
 * @vendorId: 传入的 vendorId
 * @messageId: 传入的 messageId
 * @data: 传入的 data
 *
 * 返回 std::optional<DataTransferResponse>。
 */
std::optional<DataTransferResponse> ChargePoint::data_transfer(const CiString<255>& vendorId,
                                                               const std::optional<CiString<50>>& messageId,
                                                               const std::optional<std::string>& data) {
    return this->charge_point->data_transfer(vendorId, messageId, data);
}

std::map<std::int32_t, ChargingSchedule>
ChargePoint::get_all_composite_charging_schedules(const std::int32_t duration_s, const ChargingRateUnit unit) {
    return this->charge_point->get_all_composite_charging_schedules(duration_s, unit);
}

std::map<std::int32_t, EnhancedChargingSchedule>
ChargePoint::get_all_enhanced_composite_charging_schedules(const std::int32_t duration_s, const ChargingRateUnit unit) {
    return this->charge_point->get_all_enhanced_composite_charging_schedules(duration_s, unit);
}

/**
 * ChargePoint::on_meter_values - on meter values
 * @connector: 传入的 connector
 * @measurement: 传入的 measurement
 */
void ChargePoint::on_meter_values(std::int32_t connector, const Measurement& measurement) {
    this->charge_point->on_meter_values(connector, measurement);
}

/**
 * ChargePoint::on_max_current_offered - on max current offered
 * @connector: 传入的 connector
 * @max_current: 传入的 max_current
 */
void ChargePoint::on_max_current_offered(std::int32_t connector, std::int32_t max_current) {
    this->charge_point->on_max_current_offered(connector, max_current);
}

/**
 * ChargePoint::on_max_power_offered - on max power offered
 * @connector: 传入的 connector
 * @max_power: 传入的 max_power
 */
void ChargePoint::on_max_power_offered(std::int32_t connector, std::int32_t max_power) {
    this->charge_point->on_max_power_offered(connector, max_power);
}

/**
 * ChargePoint::on_session_started - on session started
 * @connector: 传入的 connector
 * @session_id: 传入的 session_id
 * @reason: 传入的 reason
 * @session_logging_path: 传入的 session_logging_path
 */
void ChargePoint::on_session_started(std::int32_t connector, const std::string& session_id,
                                     const ocpp::SessionStartedReason reason,
                                     const std::optional<std::string>& session_logging_path) {

    this->charge_point->on_session_started(connector, session_id, reason, session_logging_path);
}

/**
 * ChargePoint::on_session_stopped - on session stopped
 * @connector: 传入的 connector
 * @session_id: 传入的 session_id
 */
void ChargePoint::on_session_stopped(const std::int32_t connector, const std::string& session_id) {
    this->charge_point->on_session_stopped(connector, session_id);
}

/**
 * ChargePoint::on_transaction_started - on transaction started
 * @connector: 传入的 connector
 * @session_id: 传入的 session_id
 * @id_token: 传入的 id_token
 * @meter_start: 传入的 meter_start
 * @reservation_id: 传入的 reservation_id
 * @timestamp: 传入的 timestamp
 * @signed_meter_value: 传入的 signed_meter_value
 */
void ChargePoint::on_transaction_started(const std::int32_t& connector, const std::string& session_id,
                                         const std::string& id_token, const double meter_start,
                                         std::optional<std::int32_t> reservation_id, const ocpp::DateTime& timestamp,
                                         std::optional<std::string> signed_meter_value) {
    this->charge_point->on_transaction_started(connector, session_id, id_token, meter_start, reservation_id, timestamp,
                                               signed_meter_value);
}

/**
 * ChargePoint::on_transaction_stopped - on transaction stopped
 * @connector: 传入的 connector
 * @session_id: 传入的 session_id
 * @reason: 传入的 reason
 * @timestamp: 传入的 timestamp
 * @energy_wh_import: 传入的 energy_wh_import
 * @id_tag_end: 传入的 id_tag_end
 * @signed_meter_value: 传入的 signed_meter_value
 */
void ChargePoint::on_transaction_stopped(const std::int32_t connector, const std::string& session_id,
                                         const Reason& reason, ocpp::DateTime timestamp, float energy_wh_import,
                                         std::optional<CiString<20>> id_tag_end,
                                         std::optional<std::string> signed_meter_value) {
    this->charge_point->on_transaction_stopped(connector, session_id, reason, timestamp, energy_wh_import, id_tag_end,
                                               signed_meter_value);
}

/**
 * ChargePoint::on_suspend_charging_ev - on suspend charging ev
 * @connector: 传入的 connector
 * @info: 传入的 info
 */
void ChargePoint::on_suspend_charging_ev(std::int32_t connector, const std::optional<CiString<50>> info) {
    this->charge_point->on_suspend_charging_ev(connector, info);
}

/**
 * ChargePoint::on_suspend_charging_evse - on suspend charging evse
 * @connector: 传入的 connector
 * @info: 传入的 info
 */
void ChargePoint::on_suspend_charging_evse(std::int32_t connector, const std::optional<CiString<50>> info) {
    this->charge_point->on_suspend_charging_evse(connector, info);
}

/**
 * ChargePoint::on_resume_charging - on resume charging
 * @connector: 传入的 connector
 */
void ChargePoint::on_resume_charging(std::int32_t connector) {
    this->charge_point->on_resume_charging(connector);
}

/**
 * ChargePoint::on_error - on error
 * @connector: 传入的 connector
 * @error_info: 传入的 error_info
 */
void ChargePoint::on_error(std::int32_t connector, const ErrorInfo& error_info) {
    this->charge_point->on_error(connector, error_info);
}

/**
 * ChargePoint::on_error_cleared - on error cleared
 * @connector: 传入的 connector
 * @uuid: 传入的 uuid
 */
void ChargePoint::on_error_cleared(std::int32_t connector, const std::string uuid) {
    this->charge_point->on_error_cleared(connector, uuid);
}

/**
 * ChargePoint::on_all_errors_cleared - on all errors cleared
 * @connector: 传入的 connector
 */
void ChargePoint::on_all_errors_cleared(std::int32_t connector) {
    this->charge_point->on_all_errors_cleared(connector);
}

/**
 * ChargePoint::on_log_status_notification - on log status notification
 * @request_id: 传入的 request_id
 * @log_status: 传入的 log_status
 */
void ChargePoint::on_log_status_notification(std::int32_t request_id, std::string log_status) {
    this->charge_point->on_log_status_notification(request_id, log_status);
}

/**
 * ChargePoint::on_firmware_update_status_notification - on firmware update status notification
 * @request_id: 传入的 request_id
 * @firmware_update_status: 传入的 firmware_update_status
 */
void ChargePoint::on_firmware_update_status_notification(std::int32_t request_id,
                                                         const FirmwareStatusNotification firmware_update_status) {
    this->charge_point->on_firmware_update_status_notification(request_id, firmware_update_status);
}

/**
 * ChargePoint::on_reservation_start - on reservation start
 * @connector: 传入的 connector
 */
void ChargePoint::on_reservation_start(std::int32_t connector) {
    this->charge_point->on_reservation_start(connector);
}

/**
 * ChargePoint::on_reservation_end - on reservation end
 * @connector: 传入的 connector
 */
void ChargePoint::on_reservation_end(std::int32_t connector) {
    this->charge_point->on_reservation_end(connector);
}

/**
 * ChargePoint::on_enabled - on enabled
 * @connector: 传入的 connector
 */
void ChargePoint::on_enabled(std::int32_t connector) {
    this->charge_point->on_enabled(connector);
}

/**
 * ChargePoint::on_disabled - on disabled
 * @connector: 传入的 connector
 */
void ChargePoint::on_disabled(std::int32_t connector) {
    this->charge_point->on_disabled(connector);
}

/**
 * ChargePoint::on_plugin_timeout - on plugin timeout
 * @connector: 传入的 connector
 */
void ChargePoint::on_plugin_timeout(std::int32_t connector) {
    this->charge_point->on_plugin_timeout(connector);
}

/**
 * ChargePoint::on_security_event - on security event
 * @event_type: 传入的 event_type
 * @tech_info: 传入的 tech_info
 * @critical: 传入的 critical
 * @timestamp: 传入的 timestamp
 */
void ChargePoint::on_security_event(const CiString<50>& event_type, const std::optional<CiString<255>>& tech_info,
                                    const std::optional<bool>& critical, const std::optional<DateTime>& timestamp) {
    this->charge_point->on_security_event(event_type, tech_info, critical, timestamp);
}

/**
 * ChargePoint::on_change_availability - on change availability
 * @request: 传入的 request
 *
 * 返回 ChangeAvailabilityResponse。
 */
ChangeAvailabilityResponse ChargePoint::on_change_availability(const ChangeAvailabilityRequest& request) {
    return this->charge_point->on_change_availability(request);
}

/**
 * ChargePoint::register_data_transfer_callback - register data transfer callback
 * @vendorId: 传入的 vendorId
 * @messageId: 传入的 messageId
 * @callback: 传入的 callback
 */
void ChargePoint::register_data_transfer_callback(
    const CiString<255>& vendorId, const CiString<50>& messageId,
    const std::function<DataTransferResponse(const std::optional<std::string>& msg)>& callback) {
    this->charge_point->register_data_transfer_callback(vendorId, messageId, callback);
}

/**
 * ChargePoint::register_data_transfer_callback - register data transfer callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_data_transfer_callback(
    const std::function<DataTransferResponse(const DataTransferRequest& request)>& callback) {
    this->charge_point->register_data_transfer_callback(callback);
}

/**
 * ChargePoint::register_enable_evse_callback - register enable evse callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_enable_evse_callback(const std::function<bool(std::int32_t connector)>& callback) {
    this->charge_point->register_enable_evse_callback(callback);
}

/**
 * ChargePoint::register_disable_evse_callback - register disable evse callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_disable_evse_callback(const std::function<bool(std::int32_t connector)>& callback) {
    this->charge_point->register_disable_evse_callback(callback);
}

/**
 * ChargePoint::register_pause_charging_callback - register pause charging callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_pause_charging_callback(const std::function<bool(std::int32_t connector)>& callback) {
    this->charge_point->register_pause_charging_callback(callback);
}

/**
 * ChargePoint::register_resume_charging_callback - register resume charging callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_resume_charging_callback(const std::function<bool(std::int32_t connector)>& callback) {
    this->charge_point->register_resume_charging_callback(callback);
}

/**
 * ChargePoint::register_provide_token_callback - register provide token callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_provide_token_callback(
    const std::function<void(const std::string& id_token, std::vector<std::int32_t> referenced_connectors,
                             bool prevalidated)>& callback) {
    this->charge_point->register_provide_token_callback(callback);
}

/**
 * ChargePoint::register_stop_transaction_callback - register stop transaction callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_stop_transaction_callback(
    const std::function<bool(std::int32_t connector, Reason reason)>& callback) {
    this->charge_point->register_stop_transaction_callback(callback);
}

/**
 * ChargePoint::register_reserve_now_callback - register reserve now callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_reserve_now_callback(
    const std::function<ReservationStatus(std::int32_t reservation_id, std::int32_t connector,
                                          ocpp::DateTime expiryDate, CiString<20> idTag,
                                          std::optional<CiString<20>> parent_id)>& callback) {
    this->charge_point->register_reserve_now_callback(callback);
}

/**
 * ChargePoint::register_cancel_reservation_callback - register cancel reservation callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_cancel_reservation_callback(const std::function<bool(std::int32_t connector)>& callback) {
    this->charge_point->register_cancel_reservation_callback(callback);
}

/**
 * ChargePoint::register_unlock_connector_callback - register unlock connector callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_unlock_connector_callback(
    const std::function<UnlockStatus(std::int32_t connector)>& callback) {
    this->charge_point->register_unlock_connector_callback(callback);
}

/**
 * ChargePoint::register_upload_diagnostics_callback - register upload diagnostics callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_upload_diagnostics_callback(
    const std::function<GetLogResponse(const GetDiagnosticsRequest& request)>& callback) {
    this->charge_point->register_upload_diagnostics_callback(callback);
}

/**
 * ChargePoint::register_update_firmware_callback - register update firmware callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_update_firmware_callback(
    const std::function<void(const UpdateFirmwareRequest msg)>& callback) {
    this->charge_point->register_update_firmware_callback(callback);
}

/**
 * ChargePoint::register_signed_update_firmware_callback - register signed update firmware callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_signed_update_firmware_callback(
    const std::function<UpdateFirmwareStatusEnumType(const SignedUpdateFirmwareRequest msg)>& callback) {
    this->charge_point->register_signed_update_firmware_callback(callback);
}

/**
 * ChargePoint::register_all_connectors_unavailable_callback - register all connectors unavailable callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_all_connectors_unavailable_callback(const std::function<void()>& callback) {
    this->charge_point->register_all_connectors_unavailable_callback(callback);
}

/**
 * ChargePoint::register_upload_logs_callback - register upload logs callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_upload_logs_callback(const std::function<GetLogResponse(GetLogRequest req)>& callback) {
    this->charge_point->register_upload_logs_callback(callback);
}

/**
 * ChargePoint::register_set_connection_timeout_callback - register set connection timeout callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_set_connection_timeout_callback(
    const std::function<void(std::int32_t connection_timeout)>& callback) {
    this->charge_point->register_set_connection_timeout_callback(callback);
}

/**
 * ChargePoint::register_is_reset_allowed_callback - register is reset allowed callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_is_reset_allowed_callback(const std::function<bool(const ResetType& reset_type)>& callback) {
    this->charge_point->register_is_reset_allowed_callback(callback);
}

/**
 * ChargePoint::register_reset_callback - register reset callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_reset_callback(const std::function<void(const ResetType& reset_type)>& callback) {
    this->charge_point->register_reset_callback(callback);
}

/**
 * ChargePoint::register_set_system_time_callback - register set system time callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_set_system_time_callback(
    const std::function<void(const std::string& system_time)>& callback) {
    this->charge_point->register_set_system_time_callback(callback);
}

/**
 * ChargePoint::register_boot_notification_response_callback - register boot notification response callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_boot_notification_response_callback(
    const std::function<void(const BootNotificationResponse& boot_notification_response)>& callback) {
    this->charge_point->register_boot_notification_response_callback(callback);
}

/**
 * ChargePoint::register_signal_set_charging_profiles_callback - register signal set charging profiles callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_signal_set_charging_profiles_callback(const std::function<void()>& callback) {
    this->charge_point->register_signal_set_charging_profiles_callback(callback);
}

/**
 * ChargePoint::register_connection_state_changed_callback - register connection state changed callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_connection_state_changed_callback(const std::function<void(bool is_connected)>& callback) {
    this->charge_point->register_connection_state_changed_callback(callback);
}

/**
 * ChargePoint::register_get_15118_ev_certificate_response_callback - register get 15118 ev certificate response callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_get_15118_ev_certificate_response_callback(
    const std::function<void(const std::int32_t connector,
                             const ocpp::v2::Get15118EVCertificateResponse& certificate_response,
                             const ocpp::v2::CertificateActionEnum& certificate_action)>& callback) {
    this->charge_point->register_get_15118_ev_certificate_response_callback(callback);
}

/**
 * ChargePoint::register_transaction_started_callback - register transaction started callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_transaction_started_callback(
    const std::function<void(const std::int32_t connector, const std::string& session_id)>& callback) {
    this->charge_point->register_transaction_started_callback(callback);
}

/**
 * ChargePoint::register_transaction_stopped_callback - register transaction stopped callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_transaction_stopped_callback(
    const std::function<void(const std::int32_t connector, const std::string& session_id,
                             const std::int32_t transaction_id)>& callback) {
    this->charge_point->register_transaction_stopped_callback(callback);
}

/**
 * ChargePoint::register_transaction_updated_callback - register transaction updated callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_transaction_updated_callback(
    const std::function<void(const std::int32_t connector, const std::string& session_id,
                             const std::int32_t transaction_id, const IdTagInfo& id_tag_info)>& callback) {
    this->charge_point->register_transaction_updated_callback(callback);
}

/**
 * ChargePoint::register_configuration_key_changed_callback - register configuration key changed callback
 * @key: 传入的 key
 * @callback: 传入的 callback
 */
void ChargePoint::register_configuration_key_changed_callback(
    const CiString<50>& key, const std::function<void(const KeyValue& key_value)>& callback) {
    this->charge_point->register_configuration_key_changed_callback(key, callback);
}

/**
 * ChargePoint::register_generic_configuration_key_changed_callback - register generic configuration key changed callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_generic_configuration_key_changed_callback(
    const std::function<void(const KeyValue& key_value)>& callback) {
    this->charge_point->register_generic_configuration_key_changed_callback(callback);
}

/**
 * ChargePoint::register_security_event_callback - register security event callback
 * @callback: 传入的 callback
 */
void ChargePoint::register_security_event_callback(
    const std::function<void(const std::string& type, const std::string& tech_info)>& callback) {
    this->charge_point->register_security_event_callback(callback);
}

/**
 * ChargePoint::register_is_token_reserved_for_connector_callback - register is token reserved for connector callback
 * @id_token: 传入的 id_token
 */
void ChargePoint::register_is_token_reserved_for_connector_callback(
    const std::function<ocpp::ReservationCheckStatus(const std::int32_t connector, const std::string& id_token)>&
        callback) {
    this->charge_point->register_is_token_reserved_for_connector_callback(callback);
}

/**
 * ChargePoint::register_session_cost_callback - register session cost callback
 * @number_of_decimals: 传入的 number_of_decimals
 */
void ChargePoint::register_session_cost_callback(
    const std::function<DataTransferResponse(const RunningCost& running_cost, const std::uint32_t number_of_decimals)>&
        session_cost_callback) {
    this->charge_point->register_session_cost_callback(session_cost_callback);
}

/**
 * ChargePoint::register_tariff_message_callback - register tariff message callback
 * @tariff_message_callback: 传入的 tariff_message_callback
 */
void ChargePoint::register_tariff_message_callback(
    const std::function<DataTransferResponse(const TariffMessage& message)>& tariff_message_callback) {
    this->charge_point->register_tariff_message_callback(tariff_message_callback);
}

/**
 * ChargePoint::register_set_display_message_callback - register set display message callback
 * @set_display_message_callback: 传入的 set_display_message_callback
 */
void ChargePoint::register_set_display_message_callback(
    const std::function<DataTransferResponse(const std::vector<DisplayMessage>&)> set_display_message_callback) {
    this->charge_point->register_set_display_message_callback(set_display_message_callback);
}

/**
 * ChargePoint::get_configuration_key - get configuration key
 * @request: 传入的 request
 *
 * 返回 GetConfigurationResponse。
 */
GetConfigurationResponse ChargePoint::get_configuration_key(const GetConfigurationRequest& request) {
    return this->charge_point->get_configuration_key(request);
}

/**
 * ChargePoint::set_configuration_key - set configuration key
 * @key: 传入的 key
 * @value: 传入的 value
 *
 * 返回 ConfigurationStatus。
 */
ConfigurationStatus ChargePoint::set_configuration_key(CiString<50> key, CiString<500> value) {
    return this->charge_point->set_configuration_key(key, value);
}

/**
 * ChargePoint::set_message_queue_resume_delay - set message queue resume delay
 * @delay: 传入的 delay
 */
void ChargePoint::set_message_queue_resume_delay(std::chrono::seconds delay) {
    this->charge_point->set_message_queue_resume_delay(delay);
}

/**
 * ChargePoint::set_powermeter_public_key - set powermeter public key
 * @connector: 传入的 connector
 * @public_key_pem: 传入的 public_key_pem
 *
 * 返回 bool。
 */
bool ChargePoint::set_powermeter_public_key(const int32_t connector, const std::string& public_key_pem) {
    return this->charge_point->set_powermeter_public_key(connector, public_key_pem);
}

} // namespace v16
} // namespace ocpp

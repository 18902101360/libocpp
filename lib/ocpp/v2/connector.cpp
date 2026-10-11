// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest

#include <utility>

#include <everest/logging.hpp>
#include <ocpp/v2/connector.hpp>

namespace ocpp {
namespace v2 {

namespace conversions {

/**
 * connector_event_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string connector_event_to_string(ConnectorEvent e) {
    switch (e) {
    case ConnectorEvent::PlugIn:
        return "PlugIn";
    case ConnectorEvent::PlugOut:
        return "PlugOut";
    case ConnectorEvent::Reserve:
        return "Reserve";
    case ConnectorEvent::ReservationCleared:
        return "ReservationCleared";
    case ConnectorEvent::Error:
        return "Error";
    case ConnectorEvent::ErrorCleared:
        return "ErrorCleared";
    case ConnectorEvent::Unavailable:
        return "Unavailable";
    case ConnectorEvent::UnavailableCleared:
        return "UnavailableCleared";
    }

    throw EnumToStringException{e, "ConnectorEvent"};
}

} // namespace conversions

Connector::Connector(const std::int32_t evse_id, const std::int32_t connector_id,
                     std::shared_ptr<ComponentStateManagerInterface> component_state_manager) :
    evse_id(evse_id), connector_id(connector_id), component_state_manager(component_state_manager) {
}

/**
 * Connector::submit_event - submit event
 * @event: 传入的 event
 */
void Connector::submit_event(ConnectorEvent event) {
    const std::lock_guard lk(this->status_mutex);
    switch (event) {
    case ConnectorEvent::PlugIn:
        this->component_state_manager->set_connector_occupied(this->evse_id, this->connector_id, true);
        break;
    case ConnectorEvent::PlugOut:
        this->component_state_manager->set_connector_occupied(this->evse_id, this->connector_id, false);
        break;
    case ConnectorEvent::Reserve:
        this->component_state_manager->set_connector_reserved(this->evse_id, this->connector_id, true);
        break;
    case ConnectorEvent::ReservationCleared:
        this->component_state_manager->set_connector_reserved(this->evse_id, this->connector_id, false);
        break;
    case ConnectorEvent::Error:
        this->component_state_manager->set_connector_faulted(this->evse_id, this->connector_id, true);
        break;
    case ConnectorEvent::ErrorCleared:
        this->component_state_manager->set_connector_faulted(this->evse_id, this->connector_id, false);
        break;
    case ConnectorEvent::Unavailable:
        this->component_state_manager->set_connector_unavailable(this->evse_id, this->connector_id, true);
        break;
    case ConnectorEvent::UnavailableCleared:
        this->component_state_manager->set_connector_unavailable(this->evse_id, this->connector_id, false);
        break;
    }
}

/**
 * Connector::set_connector_operative_status - set connector operative status
 * @new_status: 传入的 new_status
 * @persist: 传入的 persist
 */
void Connector::set_connector_operative_status(OperationalStatusEnum new_status, bool persist) {
    this->component_state_manager->set_connector_individual_operational_status(this->evse_id, this->connector_id,
                                                                               new_status, persist);
}

/**
 * Connector::restore_connector_operative_status - restore connector operative status
 */
void Connector::restore_connector_operative_status() {
    try {
        auto persisted_status = this->component_state_manager->get_connector_persisted_operational_status(
            this->evse_id, this->connector_id);
        this->component_state_manager->set_connector_individual_operational_status(this->evse_id, this->connector_id,
                                                                                   persisted_status, false);
    } catch (const everest::db::QueryExecutionException& e) {
        EVLOG_error << "QueryExecutionException while restoring connector status of evse_id: " << this->evse_id
                    << "; connector_id: " << this->connector_id << ": " << e.what();
    } catch (const std::exception& e) {
        EVLOG_error << "Internal error while restoring connector status of evse_id: " << this->evse_id
                    << "; connector_id: " << this->connector_id << ": " << e.what();
    }
}

/**
 * Connector::get_effective_operational_status - get effective operational status
 *
 * 返回 OperationalStatusEnum。
 */
OperationalStatusEnum Connector::get_effective_operational_status() {
    return this->component_state_manager->get_connector_effective_operational_status(this->evse_id, this->connector_id);
}

/**
 * Connector::get_effective_connector_status - get effective connector status
 *
 * 返回 ConnectorStatusEnum。
 */
ConnectorStatusEnum Connector::get_effective_connector_status() {
    return this->component_state_manager->get_connector_effective_status(this->evse_id, this->connector_id);
}

} // namespace v2
} // namespace ocpp

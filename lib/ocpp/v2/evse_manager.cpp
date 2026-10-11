// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2024 Pionix GmbH and Contributors to EVerest

#include <ocpp/v2/evse_manager.hpp>

namespace ocpp {
namespace v2 {

using EvseIteratorImpl = VectorOfUniquePtrIterator<EvseInterface>;

EvseManager::EvseManager(const std::map<std::int32_t, std::int32_t>& evse_connector_structure,
                         DeviceModel& device_model, std::shared_ptr<DatabaseHandler> database_handler,
                         std::shared_ptr<ComponentStateManagerInterface> component_state_manager,
                         const std::function<void(const MeterValue& meter_value, EnhancedTransaction& transaction)>&
                             transaction_meter_value_req,
                         const std::function<void(std::int32_t evse_id)>& pause_charging_callback) {
    evses.reserve(evse_connector_structure.size());
    for (const auto& [evse_id, connectors] : evse_connector_structure) {
        evses.push_back(std::make_unique<Evse>(evse_id, connectors, device_model, database_handler,
                                               component_state_manager, transaction_meter_value_req,
                                               pause_charging_callback));
    }
}

/**
 * EvseManager::begin - begin
 *
 * 返回 EvseManager::EvseIterator。
 */
EvseManager::EvseIterator EvseManager::begin() {
    return EvseIterator(std::make_unique<EvseIteratorImpl>(this->evses.begin()));
}
/**
 * EvseManager::end - end
 *
 * 返回 EvseManager::EvseIterator。
 */
EvseManager::EvseIterator EvseManager::end() {
    return EvseIterator(std::make_unique<EvseIteratorImpl>(this->evses.end()));
}

/**
 * EvseManager::get_evse - get evse
 * @id: 传入的 id
 *
 * 返回 EvseInterface&。
 */
EvseInterface& EvseManager::get_evse(std::int32_t id) {
    if (id <= 0 or id > this->evses.size()) {
        throw EvseOutOfRangeException(id);
    }
    return *this->evses.at(id - 1);
}

/**
 * EvseManager::get_evse - get evse
 * @id: 传入的 id
 *
 * 返回 const EvseInterface&。
 */
const EvseInterface& EvseManager::get_evse(const std::int32_t id) const {
    if (id <= 0 or id > this->evses.size()) {
        throw EvseOutOfRangeException(id);
    }
    return *this->evses.at(id - 1);
}

/**
 * EvseManager::does_connector_exist - does connector exist
 * @evse_id: 传入的 evse_id
 * @connector_type: 传入的 connector_type
 *
 * 返回 bool。
 */
bool EvseManager::does_connector_exist(const std::int32_t evse_id, const CiString<20> connector_type) const {
    const EvseInterface* evse = nullptr;
    try {
        evse = &this->get_evse(evse_id);
    } catch (const EvseOutOfRangeException&) {
        EVLOG_error << "Evse id " << evse_id << " is not a valid evse id.";
        return false;
    }

    return evse->does_connector_exist(connector_type);
}

/**
 * EvseManager::does_evse_exist - does evse exist
 * @id: 传入的 id
 *
 * 返回 bool。
 */
bool EvseManager::does_evse_exist(const std::int32_t id) const {
    return id >= 0 && static_cast<std::uint64_t>(id) <= this->evses.size();
}

/**
 * EvseManager::are_all_connectors_effectively_inoperative - are all connectors effectively inoperative
 *
 * 返回 bool。
 */
bool EvseManager::are_all_connectors_effectively_inoperative() const {
    // Check that all connectors on all EVSEs are inoperative
    for (const auto& evse : this->evses) {
        for (int connector_id = 1; connector_id <= evse->get_number_of_connectors(); connector_id++) {
            const OperationalStatusEnum connector_status =
                evse->get_connector_effective_operational_status(connector_id);
            if (connector_status == OperationalStatusEnum::Operative) {
                return false;
            }
        }
    }
    return true;
}

/**
 * EvseManager::get_number_of_evses - get number of evses
 *
 * 返回 size_t。
 */
size_t EvseManager::get_number_of_evses() const {
    return this->evses.size();
}

/**
 * EvseManager::get_transaction_evseid - get transaction evseid
 * @transaction_id: 传入的 transaction_id
 *
 * 返回 std::optional<std::int32_t>。
 */
std::optional<std::int32_t> EvseManager::get_transaction_evseid(const CiString<36>& transaction_id) const {
    for (const auto& evse : this->evses) {
        if (evse->has_active_transaction()) {
            if (transaction_id == evse->get_transaction()->get_transaction().transactionId) {
                return evse->get_id();
            }
        }
    }

    return std::nullopt;
}

/**
 * EvseManager::any_transaction_active - any transaction active
 * @evse: 传入的 evse
 *
 * 返回 bool。
 */
bool EvseManager::any_transaction_active(const std::optional<EVSE>& evse) const {
    if (!evse.has_value()) {
        for (const auto& evse : this->evses) {
            if (evse->has_active_transaction()) {
                return true;
            }
        }
        return false;
    }
    return this->get_evse(evse.value().id).has_active_transaction();
}

/**
 * EvseManager::is_valid_evse - is valid evse
 * @evse: 传入的 evse
 *
 * 返回 bool。
 */
bool EvseManager::is_valid_evse(const EVSE& evse) const {
    return this->does_evse_exist(evse.id) and
           (!evse.connectorId.has_value() or
            this->get_evse(evse.id).get_number_of_connectors() >= evse.connectorId.value());
}

// Free functions

void set_evse_connectors_unavailable(EvseInterface& evse, bool persist) {
    const std::uint32_t number_of_connectors = evse.get_number_of_connectors();

    for (std::uint32_t i = 1; i <= number_of_connectors; ++i) {
        evse.set_connector_operative_status(static_cast<std::int32_t>(i), OperationalStatusEnum::Inoperative, persist);
    }
}

} // namespace v2
} // namespace ocpp

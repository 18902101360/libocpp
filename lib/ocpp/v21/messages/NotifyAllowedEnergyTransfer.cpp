// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v21/messages/NotifyAllowedEnergyTransfer.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v21 {

/**
 * NotifyAllowedEnergyTransferRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string NotifyAllowedEnergyTransferRequest::get_type() const {
    return "NotifyAllowedEnergyTransfer";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const NotifyAllowedEnergyTransferRequest& k) {
    // the required parts of the message
    j = json{
        {"transactionId", k.transactionId},
        {"allowedEnergyTransfer", json::array()},
    };
    for (const auto& val : k.allowedEnergyTransfer) {
        j["allowedEnergyTransfer"].push_back(ocpp::v2::conversions::energy_transfer_mode_enum_to_string(val));
    }
    // the optional parts of the message
    if (k.customData) {
        j["customData"] = k.customData.value();
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, NotifyAllowedEnergyTransferRequest& k) {
    // the required parts of the message
    k.transactionId = j.at("transactionId");
    for (const auto& val : j.at("allowedEnergyTransfer")) {
        k.allowedEnergyTransfer.push_back(ocpp::v2::conversions::string_to_energy_transfer_mode_enum(val));
    }

    // the optional parts of the message
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given NotifyAllowedEnergyTransferRequest \p k to the given output
/// stream \p os
/// \returns an output stream with the NotifyAllowedEnergyTransferRequest written to
std::ostream& operator<<(std::ostream& os, const NotifyAllowedEnergyTransferRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * NotifyAllowedEnergyTransferResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string NotifyAllowedEnergyTransferResponse::get_type() const {
    return "NotifyAllowedEnergyTransferResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const NotifyAllowedEnergyTransferResponse& k) {
    // the required parts of the message
    j = json{
        {"status", ocpp::v2::conversions::notify_allowed_energy_transfer_status_enum_to_string(k.status)},
    };
    // the optional parts of the message
    if (k.statusInfo) {
        j["statusInfo"] = k.statusInfo.value();
    }
    if (k.customData) {
        j["customData"] = k.customData.value();
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, NotifyAllowedEnergyTransferResponse& k) {
    // the required parts of the message
    k.status = ocpp::v2::conversions::string_to_notify_allowed_energy_transfer_status_enum(j.at("status"));

    // the optional parts of the message
    if (j.contains("statusInfo")) {
        k.statusInfo.emplace(j.at("statusInfo"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given NotifyAllowedEnergyTransferResponse \p k to the given output
/// stream \p os
/// \returns an output stream with the NotifyAllowedEnergyTransferResponse written to
std::ostream& operator<<(std::ostream& os, const NotifyAllowedEnergyTransferResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v21
} // namespace ocpp

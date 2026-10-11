// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v16/messages/RemoteStartTransaction.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v16 {

/**
 * RemoteStartTransactionRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string RemoteStartTransactionRequest::get_type() const {
    return "RemoteStartTransaction";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const RemoteStartTransactionRequest& k) {
    // the required parts of the message
    j = json{
        {"idTag", k.idTag},
    };
    // the optional parts of the message
    if (k.connectorId) {
        j["connectorId"] = k.connectorId.value();
    }
    if (k.chargingProfile) {
        j["chargingProfile"] = k.chargingProfile.value();
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, RemoteStartTransactionRequest& k) {
    // the required parts of the message
    k.idTag = j.at("idTag");

    // the optional parts of the message
    if (j.contains("connectorId")) {
        k.connectorId.emplace(j.at("connectorId"));
    }
    if (j.contains("chargingProfile")) {
        k.chargingProfile.emplace(j.at("chargingProfile"));
    }
}

/// \brief Writes the string representation of the given RemoteStartTransactionRequest \p k to the given output stream
/// \p os
/// \returns an output stream with the RemoteStartTransactionRequest written to
std::ostream& operator<<(std::ostream& os, const RemoteStartTransactionRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * RemoteStartTransactionResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string RemoteStartTransactionResponse::get_type() const {
    return "RemoteStartTransactionResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const RemoteStartTransactionResponse& k) {
    // the required parts of the message
    j = json{
        {"status", conversions::remote_start_stop_status_to_string(k.status)},
    };
    // the optional parts of the message
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, RemoteStartTransactionResponse& k) {
    // the required parts of the message
    k.status = conversions::string_to_remote_start_stop_status(j.at("status"));

    // the optional parts of the message
}

/// \brief Writes the string representation of the given RemoteStartTransactionResponse \p k to the given output stream
/// \p os
/// \returns an output stream with the RemoteStartTransactionResponse written to
std::ostream& operator<<(std::ostream& os, const RemoteStartTransactionResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v16
} // namespace ocpp

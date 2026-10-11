// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v16/messages/StartTransaction.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v16 {

/**
 * StartTransactionRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string StartTransactionRequest::get_type() const {
    return "StartTransaction";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const StartTransactionRequest& k) {
    // the required parts of the message
    j = json{
        {"connectorId", k.connectorId},
        {"idTag", k.idTag},
        {"meterStart", k.meterStart},
        {"timestamp", k.timestamp.to_rfc3339()},
    };
    // the optional parts of the message
    if (k.reservationId) {
        j["reservationId"] = k.reservationId.value();
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, StartTransactionRequest& k) {
    // the required parts of the message
    k.connectorId = j.at("connectorId");
    k.idTag = j.at("idTag");
    k.meterStart = j.at("meterStart");
    k.timestamp = ocpp::DateTime(std::string(j.at("timestamp")));

    // the optional parts of the message
    if (j.contains("reservationId")) {
        k.reservationId.emplace(j.at("reservationId"));
    }
}

/// \brief Writes the string representation of the given StartTransactionRequest \p k to the given output stream \p os
/// \returns an output stream with the StartTransactionRequest written to
std::ostream& operator<<(std::ostream& os, const StartTransactionRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * StartTransactionResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string StartTransactionResponse::get_type() const {
    return "StartTransactionResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const StartTransactionResponse& k) {
    // the required parts of the message
    j = json{
        {"idTagInfo", k.idTagInfo},
        {"transactionId", k.transactionId},
    };
    // the optional parts of the message
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, StartTransactionResponse& k) {
    // the required parts of the message
    k.idTagInfo = j.at("idTagInfo");
    k.transactionId = j.at("transactionId");

    // the optional parts of the message
}

/// \brief Writes the string representation of the given StartTransactionResponse \p k to the given output stream \p os
/// \returns an output stream with the StartTransactionResponse written to
std::ostream& operator<<(std::ostream& os, const StartTransactionResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v16
} // namespace ocpp

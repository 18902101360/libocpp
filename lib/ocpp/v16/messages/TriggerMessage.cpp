// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v16/messages/TriggerMessage.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v16 {

/**
 * TriggerMessageRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string TriggerMessageRequest::get_type() const {
    return "TriggerMessage";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const TriggerMessageRequest& k) {
    // the required parts of the message
    j = json{
        {"requestedMessage", conversions::message_trigger_to_string(k.requestedMessage)},
    };
    // the optional parts of the message
    if (k.connectorId) {
        j["connectorId"] = k.connectorId.value();
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, TriggerMessageRequest& k) {
    // the required parts of the message
    k.requestedMessage = conversions::string_to_message_trigger(j.at("requestedMessage"));

    // the optional parts of the message
    if (j.contains("connectorId")) {
        k.connectorId.emplace(j.at("connectorId"));
    }
}

/// \brief Writes the string representation of the given TriggerMessageRequest \p k to the given output stream \p os
/// \returns an output stream with the TriggerMessageRequest written to
std::ostream& operator<<(std::ostream& os, const TriggerMessageRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * TriggerMessageResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string TriggerMessageResponse::get_type() const {
    return "TriggerMessageResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const TriggerMessageResponse& k) {
    // the required parts of the message
    j = json{
        {"status", conversions::trigger_message_status_to_string(k.status)},
    };
    // the optional parts of the message
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, TriggerMessageResponse& k) {
    // the required parts of the message
    k.status = conversions::string_to_trigger_message_status(j.at("status"));

    // the optional parts of the message
}

/// \brief Writes the string representation of the given TriggerMessageResponse \p k to the given output stream \p os
/// \returns an output stream with the TriggerMessageResponse written to
std::ostream& operator<<(std::ostream& os, const TriggerMessageResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v16
} // namespace ocpp

// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v2/messages/GetDisplayMessages.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v2 {

/**
 * GetDisplayMessagesRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string GetDisplayMessagesRequest::get_type() const {
    return "GetDisplayMessages";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const GetDisplayMessagesRequest& k) {
    // the required parts of the message
    j = json{
        {"requestId", k.requestId},
    };
    // the optional parts of the message
    if (k.id) {
        j["id"] = json::array();
        for (const auto& val : k.id.value()) {
            j["id"].push_back(val);
        }
    }
    if (k.priority) {
        j["priority"] = conversions::message_priority_enum_to_string(k.priority.value());
    }
    if (k.state) {
        j["state"] = conversions::message_state_enum_to_string(k.state.value());
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
void from_json(const json& j, GetDisplayMessagesRequest& k) {
    // the required parts of the message
    k.requestId = j.at("requestId");

    // the optional parts of the message
    if (j.contains("id")) {
        const json& arr = j.at("id");
        std::vector<std::int32_t> vec;
        for (const auto& val : arr) {
            vec.push_back(val);
        }
        k.id.emplace(vec);
    }
    if (j.contains("priority")) {
        k.priority.emplace(conversions::string_to_message_priority_enum(j.at("priority")));
    }
    if (j.contains("state")) {
        k.state.emplace(conversions::string_to_message_state_enum(j.at("state")));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given GetDisplayMessagesRequest \p k to the given output stream \p os
/// \returns an output stream with the GetDisplayMessagesRequest written to
std::ostream& operator<<(std::ostream& os, const GetDisplayMessagesRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * GetDisplayMessagesResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string GetDisplayMessagesResponse::get_type() const {
    return "GetDisplayMessagesResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const GetDisplayMessagesResponse& k) {
    // the required parts of the message
    j = json{
        {"status", conversions::get_display_messages_status_enum_to_string(k.status)},
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
void from_json(const json& j, GetDisplayMessagesResponse& k) {
    // the required parts of the message
    k.status = conversions::string_to_get_display_messages_status_enum(j.at("status"));

    // the optional parts of the message
    if (j.contains("statusInfo")) {
        k.statusInfo.emplace(j.at("statusInfo"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given GetDisplayMessagesResponse \p k to the given output stream \p
/// os
/// \returns an output stream with the GetDisplayMessagesResponse written to
std::ostream& operator<<(std::ostream& os, const GetDisplayMessagesResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v2
} // namespace ocpp

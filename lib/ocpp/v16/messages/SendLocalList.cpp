// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v16/messages/SendLocalList.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v16 {

/**
 * SendLocalListRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string SendLocalListRequest::get_type() const {
    return "SendLocalList";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const SendLocalListRequest& k) {
    // the required parts of the message
    j = json{
        {"listVersion", k.listVersion},
        {"updateType", conversions::update_type_to_string(k.updateType)},
    };
    // the optional parts of the message
    if (k.localAuthorizationList) {
        j["localAuthorizationList"] = json::array();
        for (const auto& val : k.localAuthorizationList.value()) {
            j["localAuthorizationList"].push_back(val);
        }
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, SendLocalListRequest& k) {
    // the required parts of the message
    k.listVersion = j.at("listVersion");
    k.updateType = conversions::string_to_update_type(j.at("updateType"));

    // the optional parts of the message
    if (j.contains("localAuthorizationList")) {
        const json& arr = j.at("localAuthorizationList");
        std::vector<LocalAuthorizationList> vec;
        for (const auto& val : arr) {
            vec.push_back(val);
        }
        k.localAuthorizationList.emplace(vec);
    }
}

/// \brief Writes the string representation of the given SendLocalListRequest \p k to the given output stream \p os
/// \returns an output stream with the SendLocalListRequest written to
std::ostream& operator<<(std::ostream& os, const SendLocalListRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * SendLocalListResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string SendLocalListResponse::get_type() const {
    return "SendLocalListResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const SendLocalListResponse& k) {
    // the required parts of the message
    j = json{
        {"status", conversions::update_status_to_string(k.status)},
    };
    // the optional parts of the message
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, SendLocalListResponse& k) {
    // the required parts of the message
    k.status = conversions::string_to_update_status(j.at("status"));

    // the optional parts of the message
}

/// \brief Writes the string representation of the given SendLocalListResponse \p k to the given output stream \p os
/// \returns an output stream with the SendLocalListResponse written to
std::ostream& operator<<(std::ostream& os, const SendLocalListResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v16
} // namespace ocpp

// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v16/messages/Reset.hpp>

#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v16 {

/**
 * ResetRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string ResetRequest::get_type() const {
    return "Reset";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const ResetRequest& k) {
    // the required parts of the message
    j = json{
        {"type", conversions::reset_type_to_string(k.type)},
    };
    // the optional parts of the message
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, ResetRequest& k) {
    // the required parts of the message
    k.type = conversions::string_to_reset_type(j.at("type"));

    // the optional parts of the message
}

/// \brief Writes the string representation of the given ResetRequest \p k to the given output stream \p os
/// \returns an output stream with the ResetRequest written to
std::ostream& operator<<(std::ostream& os, const ResetRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * ResetResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string ResetResponse::get_type() const {
    return "ResetResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const ResetResponse& k) {
    // the required parts of the message
    j = json{
        {"status", conversions::reset_status_to_string(k.status)},
    };
    // the optional parts of the message
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, ResetResponse& k) {
    // the required parts of the message
    k.status = conversions::string_to_reset_status(j.at("status"));

    // the optional parts of the message
}

/// \brief Writes the string representation of the given ResetResponse \p k to the given output stream \p os
/// \returns an output stream with the ResetResponse written to
std::ostream& operator<<(std::ostream& os, const ResetResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v16
} // namespace ocpp

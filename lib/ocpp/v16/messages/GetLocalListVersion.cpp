// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v16/messages/GetLocalListVersion.hpp>

#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v16 {

/**
 * GetLocalListVersionRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string GetLocalListVersionRequest::get_type() const {
    return "GetLocalListVersion";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const GetLocalListVersionRequest& k) {
    // the required parts of the message
    j = json({}, true);
    // the optional parts of the message
    (void)k; // no elements to unpack, silence unused parameter warning
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, GetLocalListVersionRequest& k) {
    // the required parts of the message

    // the optional parts of the message
    // no elements to unpack, silence unused parameter warning
    (void)j;
    (void)k;
}

/// \brief Writes the string representation of the given GetLocalListVersionRequest \p k to the given output stream \p
/// os
/// \returns an output stream with the GetLocalListVersionRequest written to
std::ostream& operator<<(std::ostream& os, const GetLocalListVersionRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * GetLocalListVersionResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string GetLocalListVersionResponse::get_type() const {
    return "GetLocalListVersionResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const GetLocalListVersionResponse& k) {
    // the required parts of the message
    j = json{
        {"listVersion", k.listVersion},
    };
    // the optional parts of the message
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, GetLocalListVersionResponse& k) {
    // the required parts of the message
    k.listVersion = j.at("listVersion");

    // the optional parts of the message
}

/// \brief Writes the string representation of the given GetLocalListVersionResponse \p k to the given output stream \p
/// os
/// \returns an output stream with the GetLocalListVersionResponse written to
std::ostream& operator<<(std::ostream& os, const GetLocalListVersionResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v16
} // namespace ocpp

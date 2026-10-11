// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v16/messages/SignedUpdateFirmware.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v16 {

/**
 * SignedUpdateFirmwareRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string SignedUpdateFirmwareRequest::get_type() const {
    return "SignedUpdateFirmware";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const SignedUpdateFirmwareRequest& k) {
    // the required parts of the message
    j = json{
        {"requestId", k.requestId},
        {"firmware", k.firmware},
    };
    // the optional parts of the message
    if (k.retries) {
        j["retries"] = k.retries.value();
    }
    if (k.retryInterval) {
        j["retryInterval"] = k.retryInterval.value();
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, SignedUpdateFirmwareRequest& k) {
    // the required parts of the message
    k.requestId = j.at("requestId");
    k.firmware = j.at("firmware");

    // the optional parts of the message
    if (j.contains("retries")) {
        k.retries.emplace(j.at("retries"));
    }
    if (j.contains("retryInterval")) {
        k.retryInterval.emplace(j.at("retryInterval"));
    }
}

/// \brief Writes the string representation of the given SignedUpdateFirmwareRequest \p k to the given output stream \p
/// os
/// \returns an output stream with the SignedUpdateFirmwareRequest written to
std::ostream& operator<<(std::ostream& os, const SignedUpdateFirmwareRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * SignedUpdateFirmwareResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string SignedUpdateFirmwareResponse::get_type() const {
    return "SignedUpdateFirmwareResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const SignedUpdateFirmwareResponse& k) {
    // the required parts of the message
    j = json{
        {"status", conversions::update_firmware_status_enum_type_to_string(k.status)},
    };
    // the optional parts of the message
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, SignedUpdateFirmwareResponse& k) {
    // the required parts of the message
    k.status = conversions::string_to_update_firmware_status_enum_type(j.at("status"));

    // the optional parts of the message
}

/// \brief Writes the string representation of the given SignedUpdateFirmwareResponse \p k to the given output stream \p
/// os
/// \returns an output stream with the SignedUpdateFirmwareResponse written to
std::ostream& operator<<(std::ostream& os, const SignedUpdateFirmwareResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v16
} // namespace ocpp

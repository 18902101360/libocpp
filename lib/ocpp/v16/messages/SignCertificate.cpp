// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v16/messages/SignCertificate.hpp>

#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v16 {

/**
 * SignCertificateRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string SignCertificateRequest::get_type() const {
    return "SignCertificate";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const SignCertificateRequest& k) {
    // the required parts of the message
    j = json{
        {"csr", k.csr},
    };
    // the optional parts of the message
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, SignCertificateRequest& k) {
    // the required parts of the message
    k.csr = j.at("csr");

    // the optional parts of the message
}

/// \brief Writes the string representation of the given SignCertificateRequest \p k to the given output stream \p os
/// \returns an output stream with the SignCertificateRequest written to
std::ostream& operator<<(std::ostream& os, const SignCertificateRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * SignCertificateResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string SignCertificateResponse::get_type() const {
    return "SignCertificateResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const SignCertificateResponse& k) {
    // the required parts of the message
    j = json{
        {"status", conversions::generic_status_enum_type_to_string(k.status)},
    };
    // the optional parts of the message
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, SignCertificateResponse& k) {
    // the required parts of the message
    k.status = conversions::string_to_generic_status_enum_type(j.at("status"));

    // the optional parts of the message
}

/// \brief Writes the string representation of the given SignCertificateResponse \p k to the given output stream \p os
/// \returns an output stream with the SignCertificateResponse written to
std::ostream& operator<<(std::ostream& os, const SignCertificateResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v16
} // namespace ocpp

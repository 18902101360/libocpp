// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v2/messages/Authorize.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v2 {

/**
 * AuthorizeRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string AuthorizeRequest::get_type() const {
    return "Authorize";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const AuthorizeRequest& k) {
    // the required parts of the message
    j = json{
        {"idToken", k.idToken},
    };
    // the optional parts of the message
    if (k.certificate) {
        j["certificate"] = k.certificate.value();
    }
    if (k.iso15118CertificateHashData) {
        j["iso15118CertificateHashData"] = json::array();
        for (const auto& val : k.iso15118CertificateHashData.value()) {
            j["iso15118CertificateHashData"].push_back(val);
        }
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
void from_json(const json& j, AuthorizeRequest& k) {
    // the required parts of the message
    k.idToken = j.at("idToken");

    // the optional parts of the message
    if (j.contains("certificate")) {
        k.certificate.emplace(j.at("certificate"));
    }
    if (j.contains("iso15118CertificateHashData")) {
        const json& arr = j.at("iso15118CertificateHashData");
        std::vector<OCSPRequestData> vec;
        for (const auto& val : arr) {
            vec.push_back(val);
        }
        k.iso15118CertificateHashData.emplace(vec);
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given AuthorizeRequest \p k to the given output stream \p os
/// \returns an output stream with the AuthorizeRequest written to
std::ostream& operator<<(std::ostream& os, const AuthorizeRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * AuthorizeResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string AuthorizeResponse::get_type() const {
    return "AuthorizeResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const AuthorizeResponse& k) {
    // the required parts of the message
    j = json{
        {"idTokenInfo", k.idTokenInfo},
    };
    // the optional parts of the message
    if (k.certificateStatus) {
        j["certificateStatus"] = conversions::authorize_certificate_status_enum_to_string(k.certificateStatus.value());
    }
    if (k.allowedEnergyTransfer) {
        j["allowedEnergyTransfer"] = json::array();
        for (const auto& val : k.allowedEnergyTransfer.value()) {
            j["allowedEnergyTransfer"].push_back(conversions::energy_transfer_mode_enum_to_string(val));
        }
    }
    if (k.tariff) {
        j["tariff"] = k.tariff.value();
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
void from_json(const json& j, AuthorizeResponse& k) {
    // the required parts of the message
    k.idTokenInfo = j.at("idTokenInfo");

    // the optional parts of the message
    if (j.contains("certificateStatus")) {
        k.certificateStatus.emplace(
            conversions::string_to_authorize_certificate_status_enum(j.at("certificateStatus")));
    }
    if (j.contains("allowedEnergyTransfer")) {
        const json& arr = j.at("allowedEnergyTransfer");
        std::vector<EnergyTransferModeEnum> vec;
        for (const auto& val : arr) {
            vec.push_back(conversions::string_to_energy_transfer_mode_enum(val));
        }
        k.allowedEnergyTransfer.emplace(vec);
    }
    if (j.contains("tariff")) {
        k.tariff.emplace(j.at("tariff"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given AuthorizeResponse \p k to the given output stream \p os
/// \returns an output stream with the AuthorizeResponse written to
std::ostream& operator<<(std::ostream& os, const AuthorizeResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v2
} // namespace ocpp

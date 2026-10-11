// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v21/messages/NotifySettlement.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v21 {

/**
 * NotifySettlementRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string NotifySettlementRequest::get_type() const {
    return "NotifySettlement";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const NotifySettlementRequest& k) {
    // the required parts of the message
    j = json{
        {"pspRef", k.pspRef},
        {"status", ocpp::v2::conversions::payment_status_enum_to_string(k.status)},
        {"settlementAmount", k.settlementAmount},
        {"settlementTime", k.settlementTime.to_rfc3339()},
    };
    // the optional parts of the message
    if (k.transactionId) {
        j["transactionId"] = k.transactionId.value();
    }
    if (k.statusInfo) {
        j["statusInfo"] = k.statusInfo.value();
    }
    if (k.receiptId) {
        j["receiptId"] = k.receiptId.value();
    }
    if (k.receiptUrl) {
        j["receiptUrl"] = k.receiptUrl.value();
    }
    if (k.vatCompany) {
        j["vatCompany"] = k.vatCompany.value();
    }
    if (k.vatNumber) {
        j["vatNumber"] = k.vatNumber.value();
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
void from_json(const json& j, NotifySettlementRequest& k) {
    // the required parts of the message
    k.pspRef = j.at("pspRef");
    k.status = ocpp::v2::conversions::string_to_payment_status_enum(j.at("status"));
    k.settlementAmount = j.at("settlementAmount");
    k.settlementTime = ocpp::DateTime(std::string(j.at("settlementTime")));

    // the optional parts of the message
    if (j.contains("transactionId")) {
        k.transactionId.emplace(j.at("transactionId"));
    }
    if (j.contains("statusInfo")) {
        k.statusInfo.emplace(j.at("statusInfo"));
    }
    if (j.contains("receiptId")) {
        k.receiptId.emplace(j.at("receiptId"));
    }
    if (j.contains("receiptUrl")) {
        k.receiptUrl.emplace(j.at("receiptUrl"));
    }
    if (j.contains("vatCompany")) {
        k.vatCompany.emplace(j.at("vatCompany"));
    }
    if (j.contains("vatNumber")) {
        k.vatNumber.emplace(j.at("vatNumber"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given NotifySettlementRequest \p k to the given output stream \p os
/// \returns an output stream with the NotifySettlementRequest written to
std::ostream& operator<<(std::ostream& os, const NotifySettlementRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * NotifySettlementResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string NotifySettlementResponse::get_type() const {
    return "NotifySettlementResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const NotifySettlementResponse& k) {
    // the required parts of the message
    j = json({}, true);
    // the optional parts of the message
    if (k.receiptUrl) {
        j["receiptUrl"] = k.receiptUrl.value();
    }
    if (k.receiptId) {
        j["receiptId"] = k.receiptId.value();
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
void from_json(const json& j, NotifySettlementResponse& k) {
    // the required parts of the message

    // the optional parts of the message
    if (j.contains("receiptUrl")) {
        k.receiptUrl.emplace(j.at("receiptUrl"));
    }
    if (j.contains("receiptId")) {
        k.receiptId.emplace(j.at("receiptId"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given NotifySettlementResponse \p k to the given output stream \p os
/// \returns an output stream with the NotifySettlementResponse written to
std::ostream& operator<<(std::ostream& os, const NotifySettlementResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v21
} // namespace ocpp

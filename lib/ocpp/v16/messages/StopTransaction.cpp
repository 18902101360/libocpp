// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v16/messages/StopTransaction.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v16 {

/**
 * StopTransactionRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string StopTransactionRequest::get_type() const {
    return "StopTransaction";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const StopTransactionRequest& k) {
    // the required parts of the message
    j = json{
        {"meterStop", k.meterStop},
        {"timestamp", k.timestamp.to_rfc3339()},
        {"transactionId", k.transactionId},
    };
    // the optional parts of the message
    if (k.idTag) {
        j["idTag"] = k.idTag.value();
    }
    if (k.reason) {
        j["reason"] = conversions::reason_to_string(k.reason.value());
    }
    if (k.transactionData) {
        j["transactionData"] = json::array();
        for (const auto& val : k.transactionData.value()) {
            j["transactionData"].push_back(val);
        }
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, StopTransactionRequest& k) {
    // the required parts of the message
    k.meterStop = j.at("meterStop");
    k.timestamp = ocpp::DateTime(std::string(j.at("timestamp")));
    k.transactionId = j.at("transactionId");

    // the optional parts of the message
    if (j.contains("idTag")) {
        k.idTag.emplace(j.at("idTag"));
    }
    if (j.contains("reason")) {
        k.reason.emplace(conversions::string_to_reason(j.at("reason")));
    }
    if (j.contains("transactionData")) {
        const json& arr = j.at("transactionData");
        std::vector<TransactionData> vec;
        for (const auto& val : arr) {
            vec.push_back(val);
        }
        k.transactionData.emplace(vec);
    }
}

/// \brief Writes the string representation of the given StopTransactionRequest \p k to the given output stream \p os
/// \returns an output stream with the StopTransactionRequest written to
std::ostream& operator<<(std::ostream& os, const StopTransactionRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * StopTransactionResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string StopTransactionResponse::get_type() const {
    return "StopTransactionResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const StopTransactionResponse& k) {
    // the required parts of the message
    j = json({}, true);
    // the optional parts of the message
    if (k.idTagInfo) {
        j["idTagInfo"] = k.idTagInfo.value();
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, StopTransactionResponse& k) {
    // the required parts of the message

    // the optional parts of the message
    if (j.contains("idTagInfo")) {
        k.idTagInfo.emplace(j.at("idTagInfo"));
    }
}

/// \brief Writes the string representation of the given StopTransactionResponse \p k to the given output stream \p os
/// \returns an output stream with the StopTransactionResponse written to
std::ostream& operator<<(std::ostream& os, const StopTransactionResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v16
} // namespace ocpp

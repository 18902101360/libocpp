// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v16/messages/DataTransfer.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v16 {

/**
 * DataTransferRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string DataTransferRequest::get_type() const {
    return "DataTransfer";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const DataTransferRequest& k) {
    // the required parts of the message
    j = json{
        {"vendorId", k.vendorId},
    };
    // the optional parts of the message
    if (k.messageId) {
        j["messageId"] = k.messageId.value();
    }
    if (k.data) {
        j["data"] = k.data.value();
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, DataTransferRequest& k) {
    // the required parts of the message
    k.vendorId = j.at("vendorId");

    // the optional parts of the message
    if (j.contains("messageId")) {
        k.messageId.emplace(j.at("messageId"));
    }
    if (j.contains("data")) {
        k.data.emplace(j.at("data"));
    }
}

/// \brief Writes the string representation of the given DataTransferRequest \p k to the given output stream \p os
/// \returns an output stream with the DataTransferRequest written to
std::ostream& operator<<(std::ostream& os, const DataTransferRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * DataTransferResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string DataTransferResponse::get_type() const {
    return "DataTransferResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const DataTransferResponse& k) {
    // the required parts of the message
    j = json{
        {"status", conversions::data_transfer_status_to_string(k.status)},
    };
    // the optional parts of the message
    if (k.data) {
        j["data"] = k.data.value();
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, DataTransferResponse& k) {
    // the required parts of the message
    k.status = conversions::string_to_data_transfer_status(j.at("status"));

    // the optional parts of the message
    if (j.contains("data")) {
        k.data.emplace(j.at("data"));
    }
}

/// \brief Writes the string representation of the given DataTransferResponse \p k to the given output stream \p os
/// \returns an output stream with the DataTransferResponse written to
std::ostream& operator<<(std::ostream& os, const DataTransferResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v16
} // namespace ocpp

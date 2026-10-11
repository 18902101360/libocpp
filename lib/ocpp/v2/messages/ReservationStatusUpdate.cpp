// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v2/messages/ReservationStatusUpdate.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v2 {

/**
 * ReservationStatusUpdateRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string ReservationStatusUpdateRequest::get_type() const {
    return "ReservationStatusUpdate";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const ReservationStatusUpdateRequest& k) {
    // the required parts of the message
    j = json{
        {"reservationId", k.reservationId},
        {"reservationUpdateStatus", conversions::reservation_update_status_enum_to_string(k.reservationUpdateStatus)},
    };
    // the optional parts of the message
    if (k.customData) {
        j["customData"] = k.customData.value();
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, ReservationStatusUpdateRequest& k) {
    // the required parts of the message
    k.reservationId = j.at("reservationId");
    k.reservationUpdateStatus = conversions::string_to_reservation_update_status_enum(j.at("reservationUpdateStatus"));

    // the optional parts of the message
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given ReservationStatusUpdateRequest \p k to the given output stream
/// \p os
/// \returns an output stream with the ReservationStatusUpdateRequest written to
std::ostream& operator<<(std::ostream& os, const ReservationStatusUpdateRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * ReservationStatusUpdateResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string ReservationStatusUpdateResponse::get_type() const {
    return "ReservationStatusUpdateResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const ReservationStatusUpdateResponse& k) {
    // the required parts of the message
    j = json({}, true);
    // the optional parts of the message
    if (k.customData) {
        j["customData"] = k.customData.value();
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, ReservationStatusUpdateResponse& k) {
    // the required parts of the message

    // the optional parts of the message
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given ReservationStatusUpdateResponse \p k to the given output stream
/// \p os
/// \returns an output stream with the ReservationStatusUpdateResponse written to
std::ostream& operator<<(std::ostream& os, const ReservationStatusUpdateResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v2
} // namespace ocpp

// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest

#include <ocpp/common/call_types.hpp>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace ocpp {

/**
 * create_message_id - create message id
 *
 * 返回 MessageId。
 */
MessageId create_message_id() {
    static boost::uuids::random_generator uuid_generator;
    const boost::uuids::uuid uuid = uuid_generator();
    std::stringstream s;
    s << uuid;
    return MessageId(s.str());
}

/**
 * operator< - 供日志或容器使用的比较、输出运算符。
 * @lhs: 传入的 lhs
 * @rhs: 传入的 rhs
 *
 * 返回 bool。
 */
bool operator<(const MessageId& lhs, const MessageId& rhs) {
    return lhs.get() < rhs.get();
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const MessageId& k) {
    j = json(k.get());
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, MessageId& k) {
    k.set(j);
}

} // namespace ocpp

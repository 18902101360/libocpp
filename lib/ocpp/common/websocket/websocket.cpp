// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest
#include <everest/logging.hpp>

#include <ocpp/common/websocket/websocket.hpp>
#include <ocpp/v16/types.hpp>

#include <ocpp/common/websocket/websocket_libwebsockets.hpp>

#include <boost/algorithm/string.hpp>

using json = nlohmann::json;

namespace ocpp {

Websocket::Websocket(const WebsocketConnectionOptions& connection_options, std::shared_ptr<EvseSecurity> evse_security,
                     std::shared_ptr<MessageLogging> logging) :
    logging(logging) {
    this->websocket = std::make_unique<WebsocketLibwebsockets>(connection_options, evse_security);
}

/**
 * Websocket::start_connecting - start connecting
 *
 * 返回 bool。
 */
bool Websocket::start_connecting() {
    this->logging->sys("Connecting");
    return this->websocket->start_connecting();
}

/**
 * Websocket::set_connection_options - set connection options
 * @connection_options: 传入的 connection_options
 */
void Websocket::set_connection_options(const WebsocketConnectionOptions& connection_options) {
    this->websocket->set_connection_options(connection_options);
}

/**
 * Websocket::disconnect - disconnect
 * @code: 传入的 code
 */
void Websocket::disconnect(const WebsocketCloseReason code) {
    this->logging->sys("Disconnecting");
    this->websocket->disconnect(code);
}

/**
 * Websocket::reconnect - reconnect
 * @delay: 传入的 delay
 */
void Websocket::reconnect(long delay) {
    this->logging->sys("Reconnecting");
    this->websocket->reconnect(delay);
}

/**
 * Websocket::is_connected - is connected
 *
 * 返回 bool。
 */
bool Websocket::is_connected() {
    return this->websocket->is_connected();
}

/**
 * Websocket::register_connected_callback - register connected callback
 * @callback: 传入的 callback
 */
void Websocket::register_connected_callback(const std::function<void(OcppProtocolVersion protocol)>& callback) {
    this->connected_callback = callback;

    this->websocket->register_connected_callback([this](OcppProtocolVersion protocol) {
        this->logging->sys("Connected");
        this->connected_callback(protocol);
    });
}

/**
 * Websocket::register_disconnected_callback - register disconnected callback
 * @callback: 传入的 callback
 */
void Websocket::register_disconnected_callback(const std::function<void()>& callback) {
    this->disconnected_callback = callback;

    this->websocket->register_disconnected_callback([this]() {
        this->logging->sys("Disconnected");
        this->disconnected_callback();
    });
}

/**
 * Websocket::register_stopped_connecting_callback - register stopped connecting callback
 * @callback: 传入的 callback
 */
void Websocket::register_stopped_connecting_callback(
    const std::function<void(const WebsocketCloseReason reason)>& callback) {
    this->stopped_connecting_callback = callback;
    this->websocket->register_stopped_connecting_callback(
        [this](const WebsocketCloseReason reason) { this->stopped_connecting_callback(reason); });
}

/**
 * Websocket::register_message_callback - register message callback
 * @callback: 传入的 callback
 */
void Websocket::register_message_callback(const std::function<void(const std::string& message)>& callback) {
    this->message_callback = callback;

    this->websocket->register_message_callback([this](const std::string& message) { this->message_callback(message); });
}

/**
 * Websocket::register_connection_failed_callback - register connection failed callback
 * @callback: 传入的 callback
 */
void Websocket::register_connection_failed_callback(const std::function<void(ConnectionFailedReason)>& callback) {
    this->websocket->register_connection_failed_callback(callback);
}

/**
 * Websocket::send - send
 * @message: 已经组好的 JSON 报文
 *
 * 返回 bool。
 */
bool Websocket::send(const std::string& message) {
    this->logging->raw(message, LogType::ChargePoint);
    this->logging->charge_point("Unknown", message);
    return this->websocket->send(message);
}

/**
 * Websocket::set_websocket_ping_interval - set websocket ping interval
 * @ping_interval_s: 传入的 ping_interval_s
 * @pong_interval_s: 传入的 pong_interval_s
 */
void Websocket::set_websocket_ping_interval(std::int32_t ping_interval_s, std::int32_t pong_interval_s) {
    this->logging->sys("WebSocketPingInterval changed");
    this->websocket->set_websocket_ping_interval(ping_interval_s, pong_interval_s);
}

/**
 * Websocket::set_authorization_key - set authorization key
 * @authorization_key: 传入的 authorization_key
 */
void Websocket::set_authorization_key(const std::string& authorization_key) {
    this->websocket->set_authorization_key(authorization_key);
}

} // namespace ocpp

// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest

#include <ocpp/v2/database_handler.hpp>
#include <ocpp/v2/transaction.hpp>

using QueryExecutionException = everest::db::QueryExecutionException;

namespace ocpp {

namespace v2 {

/**
 * EnhancedTransaction::get_transaction - get transaction
 *
 * 返回 Transaction。
 */
Transaction EnhancedTransaction::get_transaction() {
    Transaction transaction;
    transaction.transactionId = this->transactionId;
    transaction.chargingState = this->chargingState;
    transaction.timeSpentCharging = this->timeSpentCharging;
    transaction.stoppedReason = this->stoppedReason;
    transaction.remoteStartId = this->remoteStartId;
    return transaction;
}

/**
 * EnhancedTransaction::get_seq_no - get seq no
 *
 * 返回 std::int32_t。
 */
std::int32_t EnhancedTransaction::get_seq_no() {
    this->seq_no += 1;
    if (this->database_enabled) {
        try {
            this->database_handler.transaction_update_seq_no(this->transactionId, this->seq_no);
        } catch (const QueryExecutionException& e) {
            EVLOG_error << "Can't update transaction: " << e.what();
        }
    }
    return this->seq_no - 1;
}

/**
 * EnhancedTransaction::update_charging_state - update charging state
 * @charging_state: 传入的 charging_state
 */
void EnhancedTransaction::update_charging_state(const ChargingStateEnum charging_state) {
    this->chargingState = charging_state;
    if (this->database_enabled) {
        try {
            this->database_handler.transaction_update_charging_state(this->transactionId, charging_state);
        } catch (const QueryExecutionException& e) {
            EVLOG_error << "Can't update transaction: " << e.what();
        }
    }
}

/**
 * EnhancedTransaction::set_id_token_sent - set id token sent
 */
void EnhancedTransaction::set_id_token_sent() {
    this->id_token_sent = true;
    if (this->database_enabled) {
        try {
            this->database_handler.transaction_update_id_token_sent(this->transactionId, this->id_token_sent);
        } catch (const QueryExecutionException& e) {
            EVLOG_error << "Can't update transaction: " << e.what();
        }
    }
}

} // namespace v2

} // namespace ocpp

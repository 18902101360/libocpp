from __future__ import annotations

from ocpp_csms.handlers.base import empty
from ocpp_csms.handlers.v201 import authorize as az
from ocpp_csms.handlers.v201 import boot as boot_mod
from ocpp_csms.handlers.v201 import heartbeat as hb
from ocpp_csms.handlers.v201 import station as st

EMPTY_ACTIONS = (
    "ClearedChargingLimit",
    "FirmwareStatusNotification",
    "LogStatusNotification",
    "MeterValues",
    "NotifyChargingLimit",
    "NotifyCustomerInformation",
    "NotifyDisplayMessages",
    "NotifyEVChargingNeeds",
    "NotifyEVChargingSchedule",
    "NotifyEvent",
    "NotifyMonitoringReport",
    "NotifyReport",
    "PublishFirmwareStatusNotification",
    "ReportChargingProfiles",
    "ReservationStatusUpdate",
    "SecurityEventNotification",
)


def data_transfer(session, payload):
    session.log("dataTransfer 2.0.1", session.cp_id, payload.get("vendorId"))
    return {"status": "Accepted"}


def sign_certificate(session, _payload):
    return {"status": "Accepted"}


def get15118(session, _payload):
    return {"status": "Accepted", "exiResponse": ""}


def get_certificate_status(session, _payload):
    return {"status": "Accepted"}


def registry() -> dict:
    handlers = {
        "BootNotification": boot_mod.boot,
        "Authorize": az.authorize,
        "Heartbeat": hb.heartbeat,
        "TransactionEvent": st.transaction_event,
        "StatusNotification": st.status_notification,
        "DataTransfer": data_transfer,
        "SignCertificate": sign_certificate,
        "Get15118EVCertificate": get15118,
        "GetCertificateStatus": get_certificate_status,
        "*": empty,
    }
    for name in EMPTY_ACTIONS:
        handlers[name] = empty
    return handlers

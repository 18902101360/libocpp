from __future__ import annotations

from ocpp_csms.handlers.base import empty
from ocpp_csms.handlers.v16 import authorize as az
from ocpp_csms.handlers.v16 import boot as boot_mod
from ocpp_csms.handlers.v16 import heartbeat as hb
from ocpp_csms.handlers.v16 import status as st
from ocpp_csms.handlers.v16 import transaction as tx
from ocpp_csms.handlers.v16.defaults import data_transfer, sign_certificate

EMPTY_ACTIONS = (
    "DiagnosticsStatusNotification",
    "FirmwareStatusNotification",
    "LogStatusNotification",
    "SecurityEventNotification",
    "SignedFirmwareStatusNotification",
)


def registry() -> dict:
    handlers = {
        "BootNotification": boot_mod.boot,
        "Authorize": az.authorize,
        "Heartbeat": hb.heartbeat,
        "StartTransaction": tx.start_transaction,
        "StopTransaction": tx.stop_transaction,
        "StatusNotification": st.status_notification,
        "MeterValues": st.meter_values,
        "DataTransfer": data_transfer,
        "SignCertificate": sign_certificate,
        "*": empty,
    }
    for name in EMPTY_ACTIONS:
        handlers[name] = empty
    return handlers

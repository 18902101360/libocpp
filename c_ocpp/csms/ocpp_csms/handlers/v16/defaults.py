from __future__ import annotations

from typing import Any

from ocpp_csms.handlers.base import SessionView


def data_transfer(session: SessionView, payload: dict[str, Any]) -> dict[str, Any]:
    session.log("dataTransfer 1.6", session.cp_id, payload.get("vendorId"))
    return {"status": "Accepted"}


def sign_certificate(session: SessionView, _payload: dict[str, Any]) -> dict[str, Any]:
    session.log("signCertificate 1.6", session.cp_id)
    return {"status": "Accepted"}

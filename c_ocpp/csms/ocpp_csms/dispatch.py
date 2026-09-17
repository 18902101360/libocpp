from __future__ import annotations

from ocpp_csms.handlers.base import Handler
from ocpp_csms.handlers.v16 import registry as registry_v16
from ocpp_csms.handlers.v201 import registry as registry_v201


class Dispatcher:
    def __init__(self, protocol: str) -> None:
        if protocol == "ocpp2.0.1":
            self._handlers = registry_v201()
        else:
            self._handlers = registry_v16()

    def handle(self, session, action: str, payload: dict) -> dict:
        fn: Handler = self._handlers.get(action) or self._handlers["*"]
        return fn(session, payload if isinstance(payload, dict) else {})

from __future__ import annotations

from dataclasses import dataclass


PROTO_16 = "ocpp1.6"
PROTO_201 = "ocpp2.0.1"
SUPPORTED = (PROTO_16, PROTO_201)


@dataclass
class CsmsConfig:
    host: str = "0.0.0.0"
    port: int = 9000
    heartbeat_interval: int = 300
    send_reset_after_boot: bool = True
    log_frames: bool = True

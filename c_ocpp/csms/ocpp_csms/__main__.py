from __future__ import annotations

import argparse

from ocpp_csms.config import CsmsConfig
from ocpp_csms.server import run_server


def main() -> None:
    p = argparse.ArgumentParser(description="Modular OCPP 1.6 / 2.0.1 CSMS (WebSocket)")
    p.add_argument("--host", default="0.0.0.0")
    p.add_argument("--port", type=int, default=9000)
    p.add_argument("--interval", type=int, default=300, help="BootNotification.conf interval seconds")
    p.add_argument("--no-reset", action="store_true", help="do not send Reset after Boot")
    p.add_argument("--quiet", action="store_true")
    args = p.parse_args()
    cfg = CsmsConfig(
        host=args.host,
        port=args.port,
        heartbeat_interval=args.interval,
        send_reset_after_boot=not args.no_reset,
        log_frames=not args.quiet,
    )
    run_server(cfg)


if __name__ == "__main__":
    main()

#ifndef WS_CLIENT_H
#define WS_CLIENT_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int fd;
} ws_conn_t;

int ws_connect(ws_conn_t *c, const char *host, int port, const char *path, const char *subprotocol);
int ws_send_text(ws_conn_t *c, const void *data, size_t len);
/* timeout_ms: 0 = wait forever. Returns bytes, 0 on timeout, -1 on error/close. */
int ws_recv_text(ws_conn_t *c, char *buf, size_t buflen, int timeout_ms);
void ws_close(ws_conn_t *c);

#ifdef __cplusplus
}
#endif

#endif

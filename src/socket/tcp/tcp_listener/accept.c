/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** accept
*/

#include <errno.h>
#include <string.h>
#include <sys/socket.h>

#include <error.h>
#include <tcp_listener.h>

socket_status_t tcp_listener_accept(
    tcp_listener_t *listener, tcp_socket_t **connected)
{
    struct sockaddr_in address;
    socklen_t len = sizeof(address);
    fd_t sock = 0;

    if (!listener || listener->socket < 0 || !connected) {
        set_error(
            "tcp_listener_accept: listener and connected must not be null.");
        return SOCKET_ERROR;
    }
    if (!*connected)
        *connected = tcp_socket_create_empty();
    if (!*connected)
        return SOCKET_ERROR;
    if ((sock = accept(listener->socket, (struct sockaddr *)&address, &len)) ==
        -1) {
        set_error(strerror(errno));
        return SOCKET_ERROR;
    }
    tcp_socket_disconnect(*connected);
    (*connected)->socket = sock;
    return SOCKET_DONE;
}

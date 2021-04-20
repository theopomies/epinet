/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** receive
*/

#include <errno.h>
#include <string.h>
#include <unistd.h>

#include <error.h>
#include <tcp_socket.h>

socket_status_t tcp_socket_receive(
    tcp_socket_t *socket, void *data, size_t size, size_t *received)
{
    int rec = 0;

    if (!socket || socket->socket < 0) {
        set_error("tcp_socket_send_partial: socket cannot be NULL or < 0.");
        return SOCKET_ERROR;
    }
    if (!size)
        return SOCKET_DONE;
    if (!data) {
        set_error("tcp_socket_receive: data cannot be NULL.");
        return SOCKET_ERROR;
    }
    rec = read(socket->socket, data, size);
    if (rec > 0) {
        if (received)
            *received = rec;
        return (size_t)rec == size ? SOCKET_PARTIAL : SOCKET_DONE;
    }
    if (rec == 0)
        return SOCKET_DISCONNECTED;
    return socket_get_status();
}

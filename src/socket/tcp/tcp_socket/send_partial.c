/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** send_partial
*/

#include <errno.h>
#include <string.h>
#include <unistd.h>

#include <error.h>
#include <tcp_socket.h>

socket_status_t tcp_socket_send_partial(
    tcp_socket_t *socket, const void *data, size_t size, size_t *sent)
{
    size_t written = 0;

    if (!socket || socket->socket < 0) {
        set_error("tcp_socket_send_partial: socket cannot be NULL or < 0.");
        return SOCKET_ERROR;
    }
    if (!size)
        return SOCKET_DONE;
    if (!data || !sent) {
        set_error("tcp_socket_send_partial: data and sent cant be NULL.");
        return SOCKET_ERROR;
    }
    written = write(socket->socket, data, size);
    if (written > 0) {
        if (sent)
            *sent = written;
        return written == size ? SOCKET_DONE : SOCKET_PARTIAL;
    }
    return socket_get_status();
}

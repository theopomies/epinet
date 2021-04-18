/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** send
*/

#include <errno.h>
#include <string.h>
#include <unistd.h>

#include <error.h>
#include <tcp_socket.h>

socket_status_t tcp_socket_send(
    tcp_socket_t *socket, const void *data, size_t size)
{
    size_t total = 0;
    size_t sent = 0;
    socket_status_t status = SOCKET_PARTIAL;

    while (status == SOCKET_PARTIAL) {
        status =
            tcp_socket_send_partial(socket, data + total, size - total, &sent);
        total += sent;
    }
    return status;
}

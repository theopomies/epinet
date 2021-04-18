/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** get_status
*/

#include <errno.h>
#include <string.h>

#include <error.h>
#include <socket.h>

socket_status_t socket_get_status(void)
{
    set_error(strerror(errno));
    switch (errno) {
        case EWOULDBLOCK:
            return SOCKET_NOT_READY;
        case ECONNRESET:
            return SOCKET_DISCONNECTED;
        case EDESTADDRREQ:
            return SOCKET_DISCONNECTED;
        case ENOTCONN:
            return SOCKET_DISCONNECTED;
        default:
            return SOCKET_ERROR;
    }
    return SOCKET_ERROR;
}

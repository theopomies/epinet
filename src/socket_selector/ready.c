/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** ready
*/

#include <stdbool.h>

#include <error.h>
#include <socket_selector.h>

bool socket_selector_is_socket_ready(
    const socket_selector_t *selector, socket_t *socket)
{
    if (!selector) {
        set_error(
            "socket_selector_is_socket_ready: given selector cannot be NULL");
        return false;
    }
    if (!socket) {
        set_error(
            "socket_selector_is_socket_ready: given socket cannot be NULL");
        return false;
    }
    return FD_ISSET(socket->socket, &selector->ready);
}

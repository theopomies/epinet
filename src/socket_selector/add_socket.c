/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** socket_selector_add_socket
*/

#include <error.h>
#include <socket_selector.h>

selector_status_t socket_selector_add_socket(
    socket_selector_t *selector, socket_t *socket)
{
    if (!selector) {
        set_error("socket_selector_add_socket: given selector cannot be NULL");
        return SELECTOR_ERROR;
    }
    if (!socket) {
        set_error("socket_selector_add_socket: given socket cannot be NULL");
        return SELECTOR_ERROR;
    }
    FD_SET(socket->socket, &selector->master);
    if (socket->socket > selector->max_socket)
        selector->max_socket = socket->socket;
    return SELECTOR_OK;
}

/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** remove_socket
*/

#include <socket_selector.h>
#include <error.h>

selector_status_t socket_selector_remove_socket(
    socket_selector_t *selector, socket_t *socket)
{
    fd_t new_max = 0;

    if (!selector) {
        set_error(
            "socket_selector_remove_socket: given selector cannot be NULL");
        return SELECTOR_ERROR;
    }
    if (!socket) {
        set_error("socket_selector_remove_socket: given socket cannot be NULL");
        return SELECTOR_ERROR;
    }
    FD_CLR(socket->socket, &selector->master);
    for (fd_t fd = new_max; fd <= selector->max_socket; ++fd) {
        if (FD_ISSET(fd, &selector->master))
            new_max = fd;
    }
    return SELECTOR_OK;
}

/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** clear
*/

#include <error.h>
#include <socket_selector.h>

selector_status_t socket_selector_clear(socket_selector_t *selector)
{
    if (!selector) {
        set_error("socket_selector_clear: given selector cannot be NULL");
        return SELECTOR_ERROR;
    }
    FD_ZERO(&selector->master);
    FD_ZERO(&selector->ready);
    selector->max_socket = NO_SOCKET;
    return SELECTOR_OK;
}

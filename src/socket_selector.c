/*
** EPITECH PROJECT, 2021
** Epinet
** File description:
** socket_selector
*/

#include <errno.h>
#include <stdlib.h>

#include <error.h>
#include <socket_selector.h>
#include <string.h>

socket_selector_t *socket_selector_create(void)
{
    socket_selector_t *selector = malloc(sizeof(socket_selector_t));

    if (!selector) {
        set_error("socket_selector_create: malloc error");
        return NULL;
    }
    socket_selector_clear(selector);
    return selector;
}

socket_selector_t *socket_selector_copy(const socket_selector_t *selector)
{
    socket_selector_t *new_selector = socket_selector_create();

    if (!new_selector)
        return NULL;
    if (!selector)
        return new_selector;
    memcpy(new_selector, selector, sizeof(socket_selector_t));
    return new_selector;
}

void socket_selector_destroy(socket_selector_t *selector)
{
    if (selector)
        free(selector);
}

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

selector_status_t socket_selector_wait(
    socket_selector_t *selector, timeout_t timeout, watch_t watch)
{
    struct timeval timeval;
    struct timeval *timeval_ptr = timeout == NO_TIMEOUT ? NULL : &timeval;
    fd_set *readfds;
    fd_set *writefds;
    fd_set *exceptfds;
    selector_status_t status = SELECTOR_OK;

    timeval.tv_sec = timeout / 1000;
    timeval.tv_usec = timeout * 1000;
    if (!selector) {
        set_error("socket_selector_wait: given selector cannot be NULL");
        return SELECTOR_ERROR;
    }
    selector->ready = selector->master;
    readfds = watch & WATCH_RD ? &selector->ready : NULL;
    writefds = watch & WATCH_WRT ? &selector->ready : NULL;
    exceptfds = watch & WATCH_EXC ? &selector->ready : NULL;
    if (status = select(selector->max_socket + 1, readfds, writefds, exceptfds,
                     timeval_ptr) == SELECTOR_ERROR)
        set_error(strerror(errno));
    return status;
}

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
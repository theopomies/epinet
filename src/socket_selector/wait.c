/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** wait
*/

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include <error.h>
#include <socket_selector.h>

static selector_status_t call_select(
    socket_selector_t *selector, struct timeval *timeval_ptr, watch_t watch)
{
    fd_set *readfds;
    fd_set *writefds;
    fd_set *exceptfds;
    selector_status_t status = SELECTOR_OK;

    readfds = watch & WATCH_RD ? &selector->ready : NULL;
    writefds = watch & WATCH_WRT ? &selector->ready : NULL;
    exceptfds = watch & WATCH_EXC ? &selector->ready : NULL;
handle_select_signal:
    if ((status = select(selector->max_socket + 1, readfds, writefds, exceptfds,
             timeval_ptr)) == SELECTOR_ERROR) {
        if (errno == EINTR)
            goto handle_select_signal;
        set_error(strerror(errno));
    }
    return status;
}

selector_status_t socket_selector_wait(
    socket_selector_t *selector, timeout_t timeout, watch_t watch)
{
    struct timeval timeval;
    struct timeval *timeval_ptr = timeout == NO_TIMEOUT ? NULL : &timeval;

    timeval.tv_sec = timeout / 1000;
    timeval.tv_usec = timeout * 1000;
    if (!selector) {
        set_error("socket_selector_wait: given selector cannot be NULL");
        return SELECTOR_ERROR;
    }
    selector->ready = selector->master;
    return call_select(selector, timeval_ptr, watch);
}

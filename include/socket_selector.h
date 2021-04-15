/*
** EPITECH PROJECT, 2021
** Epinet
** File description:
** socket_selector
*/

#ifndef SOCKET_SELECTOR_H_
#define SOCKET_SELECTOR_H_

#include <sys/select.h>

#include <tcp_listener.h>
#include <tcp_socket.h>
#include <timeout.h>
#include <udp_socket.h>

typedef struct
{
    fd_set master;
    fd_set ready;
    fd_t max_socket;
} socket_selector_t;

socket_selector_t *socket_selector_create(void);
socket_selector_t *socket_selector_copy(const socket_selector_t *selector);
void socket_selector_destroy(socket_selector_t *selector);

void socket_selector_add_socket(socket_selector_t *selector, socket_t *socket);
void socket_selector_remove_socket(
    socket_selector_t *selector, socket_t *socket);

void socket_selector_clear(socket_selector_t *selector);
bool socket_selector_wait(socket_selector_t *selector, timeout_t timeout);

bool socket_selector_is_socket_ready(
    const socket_selector_t *selector, socket_t *socket);

#endif /* !SOCKET_SELECTOR_H_ */

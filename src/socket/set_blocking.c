/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** set_blocking
*/

#include <socket.h>

void socket_set_blocking(socket_t *sock, bool blocking)
{
    if (!sock)
        return;
    sock->is_blocking = blocking;
}

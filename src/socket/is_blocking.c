/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** is_blocking
*/

#include <socket.h>

bool socket_is_blocking(socket_t *sock)
{
    return !!sock && sock->is_blocking;
}

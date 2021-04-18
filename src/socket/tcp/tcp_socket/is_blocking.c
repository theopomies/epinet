/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** is_blocking
*/

#include <tcp_socket.h>

bool tcp_socket_is_blocking(const tcp_socket_t *socket)
{
    return socket_is_blocking(SOCKET(socket));
}

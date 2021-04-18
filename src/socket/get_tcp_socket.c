/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** get_tcp_socket
*/

#include <tcp_socket.h>

tcp_socket_t *socket_get_tcp_socket(socket_t *socket)
{
    if (socket->type == SOCKET_TCP)
        return (tcp_socket_t *)socket;
    return NULL;
}

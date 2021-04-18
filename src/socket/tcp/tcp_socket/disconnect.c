/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** disconnect
*/

#include <unistd.h>

#include <tcp_socket.h>

void tcp_socket_disconnect(tcp_socket_t *socket)
{
    if (!socket || socket->socket < 0)
        return;
    close(socket->socket);
    socket->socket = NO_SOCKET;
}

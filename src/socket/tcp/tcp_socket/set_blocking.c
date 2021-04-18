/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** set_blocking
*/

#include <tcp_socket.h>

void tcp_socket_set_blocking(tcp_socket_t *socket, bool blocking)
{
    socket_set_blocking(SOCKET(socket), blocking);
}

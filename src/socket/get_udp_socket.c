/*
** EPITECH PROJECT, 2021
** $
** File description:
** get_udp_socket
*/

#include <udp_socket.h>

udp_socket_t *socket_get_udp_socket(socket_t *socket)
{
    if (socket->type == SOCKET_UDP)
        return (udp_socket_t *)socket;
    return NULL;
}

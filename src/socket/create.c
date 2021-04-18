/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** create
*/

#include <stdlib.h>
#include <sys/socket.h>

#include <error.h>
#include <socket.h>

socket_t *socket_create(socket_type_t type)
{
    socket_t *sock = socket_create_empty(type);

    if (!sock)
        return NULL;
    sock->socket = socket(AF_INET, type, 0);
    if (sock->socket == NO_SOCKET) {
        free(sock);
        set_error("socket_create: socket syscall");
        return NULL;
    }
    return sock;
}

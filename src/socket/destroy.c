/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** destroy
*/

#include <stdlib.h>
#include <unistd.h>

#include <socket.h>

void socket_destroy(socket_t *sock)
{
    if (!sock)
        return;
    if (sock->socket != NO_SOCKET)
        close(sock->socket);
    free(sock);
}

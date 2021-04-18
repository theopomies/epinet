/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** create_empty
*/

#include <stdlib.h>

#include <error.h>
#include <socket.h>

socket_t *socket_create_empty(socket_type_t type)
{
    socket_t *socket = NULL;

    if (!(socket = malloc(sizeof(socket_t)))) {
        set_error("socket_create_empty: malloc error.");
        return NULL;
    }
    socket->is_blocking = true;
    socket->type = type;
    socket->socket = NO_SOCKET;
    return socket;
}

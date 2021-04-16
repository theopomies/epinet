/*
** EPITECH PROJECT, 2021
** Epinet
** File description:
** socket
*/

#ifndef SOCKET_H_
#define SOCKET_H_

#include <netinet/ip.h>
#include <stdbool.h>
#include <sys/types.h>

typedef int fd_t;

#define SOCKET(socket) ((socket_t *)socket)
#define NO_SOCKET -1

typedef enum
{
    SOCKET_TCP = SOCK_STREAM,
    SOCKET_UDP = SOCK_DGRAM
} socket_type_t;

typedef enum
{
    SOCKET_ERROR = -1,
    SOCKET_DONE,
    SOCKET_NOT_READY,
    SOCKET_PARTIAL,
    SOCKET_DISCONNECTED,
} socket_status_t;

typedef struct
{
    socket_type_t type;
    fd_t socket;
    bool is_blocking;
} socket_t;

socket_t *socket_create(socket_type_t type);
socket_t *socket_create_empty(socket_type_t type);
void socket_destroy();

void socket_set_blocking(socket_t *sock, bool blocking);
bool socket_is_blocking(socket_t *sock);

#endif /* !SOCKET_H_ */

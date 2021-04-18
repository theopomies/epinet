/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** connect
*/

#include <errno.h>
#include <netinet/ip.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <error.h>
#include <tcp_socket.h>

socket_status_t tcp_socket_connect(tcp_socket_t *socket,
    ip_address_t remote_address, unsigned short remote_port)
{
    struct sockaddr_in address;

    if (!socket || socket->socket < 0) {
        set_error("tcp_socket_connect: socket cannot be NULL.");
        return SOCKET_ERROR;
    }
    address.sin_port = htons(remote_port);
    address.sin_addr.s_addr = remote_address.address;
    address.sin_family = AF_INET;
    if (connect(socket->socket, (struct sockaddr *)&address, sizeof(address)) ==
        -1) {
        set_error(strerror(errno));
        return SOCKET_ERROR;
    }
    return SOCKET_DONE;
}

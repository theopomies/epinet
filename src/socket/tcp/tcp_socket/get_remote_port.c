/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** get_remote_port
*/

#include <errno.h>
#include <netinet/ip.h>
#include <string.h>
#include <sys/socket.h>

#include <error.h>
#include <tcp_socket.h>

unsigned short tcp_socket_get_remote_port(const tcp_socket_t *socket)
{
    struct sockaddr_in address;
    socklen_t len = sizeof(address);

    if (!socket || socket->socket < 0) {
        set_error("tcp_socket_get_local_port: socket cant be NULL or not init");
        return 0;
    }
    if (getpeername(socket->socket, (struct sockaddr *)&address, &len) == -1) {
        set_error(strerror(errno));
        return 0;
    }
    return ntohs(address.sin_port);
}

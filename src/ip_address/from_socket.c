/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** from_socket
*/

#include <errno.h>
#include <string.h>
#include <sys/socket.h>

#include <error.h>
#include <ip_address.h>

ip_address_t ip_address_from_socket(socket_t *socket)
{
    ip_address_t ip;
    struct sockaddr_in addr_in;
    socklen_t len = sizeof(addr_in);

    memset(&ip, 0, sizeof(ip_address_t));
    if (!socket || socket->socket < 0) {
        set_error("ip_address_from_socket: socket cant be NULL or a negative.");
        return ip;
    }
    if (getpeername(socket->socket, (struct sockaddr *)&addr_in, &len) == -1) {
        set_error(strerror(errno));
        return ip;
    }
    return ip_address_from_integer(addr_in.sin_addr.s_addr);
}

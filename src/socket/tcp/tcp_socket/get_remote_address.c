/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** get_remote_address
*/

#include <errno.h>
#include <netinet/ip.h>
#include <string.h>
#include <sys/socket.h>

#include <error.h>
#include <tcp_socket.h>

ip_address_t tcp_socket_get_remote_address(const tcp_socket_t *socket)
{
    ip_address_t ip;
    struct sockaddr_in address;
    socklen_t len = sizeof(address);

    memset(&ip, 0, sizeof(ip));
    ip.address = ADDRESS_NONE;
    if (!socket || socket->socket < 0) {
        set_error("tcp_socket_get_local_port: socket cant be NULL or not init");
        return ip;
    }
    if (getpeername(socket->socket, (struct sockaddr *)&address, &len) == -1) {
        set_error(strerror(errno));
        return ip;
    }
    return ip_address_from_integer(address.sin_addr.s_addr);
}

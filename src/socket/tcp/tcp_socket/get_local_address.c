/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-theo.pomies
** File description:
** get_local_address
*/

#include <errno.h>
#include <netinet/ip.h>
#include <string.h>
#include <sys/socket.h>

#include <error.h>
#include <tcp_socket.h>

ip_address_t tcp_socket_get_local_address(const tcp_socket_t *socket)
{
    ip_address_t ip;
    struct sockaddr_in address;
    socklen_t len = sizeof(address);

    memset(&ip, 0, sizeof(ip));
    if (!socket || socket->socket < 0) {
        set_error("tcp_socket_get_local_port: socket cant be NULL or not init");
        ip.address = ADDRESS_NONE;
        return ip;
    }
    if (getsockname(socket->socket, (struct sockaddr *)&address, &len) == -1) {
        set_error(strerror(errno));
        ip.address = ADDRESS_NONE;
        return ip;
    }
    return ip_address_from_integer(htonl(address.sin_addr.s_addr));
}

/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** listen
*/

#include <errno.h>
#include <netinet/ip.h>
#include <string.h>

#include <error.h>
#include <tcp_listener.h>

socket_status_t tcp_listener_listen(
    tcp_listener_t *listener, unsigned short port, ip_address_t address)
{
    struct sockaddr_in address_in;

    if (!listener || listener->socket < 0) {
        set_error("tcp_listener_listen: listener cant be NULL or negative");
        return SOCKET_ERROR;
    }
    if (address.address == ADDRESS_NONE && !*address.str_address) {
        set_error("tcp_listener_listen: address is invalid.");
        return SOCKET_ERROR;
    }
    memset(&address_in, 0, sizeof(address_in));
    address_in.sin_addr.s_addr = address.address;
    address_in.sin_family = AF_INET;
    address_in.sin_port = htons(port);
    if (!bind(listener->socket, (struct sockaddr *)&address_in,
            sizeof(address_in)) ||
        !listen(listener->socket, SOMAXCONN)) {
        set_error(strerror(errno));
        return SOCKET_ERROR;
    }
    return SOCKET_DONE;
}

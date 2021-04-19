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

static bool tcp_listener_bind(
    tcp_listener_t *listener, unsigned short port, ip_address_t address)
{
    struct sockaddr_in address_in;
    int yes = 1;

    memset(&address_in, 0, sizeof(address_in));
    address_in.sin_addr.s_addr = address.address;
    address_in.sin_family = AF_INET;
    address_in.sin_port = htons(port);
    if (setsockopt(listener->socket, SOL_SOCKET, SO_REUSEADDR, &yes,
            sizeof(int)) == -1) {
        set_error(strerror(errno));
        return false;
    }
    if (bind(listener->socket, (struct sockaddr *)&address_in,
            sizeof(address_in))) {
        set_error(strerror(errno));
        return false;
    }
    return true;
}

socket_status_t tcp_listener_listen(
    tcp_listener_t *listener, unsigned short port, ip_address_t address)
{
    if (!listener || listener->socket < 0) {
        set_error("tcp_listener_listen: listener cant be NULL or negative");
        return SOCKET_ERROR;
    }
    if (address.address == ADDRESS_NONE && !*address.str_address) {
        set_error("tcp_listener_listen: address is invalid.");
        return SOCKET_ERROR;
    }
    if (!tcp_listener_bind(listener, port, address))
        return SOCKET_ERROR;
    if (listen(listener->socket, SOMAXCONN)) {
        set_error(strerror(errno));
        return SOCKET_ERROR;
    }
    return SOCKET_DONE;
}

/*
** EPITECH PROJECT, 2021
** Epinet
** File description:
** tcp_listener
*/

#ifndef TCP_LISTENER_H_
#define TCP_LISTENER_H_

#include <ip_address.h>
#include <tcp_socket.h>

///////////////////////////////////////////////////////////////////////////////
/// A tcp_listener is a tcp_socket meant to listen and accept
/// therefore, most tcp_socket functions can be used on it
/// However you sould not use:
/// send*
/// receive*
/// (dis)connect
///////////////////////////////////////////////////////////////////////////////

#define TCP_LISTENER(socket) (tcp_socket_get_listener(socket));

typedef tcp_socket_t tcp_listener_t;

tcp_listener_t *tcp_socket_get_listener(tcp_socket_t *socket);

tcp_listener_t *tcp_listener_create(void);
void tcp_listener_destroy(tcp_listener_t *listener);

socket_status_t tcp_listener_listen(
    tcp_listener_t *listener, unsigned short port, ip_address_t address);

socket_status_t tcp_listener_accept(
    tcp_listener_t *listener, tcp_socket_t **connected);

#endif /* !TCP_LISTENER_H_ */

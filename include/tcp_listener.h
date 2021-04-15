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

typedef tcp_socket_t tcp_listener_t;

tcp_listener_t *tcp_listener_create(void);
void tcp_listener_destroy(tcp_listener_t *listener);

void tcp_listener_set_blocking(tcp_listener_t *listener, bool blocking);
bool tcp_listener_is_blocking(const tcp_listener_t *listener);

unsigned short tcp_listener_get_local_port(const tcp_listener_t *listener);

socket_status_t tcp_listener_listen(
    tcp_listener_t *listener, unsigned short port, ip_address_t address);

socket_status_t tcp_listener_accept(
    tcp_listener_t *listener, tcp_socket_t **connected);

#endif /* !TCP_LISTENER_H_ */

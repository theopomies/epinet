/*
** EPITECH PROJECT, 2021
** Epinet
** File description:
** tcp_socket
*/

#ifndef TCP_SOCKET_H_
#define TCP_SOCKET_H_

#include <stdbool.h>
#include <stddef.h>

#include <ip_address.h>
#include <packet.h>
#include <socket.h>
#include <timeout.h>

#define TCP_SOCKET(socket) (socket_get_tcp_socket(socket))

typedef struct
{
    socket_type_t type;
    fd_t socket;
    bool is_blocking;
} tcp_socket_t;

tcp_socket_t *socket_get_tcp_socket(socket_t *socket);

tcp_socket_t *tcp_socket_create(void);
tcp_socket_t *tcp_socket_create_empty(void);
void tcp_socket_destroy(tcp_socket_t *socket);

void tcp_socket_set_blocking(tcp_socket_t *socket, bool blocking);
bool tcp_socket_is_blocking(const tcp_socket_t *socket);

unsigned short tcp_socket_get_local_port(const tcp_socket_t *socket);
ip_address_t tcp_socket_get_remote_address(const tcp_socket_t *socket);
unsigned short tcp_socket_get_remote_port(const tcp_socket_t *socket);

socket_status_t tcp_socket_connect(tcp_socket_t *socket,
    ip_address_t remoteAddress, unsigned short remotePort, timeout_t timeout);
void tcp_socket_disconnect(tcp_socket_t *socket);

socket_status_t tcp_socket_send(
    tcp_socket_t *socket, const void *data, size_t size);
socket_status_t tcp_socket_send_partial(
    tcp_socket_t *socket, const void *data, size_t size, size_t *sent);
socket_status_t tcp_socket_receive(
    tcp_socket_t *socket, void *data, size_t size, size_t *received);

socket_status_t tcp_socket_send_packet(tcp_socket_t *socket, packet_t *packet);
socket_status_t tcp_socket_receive_packet(
    tcp_socket_t *socket, packet_t *packet);

#endif /* !TCP_SOCKET_H_ */

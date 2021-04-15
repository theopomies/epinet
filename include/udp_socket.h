/*
** EPITECH PROJECT, 2021
** Epinet
** File description:
** udp_socket
*/

#ifndef UDP_SOCKET_H_
#define UDP_SOCKET_H_

#include <stdbool.h>
#include <stddef.h>

#include <ip_address.h>
#include <packet.h>
#include <socket.h>

#define UDP_SOCKET_MAX_DATAGRAM_SIZE 65507
#define UDP_SOCKET(socket) (socket_get_udp_socket(socket))

typedef struct
{
    socket_type_t type;
    fd_t socket;
    bool is_blocking;
} udp_socket_t;

udp_socket_t *socket_get_udp_socket(socket_t *socket);

udp_socket_t *udp_socket_create(void);
void udp_socket_destroy(udp_socket_t *socket);

void udp_socket_set_blocking(udp_socket_t *socket, bool blocking);
bool udp_socket_is_blocking(const udp_socket_t *socket);

unsigned short udp_socket_get_local_port(const udp_socket_t *socket);

socket_status_t udp_socket_bind(
    udp_socket_t *socket, unsigned short port, ip_address_t address);
void udp_socket_unbind(udp_socket_t *socket);

socket_status_t udp_socket_send(udp_socket_t *socket, const void *data,
    size_t size, ip_address_t remote_address, unsigned short remote_port);
socket_status_t udp_socket_receive(udp_socket_t *socket, void *data,
    size_t size, size_t *received, ip_address_t *remote_address,
    unsigned short *remote_port);

socket_status_t udp_socket_send_packet(udp_socket_t *socket, packet_t *packet,
    ip_address_t remote_address, unsigned short remote_port);
socket_status_t udp_socket_receive_packet(udp_socket_t *socket,
    packet_t *packet, ip_address_t *remote_address,
    unsigned short *remote_port);

#endif /* !UDP_SELECTOR_H_ */
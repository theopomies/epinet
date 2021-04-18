/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** send_packet
*/

#include <error.h>
#include <tcp_socket.h>

socket_status_t tcp_socket_send_packet(tcp_socket_t *socket, packet_t *packet)
{
    (void)socket;
    (void)packet;

    set_error("tcp_socket_send_packet: NOT IMPLEMENTED");
    return SOCKET_ERROR;
}

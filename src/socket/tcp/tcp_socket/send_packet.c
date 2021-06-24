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
    if (!packet) {
        set_error("tcp_socket_send_packet: packet cant be NULL.");
        return SOCKET_ERROR;
    }
    return tcp_socket_send(socket, packet->data, packet->size);
}

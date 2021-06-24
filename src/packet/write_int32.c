/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** write_int32
*/

#include <arpa/inet.h>

#include <error.h>
#include <packet.h>

packet_status_t packet_write_int32(packet_t *packet, int32_t data)
{
    if (!packet) {
        set_error("packet_write_int32: packet can not be null.");
        return PACKET_ERROR;
    }
    data = htonl(data);
    return packet_append(packet, &data, sizeof(data));
}
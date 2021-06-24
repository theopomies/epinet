/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** write_uint32
*/

#include <arpa/inet.h>

#include <error.h>
#include <packet.h>

packet_status_t packet_write_uint32(packet_t *packet, uint32_t data)
{
    if (!packet) {
        set_error("packet_write_uint32: packet can not be null.");
        return PACKET_ERROR;
    }
    data = htonl(data);
    return packet_append(packet, &data, sizeof(data));
}
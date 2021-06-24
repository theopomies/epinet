/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** write_uint8
*/

#include <error.h>
#include <packet.h>

packet_status_t packet_write_uint8(packet_t *packet, uint8_t data)
{
    if (!packet) {
        set_error("packet_read_uint8: packet can not be null.");
        return PACKET_ERROR;
    }
    return packet_append(packet, &data, sizeof(data));
}
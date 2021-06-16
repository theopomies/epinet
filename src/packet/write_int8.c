/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** write_int8
*/

#include <error.h>
#include <packet.h>

packet_status_t packet_write_int8(packet_t *packet, int8_t data)
{
    if (!packet) {
        set_error("packet_write_int8: packet can not be null.");
        return PACKET_ERROR;
    }
    return packet_append(packet, &data, sizeof(data));
}
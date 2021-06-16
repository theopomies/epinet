/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** write_int16
*/

#include <arpa/inet.h>

#include <error.h>
#include <packet.h>

packet_status_t packet_write_int16(packet_t *packet, int16_t data)
{
    if (!packet) {
        set_error("packet_write_int16: packet can not be null.");
        return PACKET_ERROR;
    }
    data = htons(data);
    return packet_append(packet, &data, sizeof(data));
}
/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** read
*/

#include <string.h>

#include <error.h>
#include <packet.h>

packet_status_t packet_read(packet_t *packet, void *data, size_t size)
{
    if (!packet) {
        set_error("packet_read: packet can not be null.");
        return PACKET_ERROR;
    } else if (!data) {
        set_error("packet_read: data can not be null.");
        return PACKET_ERROR;
    }
    if (packet_can_read(packet, size) == false) {
        set_error("packet_read: Not enough data to read.");
        return PACKET_ERROR;
    }
    memcpy(data, packet->data + packet->read_pos, size);
    packet->read_pos += size;
    return PACKET_DONE;
}
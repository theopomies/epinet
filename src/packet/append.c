/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** append
*/

#include <string.h>

#include <error.h>
#include <packet.h>

packet_status_t packet_append(packet_t *packet, const void *data, size_t size)
{
    size_t read_pos = 0;
    packet_status_t status = PACKET_DONE;

    if (!packet) {
        set_error("packet_append: packet can not be null.");
        return PACKET_ERROR;
    }
    if (data && size) {
        read_pos = packet->size;
        status = packet_resize(packet, packet->size + size);
        if (status != PACKET_DONE)
            return status;
        memcpy(packet->data + read_pos, data, size);
    }
    return PACKET_DONE;
}

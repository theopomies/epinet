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
    size_t begin = 0;
    packet_status_t status = PACKET_DONE;

    if (!packet) {
        set_error("packet_append: packet can not be null.");
        return PACKET_ERROR;
    }
    if (data && size) {
        begin = packet->size;
        status = packet_resize(packet, begin + size);
        if (status != PACKET_DONE)
            return status;
        memcpy(packet->data + begin, data, size);
    }
    return PACKET_DONE;
}

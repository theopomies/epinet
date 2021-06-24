/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** resize
*/

#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <error.h>
#include <packet.h>

packet_status_t packet_resize(packet_t *packet, size_t size)
{
    if (!packet) {
        set_error("packet_resize: packet can not be null.");
        return PACKET_ERROR;
    }
    packet->data = realloc(packet->data, size + 1);
    if (!packet->data) {
        set_error(strerror(errno));
        return PACKET_CORRUPTED;
    }
    packet->size = size;
    return PACKET_DONE;
}

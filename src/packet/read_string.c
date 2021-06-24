/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** read_string
*/

#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <error.h>
#include <packet.h>

static packet_status_t packet_read_string_error(packet_t *packet, char **data)
{
    if (!data) {
        set_error("packet_read_string: data can not be null.");
        return PACKET_ERROR;
    }
    *data = NULL;
    if (!packet) {
        set_error("packet_read_string: packet can not be null.");
        return PACKET_ERROR;
    }
    if (!packet->data) {
        set_error("packet_read_string: packet can not be null.");
        return PACKET_ERROR;
    }
    return PACKET_DONE;
}

packet_status_t packet_read_string(packet_t *packet, char **data)
{
    packet_status_t status = packet_read_string_error(packet, data);
    size_t size_to_read = 0;

    if (status != PACKET_DONE)
        return status;
    packet->data[packet->size] = '\0';
    size_to_read = strlen(packet->data + packet->read_pos) + 1;
    *data = realloc(*data, size_to_read);
    if (!*data) {
        set_error(strerror(errno));
        return PACKET_ERROR;
    }
    if (size_to_read)
        (*data)[size_to_read - 1] = '\0';
    return packet_read(packet, *data, size_to_read);
}

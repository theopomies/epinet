/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** read_string_until
*/

#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <error.h>
#include <packet.h>

static packet_status_t packet_read_string_until_error(packet_t *packet,
                                                            char **data)
{
    if (!packet) {
        set_error("packet_read_string_until: packet can not be null.");
        return PACKET_ERROR;
    }
    if (!packet->data) {
        set_error("packet_read_string_until: packet can not be null.");
        return PACKET_ERROR;
    }
    if (!data) {
        set_error("packet_read_string_until: data can not be null.");
        return PACKET_ERROR;
    }
    return PACKET_DONE;
}

void packet_read_string_cut_on_delimiter(
    packet_t *packet, const char *delim, size_t *size_to_read)
{
    char *begin = packet->data + packet->read_pos;
    char *end = NULL;

    packet->read_pos += strspn(begin, delim);
    if (packet_can_read(packet, 1) == false)
        return;
    begin = packet->data + packet->read_pos;
    end = begin + strcspn(begin, delim);
    *size_to_read = (end - begin) + strspn(end, delim);
    if (begin[*size_to_read] == '\0')
        *size_to_read += 1;
    end[0] = '\0';
}

packet_status_t packet_read_string_until(
    packet_t *packet, char **data, const char *delim)
{
    packet_status_t status = packet_read_string_until_error(packet, data);
    size_t size_to_read = 0;

    if (status != PACKET_DONE)
        return status;
    if (!delim)
        return packet_read_string(packet, data);
    packet->data[packet->size] = '\0';
    packet_read_string_cut_on_delimiter(packet, delim, &size_to_read);
    if (size_to_read == 0)
        return PACKET_END_OF_PACKET;
    *data = realloc(*data, size_to_read + 1);
    if (!*data) {
        set_error(strerror(errno));
        return PACKET_ERROR;
    }
    (*data)[size_to_read] = '\0';
    return packet_read(packet, *data, size_to_read);
}

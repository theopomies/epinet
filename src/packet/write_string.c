/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** write_string
*/

#include <string.h>

#include <error.h>
#include <packet.h>

packet_status_t packet_write_string(packet_t *packet, const char *data)
{
    size_t size = 0;

    if (!data) {
        set_error("packet_write_string: data can not be null.");
        return PACKET_ERROR;
    }
    size = strlen(data) + 1;
    return packet_append(packet, data, size);
}

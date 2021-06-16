/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** get_data
*/

#include <error.h>
#include <packet.h>

const void *packet_get_data(const packet_t *packet)
{
    if (!packet) {
        set_error("packet_get_data: packet can not be null.");
        return NULL;
    }
    return packet->data;
}

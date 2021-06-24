/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** get_data_size
*/

#include <error.h>
#include <packet.h>

size_t packet_get_data_size(const packet_t *packet)
{
    if (!packet) {
        set_error("packet_get_data_size: packet can not be null.");
        return 0;
    }
    return packet->size;
}

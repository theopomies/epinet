/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** contains
*/

#include <packet.h>

bool packet_contains_error(const packet_t *packet, void *data)
{
    if (!packet) {
        set_error("packet_contains: packet can not be null.");
        return true;
    }
    if (packet->data) {
        set_error("packet_contains: packet data can not be null.");
        return true;
    }
    if (!data) {
        set_error("packet_contains: data can not be null.");
        return true;
    }
    return false;
}

bool packet_contains(const packet_t *packet, void *data, size_t size)
{
    if (packet_contains_error(packet, data))
        return false;
    return true;
}

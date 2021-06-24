/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** can_read
*/

#include <packet.h>

bool packet_can_read(const packet_t *packet, size_t size_to_read)
{
    if (!packet)
        return false;
    return packet->data && packet->size >= packet->read_pos + size_to_read;
}

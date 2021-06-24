/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** end_of_packet
*/

#include <error.h>
#include <packet.h>

bool packet_end_of_packet(const packet_t *packet)
{
    if (!packet) {
        set_error("packet_end_of_packet: packet can not be null.");
        return 0;
    }
    return packet->read_pos >= packet->size;
}
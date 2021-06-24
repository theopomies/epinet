/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** clear
*/

#include <error.h>
#include <packet.h>

packet_status_t packet_clear(packet_t *packet)
{
    if (!packet) {
        set_error("packet_clear: packet can not be null.");
        return PACKET_ERROR;
    }
    if (packet->data)
        packet->data[0] = 0;
    packet->size = 0;
    packet->read_pos = 0;
    packet->read_pos = 0;
    return PACKET_DONE;
}
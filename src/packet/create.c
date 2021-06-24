/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** create
*/

#include <stdlib.h>

#include <packet.h>

packet_t *packet_create(void)
{
    packet_t *packet = malloc(sizeof(packet_t));

    if (!packet)
        return NULL;
    packet->data = NULL;
    packet->size = 0;
    packet->read_pos = 0;
    return packet;
}

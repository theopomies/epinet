/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** destroy
*/

#include <stdlib.h>

#include <packet.h>

void packet_destroy(packet_t *packet)
{
    if (!packet)
        return;
    free(packet->data);
    free(packet);
}
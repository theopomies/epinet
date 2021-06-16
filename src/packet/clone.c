/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** create
*/

#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <error.h>
#include <packet.h>

packet_t *packet_clone(const packet_t *other)
{
    packet_t *packet = malloc(sizeof(packet_t));

    if (!packet) {
        set_error(strerror(errno));
        return NULL;
    }
    memcpy(packet, other, sizeof(packet_t));
    if (other->data) {
        packet->data = malloc(other->size);
        if (!packet->data) {
            set_error(strerror(errno));
            packet_destroy(packet);
            return NULL;
        }
        memcpy(packet->data, other->data, other->size);
    }
    return packet;
}

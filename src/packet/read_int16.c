/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** read_int16
*/

#include <arpa/inet.h>
#include <string.h>

#include <error.h>
#include <packet.h>

packet_status_t packet_read_int16(packet_t *packet, int16_t *data)
{
    packet_status_t s = packet_read(packet, data, sizeof(*data));

    if (s != PACKET_DONE)
        return s;
    *data = ntohs(*data);
    return s;
}
/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** read_int8
*/

#include <string.h>

#include <error.h>
#include <packet.h>

packet_status_t packet_read_int8(packet_t *packet, int8_t *data)
{
    return packet_read(packet, data, sizeof(*data));
}
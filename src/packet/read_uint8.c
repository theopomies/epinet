/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** read_uint8
*/

#include <string.h>

#include <error.h>
#include <packet.h>

packet_status_t packet_read_uint8(packet_t *packet, uint8_t *data)
{
    return packet_read(packet, data, sizeof(*data));
}
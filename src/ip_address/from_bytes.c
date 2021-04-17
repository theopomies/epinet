/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** from_bytes
*/

#include <ip_address.h>

ip_address_t ip_address_from_bytes(
    uint8_t byte0, uint8_t byte1, uint8_t byte2, uint8_t byte3)
{
    return ip_address_from_integer((byte0 << 24) | (byte1 << 16) | (byte2 << 8) | byte3);
}

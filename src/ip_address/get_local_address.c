/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** get_local_address
*/

#include <string.h>

#include <ip_address.h>

ip_address_t ip_address_get_local_address(void)
{
    ip_address_t ip;

    memset(&ip, 0, sizeof(ip));
    ip.address = ADDRESS_NONE;
    return ip;
}

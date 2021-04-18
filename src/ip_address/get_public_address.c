/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** get_public_address
*/

#include <string.h>

#include <error.h>
#include <ip_address.h>

ip_address_t ip_address_get_public_address(timeout_t timeout)
{
    ip_address_t ip;

    (void)timeout;
    memset(&ip, 0, sizeof(ip));
    ip.address = ADDRESS_NONE;
    set_error("ip_address_get_public_address: NOT IMPLEMENTED.");
    return ip;
}

/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** to_string
*/

#include <string.h>

#include <error.h>
#include <ip_address.h>

void ip_address_to_string(ip_address_t address, char *string)
{
    if (!string) {
        set_error("ip_address_to_string: Destination string cant be NULL.");
        return;
    }
    strncpy(string, address.str_address, INET_ADDRSTRLEN);
}

/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** from_string
*/

#include <arpa/inet.h>
#include <errno.h>
#include <string.h>

#include <error.h>
#include <ip_address.h>

ip_address_t ip_address_from_string(const char *address)
{
    ip_address_t ip;
    struct sockaddr_in address_in;
    int res;

    memset(&ip, 0, sizeof(ip_address_t));
    res = inet_pton(AF_INET, address, &address_in.sin_addr);
    if (res < 0) {
        set_error(strerror(errno));
        ip.address = ADDRESS_NONE;
        return ip;
    }
    if (res == 0) {
        set_error("ip_address_from_string: address should be a valid ipv4");
        ip.address = ADDRESS_NONE;
        return ip;
    }
    strncpy(ip.str_address, address, INET_ADDRSTRLEN);
    ip.address = address_in.sin_addr.s_addr;
    return ip;
}

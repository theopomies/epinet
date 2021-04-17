/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** from_integer
*/

#include <arpa/inet.h>
#include <errno.h>
#include <string.h>

#include <error.h>
#include <ip_address.h>

ip_address_t ip_address_from_integer(uint32_t address)
{
    ip_address_t ip;
    struct sockaddr_in address_in;

    address_in.sin_addr.s_addr = htonl(address);
    if (!inet_ntop(
            AF_INET, &address_in.sin_addr, ip.str_address, INET_ADDRSTRLEN)) {
        memset(&ip, 0, sizeof(ip_address_t));
        set_error(strerror(errno));
        ip.address = ADDRESS_NONE;
        return ip;
    }
    ip.address = address_in.sin_addr.s_addr;
    return ip;
}

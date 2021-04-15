/*
** EPITECH PROJECT, 2021
** Epinet
** File description:
** ip_address
*/

#ifndef IP_ADDRESS_H_
#define IP_ADDRESS_H_

#include <netinet/ip.h>
#include <stdint.h>

typedef struct
{
    char str_address[INET_ADDRSTRLEN];
    uint32_t address;
} ip_address_t;

ip_address_t ip_address_from_string(const char *address);
ip_address_t ip_address_from_bytes(
    uint8_t byte0, uint8_t byte1, uint8_t byte2, uint8_t byte3);
ip_address_t ip_address_from_integer(uint32_t address);
void ip_address_to_string(ip_address_t address, char *string);
uint32_t ip_address_to_integer(ip_address_t address);
ip_address_t ip_address_get_local_address(void);
ip_address_t ip_address_get_public_address(int timeout);

#endif /* !IP_ADDRESS_H_ */

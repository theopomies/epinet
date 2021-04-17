/*
** EPITECH PROJECT, 2021
** Epinet
** File description:
** ip_address
*/

#ifndef IP_ADDRESS_H_
#define IP_ADDRESS_H_

#include <socket.h>
#include <timeout.h>

#include <netinet/ip.h>
#include <stdint.h>

#define ADDRESS_NONE (htonl(-1))
#define IP_ADDRESS_ANY (ip_address_from_string("0.0.0.0"))
#define IP_ADDRESS_BROADCAST (ip_address_from_string("255.255.255.255"))
#define IP_ADDRESS_LOCALHOST (ip_address_from_string("127.0.0.1"))

typedef struct
{
    uint32_t address;
    char str_address[INET_ADDRSTRLEN];
} ip_address_t;

ip_address_t ip_address_from_string(const char *address);
ip_address_t ip_address_from_bytes(
    uint8_t byte0, uint8_t byte1, uint8_t byte2, uint8_t byte3);
ip_address_t ip_address_from_integer(uint32_t address);
ip_address_t ip_address_from_socket(socket_t *socket);
void ip_address_to_string(ip_address_t address, char *string);
uint32_t ip_address_to_integer(ip_address_t address);
ip_address_t ip_address_get_local_address(void);
ip_address_t ip_address_get_public_address(timeout_t timeout);

#endif /* !IP_ADDRESS_H_ */

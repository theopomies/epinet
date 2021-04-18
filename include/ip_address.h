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

#define IS_VALID_IP(ip) (*ip->str_address != '\0')

////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing both the integer for the address and the string
////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    uint32_t address; ///< Integer representation of the address
    char str_address[INET_ADDRSTRLEN]; ///< String representation of the address
} ip_address_t;

////////////////////////////////////////////////////////////////////////////////
/// \brief Returns an ip_address structure from a string format \a address.
///
/// \param address String representation of the address. (aka. "127.0.0.1")
///
/// \return The address corresponding to the string on success, an invalid ip on
/// error. To be checked with IS_VALID_IP(). On error epinet_perror() is set up.
////////////////////////////////////////////////////////////////////////////////
ip_address_t ip_address_from_string(const char *address);

////////////////////////////////////////////////////////////////////////////////
/// \brief Returns an ip_address structure from the bytes of the address.
///
/// Converts bytes to and ip_address.
/// Ex: ip_address_from_string(127, 0, 0, 1)
///
/// \param byte0 First byte of the address. 127 in the example.
/// \param byte1 Second byte of the address. 0 in the example.
/// \param byte2 Third byte of the address. 0 in the example.
/// \param byte3 Fourth and last byte of the address. 1 in the example.
///
/// \return The address corresponding to the bytes on success, an invalid ip on
/// error. To be checked with IS_VALID_IP(). On error epinet_perror() is set up.
////////////////////////////////////////////////////////////////////////////////
ip_address_t ip_address_from_bytes(
    uint8_t byte0, uint8_t byte1, uint8_t byte2, uint8_t byte3);

////////////////////////////////////////////////////////////////////////////////
/// \brief Returns an ip_address structure from the integer \a address.
///
/// \param address Integer representation of the address.
///
/// \return The address corresponding on success, an invalid ip on
/// error. To be checked with IS_VALID_IP(). On error epinet_perror() is set up.
////////////////////////////////////////////////////////////////////////////////
ip_address_t ip_address_from_integer(uint32_t address);

////////////////////////////////////////////////////////////////////////////////
/// \brief Returns an ip_address structure from a socket_t object.
///
/// \param socket The socket object pointer from which to retrieve the ip.
///
/// \return The address corresponding on success, an invalid ip on
/// error. To be checked with IS_VALID_IP(). On error epinet_perror() is set up.
////////////////////////////////////////////////////////////////////////////////
ip_address_t ip_address_from_socket(socket_t *socket);

////////////////////////////////////////////////////////////////////////////////
/// \brief Places the string representation of \a address in \a string.
///
/// \param address Ip_address to convert to string.
/// \param string The destination string. (At least INET_ADDRSTRLEN large)
////////////////////////////////////////////////////////////////////////////////
void ip_address_to_string(ip_address_t address, char *string);

////////////////////////////////////////////////////////////////////////////////
/// \brief Retrieves the integer represenation of \a address.
///
/// \param address Ip_address to convert to string.
///
/// \return The integer representation of the address.
////////////////////////////////////////////////////////////////////////////////
uint32_t ip_address_to_integer(ip_address_t address);

////////////////////////////////////////////////////////////////////////////////
/// \brief Getter for the local address.
///
/// TODO NOT IMPLEMENTED YET.
///
/// \return The ip_address corresponding to the local address.
////////////////////////////////////////////////////////////////////////////////
ip_address_t ip_address_get_local_address(void);

////////////////////////////////////////////////////////////////////////////////
/// \brief Getter for the public address.
///
/// TODO NOT IMPLEMENTED YET.
///
/// \return The ip_address corresponding to the public address.
////////////////////////////////////////////////////////////////////////////////
ip_address_t ip_address_get_public_address(timeout_t timeout);

#endif /* !IP_ADDRESS_H_ */

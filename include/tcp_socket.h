/*
** EPITECH PROJECT, 2021
** Epinet
** File description:
** tcp_socket
*/

#ifndef TCP_SOCKET_H_
#define TCP_SOCKET_H_

#include <stdbool.h>
#include <stddef.h>

#include <ip_address.h>
#include <packet.h>
#include <socket.h>
#include <timeout.h>

#define TCP_SOCKET(socket) (socket_get_tcp_socket(socket))

typedef struct
{
    socket_type_t type;
    fd_t socket;
    bool is_blocking;
} tcp_socket_t;

////////////////////////////////////////////////////////////////////////////////
/// \brief Casts a socket in a TCP_SOCKET
///
/// \return The casted socket if it is of SOCKET_TCP type, NULL otherwise
////////////////////////////////////////////////////////////////////////////////
tcp_socket_t *socket_get_tcp_socket(socket_t *socket);

////////////////////////////////////////////////////////////////////////////////
/// \brief Creates a tcp_socket with a VALID socket
///
/// \return The newly allocated tcp_socket
////////////////////////////////////////////////////////////////////////////////
tcp_socket_t *tcp_socket_create(void);

////////////////////////////////////////////////////////////////////////////////
/// \brief creates an empty tcp_socket. that is allocated but with no_socket
///
/// \return the newly allocated tcp_socket
////////////////////////////////////////////////////////////////////////////////
tcp_socket_t *tcp_socket_create_empty(void);

////////////////////////////////////////////////////////////////////////////////
/// \brief Destroys (free + close) a tcp_socket
///
/// \param socket Socket to destroy
////////////////////////////////////////////////////////////////////////////////
void tcp_socket_destroy(tcp_socket_t *socket);

////////////////////////////////////////////////////////////////////////////////
/// \brief Sets blocking-ness of a tcp_socket
///
/// \param socket Socket to set up
/// \param blocking Blocking-ness to set
////////////////////////////////////////////////////////////////////////////////
void tcp_socket_set_blocking(tcp_socket_t *socket, bool blocking);

////////////////////////////////////////////////////////////////////////////////
/// \brief Check blocking-ness of a tcp_socket
///
/// \param socket Socket to check
///
/// \return Blocking-ness of the socket
////////////////////////////////////////////////////////////////////////////////
bool tcp_socket_is_blocking(const tcp_socket_t *socket);

////////////////////////////////////////////////////////////////////////////////
/// \brief Gets the local port of a socket
///
/// \param socket Socket to check
///
/// \return The port bound to the socket on success. 0 on error with error set.
////////////////////////////////////////////////////////////////////////////////
unsigned short tcp_socket_get_local_port(const tcp_socket_t *socket);

////////////////////////////////////////////////////////////////////////////////
/// \brief Gets the remote address of a socket
///
/// \param socket Socket to check
///
/// \return The ip address. To check with IS_VALID_IP
////////////////////////////////////////////////////////////////////////////////
ip_address_t tcp_socket_get_remote_address(const tcp_socket_t *socket);

////////////////////////////////////////////////////////////////////////////////
/// \brief Gets the local address of a socket
///
/// \param socket Socket to check
///
/// \return The ip address. To check with IS_VALID_IP
////////////////////////////////////////////////////////////////////////////////
ip_address_t tcp_socket_get_local_address(const tcp_socket_t *socket);

////////////////////////////////////////////////////////////////////////////////
/// \brief Gets the remote port of a socket
///
/// \param socket Socket to check
///
/// \return The port bound to the socket on success. 0 on error.
////////////////////////////////////////////////////////////////////////////////
unsigned short tcp_socket_get_remote_port(const tcp_socket_t *socket);

////////////////////////////////////////////////////////////////////////////////
/// \brief Connect to a \a socket
///
/// \param socket Socket to connect with
/// \param remote_address Remote addresss to connect to
/// \param remote_port Remote port to connect to
///
/// \return SOCKET_DONE on success, SOCKET_ERROR otherwise and epinet_perror set
////////////////////////////////////////////////////////////////////////////////
socket_status_t tcp_socket_connect(tcp_socket_t *socket,
    ip_address_t remote_address, unsigned short remote_port);

////////////////////////////////////////////////////////////////////////////////
/// \brief Disconnects a \a socket
///
/// \param socket Socket to disconnect
////////////////////////////////////////////////////////////////////////////////
void tcp_socket_disconnect(tcp_socket_t *socket);

////////////////////////////////////////////////////////////////////////////////
/// \brief Sends \a data of size \a size to a \a socket
///
/// \param socket Socket to send \a data to
/// \param data Data to send
/// \param size Size of the data to send
///
/// \return SOCKET_DONE on success, any other status otherwise and sets error.
////////////////////////////////////////////////////////////////////////////////
socket_status_t tcp_socket_send(
    tcp_socket_t *socket, const void *data, size_t size);

////////////////////////////////////////////////////////////////////////////////
/// \brief Attempts to send \a size of \a data to \a socket. Data actually sent
/// is placed is sent
///
/// \param socket Socket to send to
/// \param data Data to send
/// \param size Size of the data to send
/// \param sent Pointer to a value-return to place the size of data sent. can be
/// NULL to discard result.
///
/// \return SOCKET_DONE on complete send, SOCKET_PARTIAL on partial send,
/// an informative status and epinet_perror set otherwise.
////////////////////////////////////////////////////////////////////////////////
socket_status_t tcp_socket_send_partial(
    tcp_socket_t *socket, const void *data, size_t size, size_t *sent);

////////////////////////////////////////////////////////////////////////////////
/// \brief Attempts to receive \a size of \a data from \a socket
///
/// \param socket Socket to receive from
/// \param data Pointer to store data
/// \param size Size of the data to receive
/// \param receive Pointer to a value-return to place the size of data received.
/// can be NULL to discard result.
////////////////////////////////////////////////////////////////////////////////
socket_status_t tcp_socket_receive(
    tcp_socket_t *socket, void *data, size_t size, size_t *received);

////////////////////////////////////////////////////////////////////////////////
/// \brief Attempts to send \a packet to \a socket. The data and it's size are
/// stored in the packet
///
/// \param socket Socket to send to
/// \param packet Packet to send
/// \return SOCKET_DONE on complete send, SOCKET_PARTIAL on partial send,
/// an informative status and epinet_perror set otherwise.
////////////////////////////////////////////////////////////////////////////////
socket_status_t tcp_socket_send_packet(tcp_socket_t *socket, packet_t *packet);

////////////////////////////////////////////////////////////////////////////////
/// TODO: NOT IMPLEMENTED
////////////////////////////////////////////////////////////////////////////////
socket_status_t tcp_socket_receive_packet(
    tcp_socket_t *socket, packet_t *packet);

#endif /* !TCP_SOCKET_H_ */

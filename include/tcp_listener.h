/*
** EPITECH PROJECT, 2021
** Epinet
** File description:
** tcp_listener
*/

#ifndef TCP_LISTENER_H_
#define TCP_LISTENER_H_

#include <ip_address.h>
#include <tcp_socket.h>

///////////////////////////////////////////////////////////////////////////////
/// A tcp_listener is a tcp_socket meant to listen and accept
/// therefore, most tcp_socket functions can be used on it
/// However you sould not use:
/// send*
/// receive*
/// (dis)connect
///////////////////////////////////////////////////////////////////////////////

#define TCP_LISTENER(socket) (tcp_socket_get_listener(socket));

typedef tcp_socket_t tcp_listener_t;

////////////////////////////////////////////////////////////////////////////////
/// \brief Casts a \a tcp_socket in a tcp_listener
///
/// \param socket The tcp_socket to cast
///
/// \return The casted socket
////////////////////////////////////////////////////////////////////////////////
tcp_listener_t *tcp_socket_get_listener(tcp_socket_t *socket);

////////////////////////////////////////////////////////////////////////////////
/// \brief Creates a tcp_listener (not yet listening)
///
/// \returns A newly allocated/socket-ed listener
////////////////////////////////////////////////////////////////////////////////
tcp_listener_t *tcp_listener_create(void);

////////////////////////////////////////////////////////////////////////////////
/// \brief Destroys a tcp_listener object (free + close)
///
/// \param listener Listener object to destroy
////////////////////////////////////////////////////////////////////////////////
void tcp_listener_destroy(tcp_listener_t *listener);

////////////////////////////////////////////////////////////////////////////////
/// \brief Starts listener binding and listening on port and address
///
/// \param listener Listener to listen on
/// \param port Port to listen on
/// \param address Address to listen on
///
/// \return SOCKET_DONE on success, SOCKET_ERROR otherwise and epinet-perror set
////////////////////////////////////////////////////////////////////////////////
socket_status_t tcp_listener_listen(
    tcp_listener_t *listener, unsigned short port, ip_address_t address);

////////////////////////////////////////////////////////////////////////////////
/// \brief Accepts a connection and places it in connected.
///
/// \param listener Listener to accept on
/// \param connected Pointer to a (tcp_socket_t *). It can point to a valid
/// tcp_socket or NULL but itself cant be NULL.
///
/// \return SOCKET_DONE on success, SOCKET_ERROR otherwise and epinet-perror set
////////////////////////////////////////////////////////////////////////////////
socket_status_t tcp_listener_accept(
    tcp_listener_t *listener, tcp_socket_t **connected);

#endif /* !TCP_LISTENER_H_ */

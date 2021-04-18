/*
** EPITECH PROJECT, 2021
** Epinet
** File description:
** socket
*/

#ifndef SOCKET_H_
#define SOCKET_H_

#include <netinet/ip.h>
#include <stdbool.h>
#include <sys/types.h>

typedef int fd_t;

#define SOCKET(socket) ((socket_t *)socket)
#define NO_SOCKET -1

typedef enum
{
    SOCKET_TCP = SOCK_STREAM,
    SOCKET_UDP = SOCK_DGRAM
} socket_type_t;

typedef enum
{
    SOCKET_ERROR = -1,
    SOCKET_DONE,
    SOCKET_NOT_READY,
    SOCKET_PARTIAL,
    SOCKET_DISCONNECTED,
} socket_status_t;

typedef struct
{
    socket_type_t type;
    fd_t socket;
    bool is_blocking;
} socket_t;

////////////////////////////////////////////////////////////////////////////////
/// \brief Converts errno to a socket_status
///
/// \return Socket status from errno
////////////////////////////////////////////////////////////////////////////////
socket_status_t socket_get_status(void);

////////////////////////////////////////////////////////////////////////////////
/// \brief Creates a socket of type \a type.
///
/// Allocates and calls socket().
///
/// \param type The type of socket to create. (SOCKET_TCP or SOCKET_UDP)
///
/// \return The created socket on success, NULL on error and epinet_perror set.
////////////////////////////////////////////////////////////////////////////////
socket_t *socket_create(socket_type_t type);

////////////////////////////////////////////////////////////////////////////////
/// \brief Creates an empty socket (without actual socket) of type \a type.
///
/// It allocates the socket but doesnt call socket(). Used to accept().
///
/// \param type The type of socket to create. (SOCKET_TCP or SOCKET_UDP)
///
/// \return The created socket on success, NULL on error and epinet_perror set.
////////////////////////////////////////////////////////////////////////////////
socket_t *socket_create_empty(socket_type_t type);

////////////////////////////////////////////////////////////////////////////////
/// \brief Destroys the \a socket object. Closes it and frees it.
///
/// \param type The socket object to destroy.
////////////////////////////////////////////////////////////////////////////////
void socket_destroy(socket_t *sock);

////////////////////////////////////////////////////////////////////////////////
/// \brief Sets the blocking-ness of a socket.
///
/// TODO Real implementation for outside epitech
///
/// \param sock Socket of which to set the blocking-ness.
/// \param blocking Boolean of blocking state to set
////////////////////////////////////////////////////////////////////////////////
void socket_set_blocking(socket_t *sock, bool blocking);

////////////////////////////////////////////////////////////////////////////////
/// \brief Gets the blocking-ness of a socket
///
/// TODO Real implementation for outside epitech
///
/// \param sock Socket of which to get the blocking-ness.
////////////////////////////////////////////////////////////////////////////////
bool socket_is_blocking(socket_t *sock);

#endif /* !SOCKET_H_ */

/*
** EPITECH PROJECT, 2021
** Epinet
** File description:
** socket_selector
*/

#ifndef SOCKET_SELECTOR_H_
#define SOCKET_SELECTOR_H_

#include <sys/select.h>

#include <tcp_listener.h>
#include <tcp_socket.h>
#include <timeout.h>
#include <udp_socket.h>

typedef struct
{
    fd_set master;   ///< Master set, it is used to save the fd's to watch
    fd_set ready;    ///< Ready set, passed in param to select, stores ready fd
    fd_t max_socket; ///< Value of the biggest fd (in number only)
} socket_selector_t;

typedef enum
{
    WATCH_RD = 1,                     ///< Watch for read
    WATCH_WRT = 1 << 1,               ///< Watch for write
    WATCH_EXC = 1 << 2,               ///< Watch for exceptions
    WATCH_RW = WATCH_RD | WATCH_WRT,  ///< Watch for read or write
    WATCH_RE = WATCH_RD | WATCH_EXC,  ///< Watch for read or exceptions
    WATCH_WE = WATCH_WRT | WATCH_EXC, ///< Watch for write or exceptions
    WATCH_RWE = WATCH_RD | WATCH_WRT | WATCH_EXC ///< Watch for everything
} watch_t;

typedef int selector_status_t;

#define SELECTOR_ERROR -1
#define SELECTOR_OK 0

///////////////////////////////////////////////////////////////////////////////
/// \brief Create a new selector
///
/// \return Newly created (allocated) selector
///////////////////////////////////////////////////////////////////////////////
socket_selector_t *socket_selector_create(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Create a new selector from an other (Copy constructor)
///
/// \param selector Selector object to copy from
///
/// \return Newly created (allocated) selector which is a copy of \a selector
///////////////////////////////////////////////////////////////////////////////
socket_selector_t *socket_selector_copy(const socket_selector_t *selector);

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroy (free) a selector object
///
/// \param selector Selector object to destroy
///////////////////////////////////////////////////////////////////////////////
void socket_selector_destroy(socket_selector_t *selector);

///////////////////////////////////////////////////////////////////////////////
/// \brief Add a socket to the set of socket a selector watches
///
/// \param selector Selector to which we want to add the \a socket
/// \param socket Socket to add to the \a selector
/// \return SELECTOR_ERROR on error and sets error for epinet_perror(),
/// SELECTOR_OK on success.
///////////////////////////////////////////////////////////////////////////////
selector_status_t socket_selector_add_socket(
    socket_selector_t *selector, socket_t *socket);

///////////////////////////////////////////////////////////////////////////////
/// \brief Remove a socket for the set of socker a selector watches
///
/// \param selector Selector from which we want to remove the \a socket
/// \param socket Socket to remove from the \a selector
///
/// \return SELECTOR_ERROR on error and sets error for epinet_perror(),
/// SELECTOR_OK on success.
///////////////////////////////////////////////////////////////////////////////
selector_status_t socket_selector_remove_socket(
    socket_selector_t *selector, socket_t *socket);

///////////////////////////////////////////////////////////////////////////////
/// \brief Clear/Empty a selector
///
/// This removes all sockets from the selector but does not destroy the object
/// it can still be used with new sockets
///
/// \param selector Selector to clear
///
/// \return SELECTOR_ERROR on error and sets error for epinet_perror(),
/// SELECTOR_OK on success.
///////////////////////////////////////////////////////////////////////////////
selector_status_t socket_selector_clear(socket_selector_t *selector);

///////////////////////////////////////////////////////////////////////////////
/// \brief Wait for a socket to be ready or poll a selector.
///
/// \param selector Selector to use for waiting/polling
/// \param timeout Time to use for the timeout in ms. (NO_TIMEOUT for blocking)
/// \param watch One of the watch_t describing what actions to wait for (W/R/E)
///
/// \return SELECTOR_ERROR on error and sets error for epinet_perror(),
/// the number of sockets ready otherwise.
///////////////////////////////////////////////////////////////////////////////
selector_status_t socket_selector_wait(
    socket_selector_t *selector, timeout_t timeout, watch_t watch);

///////////////////////////////////////////////////////////////////////////////
/// \brief Check if a socket is ready in a selector
///
/// \param selector Selector to check from
/// \param socket Socket to check for
///
/// \return True if socket is ready, false otherwise
///////////////////////////////////////////////////////////////////////////////
bool socket_selector_is_socket_ready(
    const socket_selector_t *selector, socket_t *socket);

#endif /* !SOCKET_SELECTOR_H_ */

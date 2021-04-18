/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** create
*/

#include <tcp_socket.h>

tcp_socket_t *tcp_socket_create(void)
{
    return TCP_SOCKET(socket_create(SOCKET_TCP));
}

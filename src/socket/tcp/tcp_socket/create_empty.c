/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** create_empty
*/

#include <tcp_socket.h>

tcp_socket_t *tcp_socket_create_empty(void)
{
    return TCP_SOCKET(socket_create_empty(SOCKET_TCP));
}

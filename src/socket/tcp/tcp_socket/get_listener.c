/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** get_listener
*/

#include <tcp_listener.h>

tcp_listener_t *tcp_socket_get_listener(tcp_socket_t *socket)
{
    return (tcp_listener_t *)socket;
}

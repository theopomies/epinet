/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** destroy
*/

#include <tcp_listener.h>

void tcp_listener_destroy(tcp_listener_t *listener)
{
    return tcp_socket_destroy((tcp_socket_t *)listener);
}

/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** create
*/

#include <tcp_listener.h>

tcp_listener_t *tcp_listener_create(void)
{
    return TCP_LISTENER(tcp_socket_create());
}

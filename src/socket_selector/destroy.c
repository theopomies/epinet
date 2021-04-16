/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** socket_selector_destroy
*/

#include <stdlib.h>

#include <socket_selector.h>

void socket_selector_destroy(socket_selector_t *selector)
{
    if (selector)
        free(selector);
}

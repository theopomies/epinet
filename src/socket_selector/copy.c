/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** socket_selector_copy
*/

#include <stdlib.h>
#include <string.h>

#include <socket_selector.h>

socket_selector_t *socket_selector_copy(const socket_selector_t *selector)
{
    socket_selector_t *new_selector = socket_selector_create();

    if (!new_selector)
        return NULL;
    if (!selector)
        return new_selector;
    memcpy(new_selector, selector, sizeof(socket_selector_t));
    return new_selector;
}

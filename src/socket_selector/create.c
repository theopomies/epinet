/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** socket_selector_create
*/

#include <stdlib.h>

#include <error.h>
#include <socket_selector.h>

socket_selector_t *socket_selector_create(void)
{
    socket_selector_t *selector = malloc(sizeof(socket_selector_t));

    if (!selector) {
        set_error("socket_selector_create: malloc error");
        return NULL;
    }
    socket_selector_clear(selector);
    return selector;
}

/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** epinet_perror
*/

#include <stdio.h>

#include <error.h>

void epinet_perror(const char *message)
{
    const char *error = get_error();

    if (!message)
        return;
    fprintf(stderr, "%s", message);
    if (!error || !*error) {
        fprintf(stderr, "\n");
        return;
    }
    fprintf(stderr, ": %s\n", error);
}

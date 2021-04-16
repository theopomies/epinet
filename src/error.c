/*
** EPITECH PROJECT, 2021
** Epinet
** File description:
** error
*/

#include <error.h>

#include <stdbool.h>
#include <stdio.h>
#include <strings.h>

char *get_error(void)
{
    static char error[MAX_ERROR_LEN];
    static bool init = false;

    if (!init) {
        bzero(error, MAX_ERROR_LEN);
        init = true;
    }
    return error;
}

void epinet_perror(const char *message)
{
    const char *error = get_error();

    fprintf(stderr, "%s", message);
    if (!error || !*error) {
        fprintf(stderr, "\n");
        return;
    }
    fprintf(stderr, ": %s\n", error);
}

void set_error(const char *message)
{
    char *error = get_error();

    strncpy(error, message, MAX_ERROR_LEN);
    error[MAX_ERROR_LEN - 1] = '\0';
}
/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** set_error
*/

#include <string.h>
#include <strings.h>

#include <error.h>

void set_error(const char *message)
{
    char *error = get_error();

    if (!message) {
        memset(error, 0, MAX_ERROR_LEN);
        return;
    }
    strncpy(error, message, MAX_ERROR_LEN);
    error[MAX_ERROR_LEN - 1] = '\0';
}

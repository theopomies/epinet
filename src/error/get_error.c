/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** get_error
*/

#include <stdbool.h>
#include <string.h>

#include <error.h>

char *get_error(void)
{
    static char error[MAX_ERROR_LEN];
    static bool init = false;

    if (!init) {
        memset(error, 0, MAX_ERROR_LEN);
        init = true;
    }
    return error;
}

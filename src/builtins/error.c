/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** error
*/
#include <string.h>
#include <errno.h>
#include "header.h"

int check_error(char *dest)
{
    if (errno == 2) {
        if (dest != NULL)
            write(2, dest, strlen(dest));
        write(2, ": No such file or directory.\n", 29);
        return 1;
    }
    if (errno == 20) {
        if (dest != NULL)
            write(2, dest, strlen(dest));
        write(2, ": Not a directory.\n", 19);
        return 1;
    }
    if (errno == 13) {
        if (dest != NULL)
            write(2, dest, strlen(dest));
        write(2, ": Permission denied.\n", 21);
        return 1;
    }
    perror(dest);
    return 1;
}
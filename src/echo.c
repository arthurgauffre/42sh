/*
** EPITECH PROJECT, 2023
** echo
** File description:
** echo
*/

#include <sys/stat.h>
#include <stdbool.h>

int is_echo(void)
{
    struct stat s;
    int fd = 0;
    fstat(fd, &s);
    if (S_ISFIFO(s.st_mode))
        return true;
    return false;
}

/*
** EPITECH PROJECT, 2023
** write_in_file
** File description:
** write the string given in a file
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

#include "my.h"

int write_in_file(char *name, char *content)
{
    FILE *fd = fopen(name, "a+");
    if (fd == NULL)
        return 84;
    if (fprintf(fd, "%s", content) < 0)
        return 84;
    fclose(fd);
    return 0;
}

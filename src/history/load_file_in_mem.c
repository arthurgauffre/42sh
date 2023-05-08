/*
** EPITECH PROJECT, 2022
** load_file_in_mem
** File description:
** load a file like a map and allocate it in the memory
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

char *load_file_in_mem(char const *filepath)
{
    struct stat s;
    int fd;
    if (filepath == NULL)
        return NULL;
    if ((fd = open(filepath, O_RDONLY)) == -1)
        return NULL;
    stat(filepath, &s);
    char *buffer = malloc(sizeof(char) * (s.st_size + 1));
    if (buffer == NULL)
        return NULL;
    buffer[s.st_size] = '\0';
    read(fd, buffer, s.st_size);
    if (buffer == NULL)
        return NULL;
    close(fd);
    return buffer;
}

/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-42sh-arthur.gauffre
** File description:
** load_fd_in_str
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "header.h"
#include "struct.h"
#include "my.h"


static char *add_str_read_in_end_str(char *str, char *str_read, int nb_copy,
int len)
{
    for (int i = 0; i < nb_copy; i += 1) {
        str[len + i] = str_read[i];
    }
    return str;
}

static char *add_str_to_end_str(char *str, char *str_read, int nb_copy)
{
    int len = my_strlen(str);
    char *str_tmp = malloc(sizeof(char) * (len + 1));
    if (str_tmp == NULL)
        return NULL;
    str_tmp[0] = '\0';
    str_tmp = strcat(str_tmp, str);
    free(str);
    str = malloc(sizeof(char) * (len + nb_copy + 1));
    if (str == NULL)
        return NULL;
    str[0] = '\0';
    str = strcat(str, str_tmp);
    str = add_str_read_in_end_str(str, str_read, nb_copy, len);
    str[len + nb_copy] = '\0';
    free(str_tmp);
    return str;
}

char *load_fd_in_str(int fd)
{
    char *str = malloc(sizeof(char) * (1));
    str[0] = '\0';
    ssize_t nread = 1;
    char buffer[100];
    while ((nread = read(fd, buffer, 100)) != 0) {
        str = add_str_to_end_str(str, buffer, nread);
        if (str == NULL)
            return NULL;
        if (nread < 100)
            return str;
    }
    return str;
}

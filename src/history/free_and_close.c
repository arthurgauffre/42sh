/*
** EPITECH PROJECT, 2023
** free_and_close
** File description:
** free and close all the history
*/

#include <stdio.h>
#include <stdlib.h>

void free_and_close(FILE *fd, char *history, char *time, char *path)
{
    fclose(fd);
    free(history);
    free(time);
    free(path);
}

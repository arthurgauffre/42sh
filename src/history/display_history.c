/*
** EPITECH PROJECT, 2023
** display_history
** File description:
** display the history
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

char *get_path_history(char *path_history)
{
    char *path = malloc(sizeof(char) * strlen(path_history) + 15);
    path = strcpy(path, path_history);
    path = strcat(path, "/.history_42sh");
    return path;
}

void display_history(char *path_history)
{
    char *path = get_path_history(path_history);
    char *history = load_file_in_mem(path);
    printf("%s\n", history);
    free(history);
    free(path);
}

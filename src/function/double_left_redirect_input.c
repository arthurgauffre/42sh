/*
** EPITECH PROJECT, 2023
** double_left_redirect_input
** File description:
** wait for the right input in double redirect
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "header.h"

char *double_left_redirect_input(char *ending_input)
{
    char *line = NULL;
    char *str = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, stdin)) != -1) {
        if (strncmp(line, ending_input, strlen(ending_input)) == 0) {
            free(line);
            return str;
        }
        if (str == NULL) {
            str = my_realloc(str, strlen(line) + 1);
            strcpy(str, line);
        } else {
            str = my_realloc(str, strlen(line) + 1);
            strcat(str, line);
        }
    }
    free(line);
    return NULL;
}

/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get_text
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "struct.h"
#include "header.h"

char **add_str(char **tab, char *new_var);

char **add_line(char *line, ssize_t linesize, char **text, char *new_line)
{
    if (line[linesize - 1] == '\n') {
        line[linesize - 1] = '\0';
        text = add_str(text, line);
    } else {
        new_line = malloc(linesize + 1);
        for (int j = 0; j < linesize; j++) {
            new_line[j] = line[j];
        }
        new_line[linesize] = '\0';
        text = add_str(text, new_line);
    }
    return text;
}

char **get_text(sh_data_t *data)
{
    char *history_path = get_path_history(data->pwd);
    if (access(history_path, F_OK) != 0)
        return NULL;
    FILE *file = fopen(history_path, "rb");
    char **text = NULL;
    char *line = NULL;
    size_t len = 0;
    char *new_line = NULL;
    ssize_t linesize = 0;
    while ((linesize = getline(&line, &len, file)) != -1) {
        text = add_line(line + 13, linesize - 13, text, new_line);
    }
    free(history_path);
    fclose(file);
    return text;
}

/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell2-arthur.gauffre
** File description:
** null_command
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "header.h"

int is_null_pipe(char **command_tab, int i)
{
    char **pipe_tab = NULL;
    pipe_tab = my_str_to_word_array(command_tab[i], '|');
    for (int j = 0; pipe_tab[j] != NULL; j++) {
        if (all_space_or_tab(pipe_tab[j]) == 0) {
            free_tab(pipe_tab);
            free_tab(command_tab);
            return 1;
        }
    }
    free_tab(pipe_tab);
    return 0;
}

int is_null_command(char *parser)
{
    char **command_tab = NULL;
    if (parser[0] == '|')
        return 1;
    command_tab = my_str_to_word_array(parser, ';');
    for (int i = 0; command_tab[i] != NULL; i++) {
        if (command_tab[i][0] == '|' ||
        command_tab[i][my_strlen(command_tab[i]) - 1] == '|') {
            free_tab(command_tab);
            return 1;
        }
        if (is_null_pipe(command_tab, i) == 1) {
            return 1;
        }
    }
    free_tab(command_tab);
    return 0;
}

int invalid_null_function(char *parser)
{
    write(2, "Invalid null command.\n", 22);
    free(parser);
    return 1;
}

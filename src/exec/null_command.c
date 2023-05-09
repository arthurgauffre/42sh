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

static int bad_redirection(char *str)
{
    char **tab = my_str_to_word_array(str, '>');
    if (nb_chevron(str) > 2) {
        free_tab(tab);
        return 1;
    }
    if (my_tablen(tab) > 2) {
        free_tab(tab);
        return 1;
    }
    free_tab(tab);
    return 0;
}

static int is_null_pipe_or_redirection(char **command_tab, int i)
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

static int bad_separator(char *str)
{
    char **tab = split_str_to_tab_with_wtr_separator(str, "&&");
    for (int i = 0; tab[i] != NULL; i++) {
        if (all_space_or_tab(tab[i]) == 0) {
            free_tab(tab);
            return 1;
        }
    }
    free_tab(tab);
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
        command_tab[i][my_strlen(command_tab[i]) - 1] == '|' ||
        is_null_pipe_or_redirection(command_tab, i) == 1 ||
        bad_separator(command_tab[i]) == 1) {
            free_tab(command_tab);
            return 1;
        }
        if (bad_redirection(command_tab[i]) == 1) {
            free_tab(command_tab);
            return 2;
        }

    }
    free_tab(command_tab);
    return 0;
}

int invalid_null_function(char *parser, int value)
{
    if (value == 1)
        my_puterror("Invalid null command.\n");
    if (value == 2)
        my_puterror("Ambiguous output redirect.\n");
    free(parser);
    return 1;
}

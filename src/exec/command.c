/*
** EPITECH PROJECT, 2023
** command
** File description:
** command
*/

#include <unistd.h>
#include <stdlib.h>
#include "struct.h"
#include "header.h"
#include "my.h"

void pipes_connexion(sh_data_t sh_data)
{
    if (sh_data.nb_actual_command == 0) {
        dup2(sh_data.pipes[sh_data.nb_actual_command][1], STDOUT_FILENO);
        close(sh_data.pipes[sh_data.nb_actual_command][0]);
        close(sh_data.pipes[sh_data.nb_actual_command][1]);
    } else if (sh_data.nb_actual_command == (sh_data.nb_commands - 1)) {
        dup2(sh_data.pipes[sh_data.nb_actual_command - 1][0], STDIN_FILENO);
        close(sh_data.pipes[sh_data.nb_actual_command - 1][0]);
        close(sh_data.pipes[sh_data.nb_actual_command - 1][1]);
    } else {
        dup2(sh_data.pipes[sh_data.nb_actual_command][1], STDOUT_FILENO);
        dup2(sh_data.pipes[sh_data.nb_actual_command - 1][0], STDIN_FILENO);
        close(sh_data.pipes[sh_data.nb_actual_command][0]);
        close(sh_data.pipes[sh_data.nb_actual_command][1]);
        close(sh_data.pipes[sh_data.nb_actual_command - 1][0]);
        close(sh_data.pipes[sh_data.nb_actual_command - 1][1]);
    }
}

int nb_chevron(char *str)
{
    int nb_chevron = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '>')
            nb_chevron++;
    }
    return nb_chevron;
}

static char *init_redirection(char *parser, sh_data_t *data)
{
    char **tab = NULL;
    char **tab_file;
    data->redirection.filename = NULL;
    data->redirection.simple_redirection = 0;
    tab = my_str_to_word_array(parser, '>');
    if (my_tablen(tab) > 1) {
        tab_file = my_str_to_word_array(tab[1], ' ');
        data->redirection.filename = my_strdup(tab_file[0]);
        if (nb_chevron(parser) == 1)
            data->redirection.simple_redirection = 1;
        else
            data->redirection.double_redirection = 1;
        data->redirection.pipe_redirection = malloc(sizeof(int) * 2);
        free(parser);
        parser = my_strdup(tab[0]);
        free_tab(tab_file);
    }
    free_tab(tab);
    return parser;
}

int loop_pipe(sh_data_t *data)
{
    int return_value = 0;

    for (int i = 0; i < data->nb_commands - 1; i++)
        data->pipes[i] = malloc(sizeof(int) * 2);
    for (int i = 0; data->tab_pipe[i] != NULL; i++) {
        data->tab_pipe[i] = init_redirection(data->tab_pipe[i], data);
        data->tab_parser = my_str_to_word_array(data->tab_pipe[i], ' ');
        data->nb_actual_command = i;
        if ((return_value = check_and_launch_mybuiltins(data)) == 2)
            return_value = check_and_launch_binary(data);
        free_tab(data->tab_parser);
    }
    free_int_tab(data->pipes);
    return return_value;
}

int check_and_launch_command(sh_data_t *data)
{
    data->old_parser = data->parser;
    if (all_space_or_tab(data->command) == 1) {
        return loop_and(data);
    }
    return 0;
}

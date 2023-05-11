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

int loop_pipe(sh_data_t *data)
{
    for (int i = 0; i < data->nb_commands - 1; i++)
        data->pipes[i] = malloc(sizeof(int) * 2);
    for (int i = 0; data->tab_pipe[i] != NULL; i++) {
        if (check_exit(data->tab_pipe[i]) == 1) {
            data->exit_shell = 0;
            free_int_tab(data->pipes);
            free(data->pwd);
            return exit_shell(*data);
        }
        data->tab_pipe[i] = init_redirection(data->tab_pipe[i], data);
        data->tab_parser = my_str_to_word_array(data->tab_pipe[i], ' ');
        data->nb_actual_command = i;
        globing(data);
        free_tab(data->tab_parser);
    }
    free_int_tab(data->pipes);
    return data->return_value;
}

int check_and_launch_command(sh_data_t *data)
{
    data->old_parser = data->parser;
    if (all_space_or_tab(data->command) == 1) {
        return loop_or(data);
    }
    return data->return_value;
}

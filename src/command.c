/*
** EPITECH PROJECT, 2023
** command
** File description:
** command
*/

#include <unistd.h>
#include <stdlib.h>
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

int loop_pipe(char **tab_command, char *parser, sh_data_t sh_data, char **tab)
{
    int return_value = 0;
    for (int i = 0; i < sh_data.nb_commands - 1; i++)
        sh_data.pipes[i] = malloc(sizeof(int) * 2);
    for (int i = 0; tab[i] != NULL; i++) {
        sh_data.tab_parser = my_str_to_word_array(tab[i], ' ');
        sh_data.nb_actual_command = i;
        if ((return_value = check_and_launch_mybuiltins(tab_command,
        sh_data)) == 2)
            return_value = check_and_launch_binary(tab_command, sh_data, tab);
        free_tab(sh_data.tab_parser);
    }
    free_int_tab(sh_data.pipes);
    free_tab(tab);
    return return_value;
}

int check_and_launch_command(char **tab_command, char *parser, char ***env,
char *old_parser)
{
    sh_data_t sh_data = {0};
    char **tab = NULL;
    parser = replace_tab_with_space(parser);
    tab = my_str_to_word_array(parser, '|');
    if (tab == NULL)
        return KO;
    sh_data.tab_pipe = tab;
    sh_data.env = env;
    sh_data.nb_commands = my_tablen(tab);
    sh_data.pipes = malloc(sizeof(int *) * sh_data.nb_commands);
    sh_data.pipes[sh_data.nb_commands - 1] = NULL;
    sh_data.old_parser = old_parser;
    return loop_pipe(tab_command, parser, sh_data, tab);
}

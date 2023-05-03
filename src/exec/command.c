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

static char *init_redirection(char *parser, sh_data_t *sh_data)
{
    char **tab = NULL;
    char **tab_file;
    sh_data->redirection.filename = NULL;
    sh_data->redirection.simple_redirection = 0;
    tab = my_str_to_word_array(parser, '>');
    if (my_tablen(tab) > 1) {
        tab_file = my_str_to_word_array(tab[1], ' ');
        sh_data->redirection.filename = my_strdup(tab_file[0]);
        if (nb_chevron(parser) == 1)
            sh_data->redirection.simple_redirection = 1;
        else
            sh_data->redirection.double_redirection = 1;
        sh_data->redirection.pipe_redirection = malloc(sizeof(int) * 2);
        free(parser);
        parser = my_strdup(tab[0]);
        free_tab(tab_file);
    }
    free_tab(tab);
    return parser;
}

int loop_pipe(char **tab_command, sh_data_t sh_data, char **tab)
{
    int return_value = 0;

    for (int i = 0; i < sh_data.nb_commands - 1; i++)
        sh_data.pipes[i] = malloc(sizeof(int) * 2);
    for (int i = 0; tab[i] != NULL; i++) {
        tab[i] = init_redirection(tab[i], &sh_data);
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
    if (all_space_or_tab(parser) == 1) {
        parser = replace_tab_with_space(parser);
        tab = my_str_to_word_array(parser, '|');
        if (tab == NULL)
            return KO;
        sh_data = init_pipe_data(env, tab, old_parser, sh_data);
        return loop_pipe(tab_command, sh_data, tab);
    }
    return 0;
}

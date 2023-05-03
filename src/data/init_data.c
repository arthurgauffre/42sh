/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-42sh-arthur.gauffre
** File description:
** init_data
*/

#include <unistd.h>
#include <stdlib.h>
#include "struct.h"
#include "header.h"

sh_data_t init_pipe_data(char ***env, char **tab , char *old_parser,
sh_data_t sh_data)
{
    sh_data.tab_pipe = tab;
    sh_data.env = env;
    sh_data.nb_commands = my_tablen(tab);
    sh_data.pipes = malloc(sizeof(int *) * sh_data.nb_commands);
    sh_data.pipes[sh_data.nb_commands - 1] = NULL;
    sh_data.old_parser = old_parser;
    return sh_data;
}

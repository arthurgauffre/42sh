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

sh_data_t *init_pipe_data(sh_data_t *data, char **tab)
{
    data->tab_pipe = tab;
    data->nb_commands = my_tablen(tab);
    data->pipes = malloc(sizeof(int *) * data->nb_commands);
    data->pipes[data->nb_commands - 1] = NULL;
    return data;
}

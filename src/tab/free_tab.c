/*
** EPITECH PROJECT, 2023
** free_tab
** File description:
** free the tab
*/

#include <stdlib.h>
#include "header.h"

void free_child_env(char **tab_command, sh_data_t sh_data, char **tab)
{
    free_tab(tab);
    free_tab(sh_data.tab_pipe);
    free_tab(tab_command);
    free(sh_data.old_parser);
    free_int_tab(sh_data.pipes);
    free_tab(*sh_data.env);
    free(sh_data.pwd);
}

void free_int_tab(int **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

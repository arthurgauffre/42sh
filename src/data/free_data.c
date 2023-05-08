/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-42sh-arthur.gauffre
** File description:
** free_data
*/

#include <stdlib.h>
#include "struct.h"
#include "header.h"

void free_data(sh_data_t data)
{
    if (data.tab_parser)
        free_tab(data.tab_parser);
    if (data.old_parser)
        free(data.old_parser);
    if (data.pipes)
        free_int_tab(data.pipes);
    if (data.tab_command)
        free_tab(data.tab_command);
    if (data.tab_and)
        free_tab(data.tab_and);
    if (data.tab_or)
        free_tab(data.tab_or);
    if (data.env)
        free_tab(*data.env);
    if (data.redirection.filename)
        free(data.redirection.filename);
    if (data.tab_pipe)
        free_tab(data.tab_pipe);
    if (data.pwd)
        free(data.pwd);
}

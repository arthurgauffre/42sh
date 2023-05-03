/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-42sh-arthur.gauffre
** File description:
** free_data
*/

#include <stdlib.h>
#include "struct.h"
#include "header.h"

void free_data(sh_data_t sh_data)
{
    if (sh_data.tab_parser)
        free_tab(sh_data.tab_parser);
    if (sh_data.old_parser)
        free(sh_data.old_parser);
    if (sh_data.pipes)
        free_int_tab(sh_data.pipes);
    if (sh_data.env)
        free_tab(*sh_data.env);
    if (sh_data.redirection.filename)
        free(sh_data.redirection.filename);
}

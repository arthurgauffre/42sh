/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** loop_separators
*/

#include <unistd.h>
#include <stdlib.h>
#include "struct.h"
#include "header.h"
#include "my.h"

static int loop_or(sh_data_t *data)
{
    char **tab = NULL;
    char **tab_or = NULL;
    data->command_and = replace_tab_with_space(data->command_and);
    tab_or = split_str_to_tab_with_wtr_separator(data->command_and, "||");
    data->tab_or = tab_or;
    for (int i = 0; tab_or[i] != NULL; i++) {
        tab = my_str_to_word_array(tab_or[i], '|');
        if (tab == NULL) {
            return KO;
        }
        data = init_pipe_data(data, tab);
        data->return_value = loop_pipe(data);
        free_tab(data->tab_pipe);
        if (data->return_value == 0) {
            free_tab(data->tab_or);
            return data->return_value;
        }
    }
    free_tab(data->tab_or);
    return data->return_value;
}

int loop_and(sh_data_t *data)
{
    char **tab_and = NULL;
    data->command = replace_tab_with_space(data->command);
    tab_and = split_str_to_tab_with_wtr_separator(data->command, "&&");
    data->tab_and = tab_and;
    for (int i = 0; tab_and[i] != NULL; i++) {
        data->command_and = tab_and[i];
        data->return_value = loop_or(data);
        if (data->return_value != 0) {
            free_tab(data->tab_and);
            return data->return_value;
        }
    }
    free_tab(data->tab_and);
    return data->return_value;
}

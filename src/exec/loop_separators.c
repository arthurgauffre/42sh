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

int loop_and(sh_data_t *data)
{
    char **tab = NULL;
    data->tab_and = split_str_to_tab_with_wtr_separator
    (data->command_and, "&&");
    for (int i = 0; data->tab_and[i] != NULL; i++) {
        tab = my_str_to_word_array(data->tab_and[i], '|');
        if (tab == NULL)
            return KO;
        data = init_pipe_data(data, tab);
        data->return_value = loop_pipe(data);
        free_tab(data->tab_pipe);
        if (data->return_value != 0) {
            free_tab(data->tab_and);
            return data->return_value;
        }
    }
    free_tab(data->tab_and);
    return data->return_value;
}

int loop_or(sh_data_t *data)
{
    data->command = replace_tab_with_space(data->command);
    data->tab_or = split_str_to_tab_with_wtr_separator(data->command, "||");
    for (int i = 0; data->tab_or[i] != NULL; i++) {
        data->command_and = data->tab_or[i];
        data->return_value = loop_and(data);
        if (data->return_value == 0) {
            free_tab(data->tab_or);
            return data->return_value;
        }
    }
    free_tab(data->tab_or);
    return data->return_value;
}

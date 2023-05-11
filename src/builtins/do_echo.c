/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** do_echo
*/

#include <string.h>
#include "header.h"

int do_echo(sh_data_t *data)
{
    if (data->tab_parser[1] == NULL)
        return KO;
    if (my_strcmp(data->tab_parser[1], "$?") == 0) {
        printf("%d\n", data->return_value);
        return 0;
    }
    if (my_strcmp(data->tab_parser[1], "-n") == 0) {
        if (data->tab_parser[2] != NULL)
            printf("%s", data->tab_parser[2]);
        return 0;
    }
    printf("%s\n", data->tab_parser[1]);
    return 0;
}

/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** globing
*/
#include <stdio.h>
#include <string.h>
#include <glob.h>
#include "struct.h"
#include "header.h"
char **add_str(char **tab, char *new_var);

int star_in_str(char *str)
{
    if (str == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '*' || str[i] == '?' || str[i] == '[' || str[i] == ']')
            return 1;
    }
    return 0;
}

int launcher_globing(char **temp, int i, sh_data_t *data)
{
    glob_t result;
    glob(temp[i], 0, NULL, &result);
    if (result.gl_pathc == 0)
        return 1;
    free(temp[i]);
    temp[i] = strdup(result.gl_pathv[0]);
    for (size_t i = 1; i < result.gl_pathc; i++) {
        data->tab_parser = add_str(data->tab_parser, result.gl_pathv[i]);
    }
    if ((data->return_value = check_and_launch_mybuiltins(data)) == 2)
        data->return_value = check_and_launch_binary(data);
    globfree(&result);
    return 0;
}

int globing(sh_data_t *data)
{
    char **temp = data->tab_parser;
    int res = 1;
    for (int i = 0; temp[i] != NULL; i++) {
        if (star_in_str(temp[i]) == 1) {
            res = launcher_globing(temp, i, data);
            break;
        }
    }
    if (res == 0)
        return res;
    if ((data->return_value = check_and_launch_mybuiltins(data)) == 2)
        data->return_value = check_and_launch_binary(data);
    return 0;
}

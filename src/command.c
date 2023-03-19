/*
** EPITECH PROJECT, 2023
** command
** File description:
** command
*/

#include <unistd.h>
#include <stdlib.h>
#include "header.h"
#include "my.h"

int check_and_launch_command(char *parser, char ***env)
{
    int return_value = 0;
    char **tab = NULL;
    parser = replace_tab_with_space(parser);
    tab = my_str_to_word_array(parser, ' ');
    if (tab == NULL)
        return KO;
    if ((return_value = check_and_launch_mybuiltins(tab, env)) == 2)
        return_value = check_and_launch_binary(tab, *env, parser);
    free(parser);
    free_tab(tab);
    return return_value;
}

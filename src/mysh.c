/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** mysh
*/

#include <unistd.h>
#include "header.h"

int mysh(char **my_env)
{
    int return_value = 0;
    return_value = start_shell(&my_env);
    free_tab(my_env);
    return return_value;
}

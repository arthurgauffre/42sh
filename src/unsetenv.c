/*
** EPITECH PROJECT, 2023
** unsetenv
** File description:
** unsetenv
*/

#include <stdlib.h>
#include <unistd.h>
#include "header.h"
#include "my.h"

int delete_var_env(char **tab, char ***env, int i, int j)
{
    int last = 0;
    if (my_strncmp(tab[i], (*env)[j], my_strlen(tab[i])) == 0 &&
    (*env)[j][my_strlen(tab[i])] == '=') {
        last = my_tablen((*env)) - 1;
        free((*env)[j]);
        (*env)[j] = (*env)[last];
        (*env)[last] = NULL;
    }
    return 0;
}

int unsetenv_builtin(char **tab, char ***env)
{
    if (my_tablen(tab) == 1) {
        my_putstr("unsetenv: Too few arguments.\n");
        return 1;
    }
    for (int i = 1; tab[i] != NULL; i++) {
        for (int j = 0; (*env)[j]; j++) {
            delete_var_env(tab, env , i, j);
        }
    }
    return 1;
}

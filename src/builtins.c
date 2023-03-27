/*
** EPITECH PROJECT, 2023
** builtins
** File description:
** bulitins
*/

#include <unistd.h>
#include <stdlib.h>
#include "header.h"
#include "my.h"

int env_builtin(char **tab, char **env)
{
    if (my_tablen(tab) == 1) {
        for (int i = 0; env[i] != NULL; i++) {
            my_putstr(env[i]);
            write(1, "\n", 1);
        }
        return 0;
    }
    return 0;
}

int setenv_builtin(char **tab, char ***env)
{
    if (my_tablen(tab) == 1)
        return env_builtin(tab, *env);
    if (my_tablen(tab) > 3) {
        my_puterror("setenv: Too many arguments.\n");
        return 1;
    }
    if (my_str_isalphanum(tab[1]) == 0) {
        my_puterror("setenv: Variable name must contain alphanumeric \
characters.\n");
        return 1;
    }
    if (my_tablen(tab) == 2)
        return add_var_env_with_no_value(tab, env);
    if (my_tablen(tab) == 3)
        return add_var_env_with_value(tab, env);
    return 0;
}

int check_and_launch_mybuiltins(sh_data_t sh_data)
{
    if (sh_data.tab_parser == NULL)
        return 2;
    if (my_strcmp(sh_data.tab_parser[0], "cd") == 0)
        return cd_builtin(sh_data.tab_parser, *sh_data.env);
    if (my_strcmp(sh_data.tab_parser[0], "unsetenv") == 0)
        return unsetenv_builtin(sh_data.tab_parser, sh_data.env);
    if (my_strcmp(sh_data.tab_parser[0], "setenv") == 0)
        return setenv_builtin(sh_data.tab_parser, sh_data.env);
    if (my_strcmp(sh_data.tab_parser[0], "env") == 0)
        return env_builtin(sh_data.tab_parser, *sh_data.env);
    return 2;
}

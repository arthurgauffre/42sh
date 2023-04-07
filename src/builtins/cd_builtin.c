/*
** EPITECH PROJECT, 2023
** cd_builtin
** File description:
** cd_builtins
*/

#include <unistd.h>
#include <stdlib.h>
#include "header.h"
#include "my.h"

int cd_error_and_cd_home(char **tab)
{
    if (tab[1] != NULL && my_strcmp(tab[1], "-") == 0 && my_tablen(tab) > 2) {
        my_puterror("Usage: cd [-plvn][-|<dir>].\n");
        return 1;
    }
    if (my_tablen(tab) > 2) {
        my_puterror("cd: Too many arguments.\n");
        return 1;
    }
    return 0;
}

int cd_with_file(char **tab, char **env)
{
    if (chdir(tab[1]) != -1) {
        char *pwd = get_pwd();
        env = modif_var_env(env, "OLDPWD=", get_inside_var_env(env, "PWD="));
        env = modif_var_env(env, "PWD=", pwd);
        free(pwd);
    } else {
        my_puterror(tab[1]);
        my_puterror(": No such file or directory.\n");
        return 1;
    }
    return 0;
}

int cd_tild_slash(char **tab, char **env)
{
    char *str = malloc(sizeof(char) *
    (my_strlen(get_inside_var_env(env, "HOME=")) + my_strlen(tab[1])));
    my_strcpy(str, get_inside_var_env(env, "HOME="));
    tab[1] = my_str_cut(tab[1], 1, 0);
    my_strcpy(&str[my_strlen(str)], tab[1]);
    if (chdir(str) != -1) {
        char *pwd = get_pwd();
        env = modif_var_env(env, "OLDPWD=", get_inside_var_env(env, "PWD="));
        env = modif_var_env(env, "PWD=", pwd);
        free(pwd);
        free(str);
    } else {
        my_puterror(str);
        my_puterror(": No such file or directory.\n");
        free(str);
        return 1;
    }
    return 0;
}

int cd_tild(char **env)
{
    chdir(get_inside_var_env(env, "HOME="));
    char *pwd = get_pwd();
    env = modif_var_env(env, "OLDPWD=", get_inside_var_env(env, "PWD="));
    env = modif_var_env(env, "PWD=", pwd);
    free(pwd);
    return 0;
}

int cd_builtin(char **tab, char **env)
{
    if (cd_error_and_cd_home(tab) == 1)
        return 1;
    if (my_tablen(tab) == 1 ||
    (my_tablen(tab) == 2 && my_strcmp(tab[1], "~") == 0)) {
        return cd_tild(env);
    }
    if (my_tablen(tab) == 2 && my_strcmp(tab[1], "-") == 0) {
        chdir(get_inside_var_env(env, "OLDPWD="));
        char *pwd = get_pwd();
        env = modif_var_env(env, "OLDPWD=", get_inside_var_env(env, "PWD="));
        env = modif_var_env(env, "PWD=", pwd);
        free(pwd);
        return 0;
    }
    if (my_tablen(tab) == 2 && my_strncmp(tab[1], "~/", 2) == 0)
        return cd_tild_slash(tab, env);
    return cd_with_file(tab, env);
}

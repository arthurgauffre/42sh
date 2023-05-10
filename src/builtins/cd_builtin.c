/*
** EPITECH PROJECT, 2023
** cd_builtin
** File description:
** cd_builtins
*/

#include <unistd.h>
#include <stdlib.h>
#include "header.h"
#include "struct.h"
#include "my.h"

int cd_error_and_cd_home(sh_data_t *data)
{
    if (data->tab_parser[1] != NULL && my_strcmp(data->tab_parser[1], "-") == 0
    && my_tablen(data->tab_parser) > 2) {
        my_puterror("Usage: cd [-plvn][-|<dir>].\n");
        return 1;
    }
    if (my_tablen(data->tab_parser) > 2) {
        my_puterror("cd: Too many arguments.\n");
        return 1;
    }
    return 0;
}

int cd_with_file(char **tab, char ***env)
{
    if (get_inside_var_env(*env, "OLDPWD=") == NULL)
        add_var_env_with_no_value((char *[]){"false", "OLDPWD", NULL}, env);
    if (chdir(tab[1]) != -1) {
        char *pwd = get_pwd();
        *env = modif_var_env(*env, "OLDPWD=",
        get_inside_var_env(*env, "PWD="));
        *env = modif_var_env(*env, "PWD=", pwd);
        free(pwd);
    } else {
        my_puterror(tab[1]);
        my_puterror(": No such file or directory.\n");
        return 1;
    }
    return 0;
}

int cd_tild_slash(char **tab, char ***env)
{
    char *str = malloc(sizeof(char) *
    (my_strlen(get_inside_var_env(*env, "HOME=")) + my_strlen(tab[1])));
    my_strcpy(str, get_inside_var_env(*env, "HOME="));
    tab[1] = my_str_cut(tab[1], 1, 0);
    my_strcpy(&str[my_strlen(str)], tab[1]);
    if (get_inside_var_env(*env, "OLDPWD=") == NULL)
        add_var_env_with_no_value((char *[]){"false", "OLDPWD", NULL}, env);
    if (chdir(str) != -1) {
        char *pwd = get_pwd();
        *env = modif_var_env(*env, "OLDPWD=", get_inside_var_env(*env, "PWD="));
        *env = modif_var_env(*env, "PWD=", pwd);
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

int cd_tild(char ***env)
{
    if (get_inside_var_env(*env, "OLDPWD=") == NULL)
        add_var_env_with_no_value((char *[]){"false", "OLDPWD", NULL}, env);
    chdir(get_inside_var_env(*env, "HOME="));
    char *pwd = get_pwd();
    *env = modif_var_env(*env, "OLDPWD=", get_inside_var_env(*env, "PWD="));
    *env = modif_var_env(*env, "PWD=", pwd);
    free(pwd);
    return 0;
}

int cd_builtin(sh_data_t *data)
{
    if (cd_error_and_cd_home(data) == 1)
        return 1;
    if (my_tablen(data->tab_parser) == 1 ||
    (my_tablen(data->tab_parser) == 2 && my_strcmp(data->tab_parser[1], "~")
    == 0))
        return cd_tild(data->env);
    if (my_tablen(data->tab_parser) == 2 && my_strcmp(data->tab_parser[1], "-")
    == 0) {
        return cd_dash(data);
    }
    if (my_tablen(data->tab_parser) == 2 &&
    my_strncmp(data->tab_parser[1], "~/", 2) == 0)
        return cd_tild_slash(data->tab_parser, data->env);
    return cd_with_file(data->tab_parser, data->env);
}

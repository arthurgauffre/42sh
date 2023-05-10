/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** cd_dash
*/

#include <unistd.h>
#include <stdlib.h>
#include "header.h"
#include "struct.h"
#include "my.h"

int cd_dash(sh_data_t *data)
{
    char *old_pwd = get_inside_var_env((*data->env), "OLDPWD=");
    if (old_pwd == NULL) {
        write(2, ": No such file or directory.\n", 29);
        return 1;
    }
    chdir(old_pwd);
    char *pwd = get_pwd();
    (*data->env) = modif_var_env((*data->env), "OLDPWD=",
    get_inside_var_env((*data->env), "PWD="));
    (*data->env) = modif_var_env((*data->env), "PWD=", pwd);
    free(pwd);
    return 0;
}

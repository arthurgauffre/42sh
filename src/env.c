/*
** EPITECH PROJECT, 2023
** env
** File description:
** env
*/

#include <stdlib.h>
#include <unistd.h>
#include "header.h"
#include "my.h"

char *inside_var_env(char *var_env)
{
    int nb = 0;
    for (; var_env[nb] != '='; nb++);
    return &(var_env[nb + 1]);
}

char *get_inside_var_env(char **env, char *var_env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], var_env, my_strlen(var_env)) == 0)
            return inside_var_env(env[i]);
    }
    return NULL;
}

char *get_new_var_env_value(char *old_var_env, char *var_env,
char *new_var_env_value)
{
    free(old_var_env);
    char *new_var_env = malloc(sizeof(char ) * (my_strlen(var_env) +
    my_strlen(new_var_env_value) + 1));
    my_strcpy(new_var_env, var_env);
    my_strcpy(&(new_var_env[my_strlen(new_var_env)]), new_var_env_value);
    return new_var_env;
}

char **modif_var_env(char **env, char *var_env, char *new_var_env_value)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], var_env, my_strlen(var_env)) == 0) {
            env[i] = get_new_var_env_value(env[i], var_env, new_var_env_value);
        }
    }
    return env;
}

char **my_envcpy(char **env)
{
    char **my_env = malloc(sizeof(char *) * (my_tablen(env) + 1));
    if (my_env == NULL)
        return NULL;
    my_env[my_tablen(env)] = NULL;
    for (int i = 0; env[i] != NULL; i++) {
        my_env[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        my_env[i][my_strlen(env[i])] = '\0';
        my_strcpy(my_env[i], env[i]);
    }
    return my_env;
}

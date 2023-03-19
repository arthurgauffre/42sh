/*
** EPITECH PROJECT, 2023
** setenv
** File description:
** setenv
*/

#include <stdlib.h>
#include <unistd.h>
#include "header.h"
#include "my.h"

char *add_new_var_env(char *new_var_env, char *var_env, char *var_env_value)
{
    new_var_env = malloc(sizeof(char) * (my_strlen(var_env) +
    my_strlen(var_env_value) + 3));
    if (new_var_env == NULL)
        return NULL;
    my_strcpy(new_var_env, var_env);
    new_var_env[my_strlen(new_var_env) + 1] = '\0';
    new_var_env[my_strlen(new_var_env)] = '=';
    my_strcpy(&(new_var_env[my_strlen(new_var_env)]), var_env_value);
    return new_var_env;
}

char **create_new_var_env(char ***env, char *var_env, char *var_env_value)
{
    char **env_copy = malloc(sizeof(char*) * (my_tablen(*env) + 2));
    if (env_copy == NULL)
        return NULL;
    env_copy[my_tablen(*env) + 1] = NULL;
    env_copy[my_tablen(*env)] = NULL;
    for (int i = 0; (*env)[i] != NULL; i++) {
        env_copy[i] = malloc(sizeof(char) * (my_strlen((*env)[i]) + 1));
        my_strcpy(env_copy[i], (*env)[i]);
    }
    free_tab(*env);
    env_copy[my_tablen(env_copy)] =
    add_new_var_env(env_copy[my_tablen(env_copy)],
    var_env, var_env_value);
    *env = env_copy;
    for (int i = 0; env_copy[i] != NULL; i++)
        (*env)[i] = env_copy[i];
    return (*env);
}

char *modif_var_env_value(char *old_var_env, char *var_env,
char *new_var_env_value)
{
    free(old_var_env);
    char *new_var_env = malloc(sizeof(char ) * (my_strlen(var_env) +
    my_strlen(new_var_env_value) + 2));
    my_strcpy(new_var_env, var_env);
    new_var_env[my_strlen(new_var_env) + 1] = '\0';
    new_var_env[my_strlen(new_var_env)] = '=';
    my_strcpy(&(new_var_env[my_strlen(new_var_env)]), new_var_env_value);
    return new_var_env;
}

int add_var_env_with_value(char **tab, char ***env)
{
    for (int i = 0; (*env)[i] != NULL; i++) {
        if (my_strncmp((*env)[i], tab[1], my_strlen(tab[1])) == 0 &&
        (*env)[i][my_strlen(tab[1])] == '=') {
            (*env)[i] = modif_var_env_value((*env)[i], tab[1], tab[2]);
            return 0;
        }
    }
    *env = create_new_var_env(env, tab[1], tab[2]);
    return 0;
}

int add_var_env_with_no_value(char **tab, char ***env)
{
    for (int i = 0; (*env)[i] != NULL; i++) {
        if (my_strncmp((*env)[i], tab[1], my_strlen(tab[1])) == 0 &&
        (*env)[i][my_strlen(tab[1])] == '=') {
            (*env)[i] = modif_var_env_value((*env)[i], tab[1], "\0");
            return 0;
        }
    }
    *env = create_new_var_env(env, tab[1], "\0");
    return 0;
}

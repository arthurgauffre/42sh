/*
** EPITECH PROJECT, 2023
** builtins
** File description:
** bulitins
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "header.h"
#include "my.h"

static int env_child_exec(sh_data_t *data)
{
    if (data->nb_commands > 1) {
        pipes_connexion(*data);
    }
    if (my_tablen(data->tab_parser) == 1) {
        for (int i = 0; (*data->env)[i] != NULL; i++) {
            my_putstr((*data->env)[i]);
            write(1, "\n", 1);
        }
        free_child_env(data->tab_command, *data, data->tab_parser);
        exit(0);
    }
    my_puterror("env: '");
    my_puterror(data->tab_parser[1]);
    my_puterror("': No such file or directory\n");
    free_child_env(data->tab_command, *data, data->tab_parser);
    exit(1);
}

static int env_parent_exec(pid_t pid, int wstatus, sh_data_t data)
{
    if (data.nb_actual_command > 0) {
        close(data.pipes[data.nb_actual_command - 1][0]);
        close(data.pipes[data.nb_actual_command - 1][1]);
    }
    waitpid(pid, &wstatus, 0);
    return WEXITSTATUS(wstatus);
}

int env_builtin(sh_data_t *data)
{
    int wstatus = 0;
    if (data->tab_parser == NULL)
        return 84;
    if (data->nb_actual_command < data->nb_commands - 1)
        pipe(data->pipes[data->nb_actual_command]);
    pid_t pid = fork();
    if (pid < 0)
        return 84;
    if (pid == 0) {
        return env_child_exec(data);
    } else
        return env_parent_exec(pid, wstatus, *data);
}

int setenv_builtin(sh_data_t *data)
{
    if (my_tablen(data->tab_parser) == 1)
        return env_builtin(data);
    if (data->nb_commands != 1)
        return 2;
    if (my_tablen(data->tab_parser) > 3) {
        my_puterror("setenv: Too many arguments.\n");
        return 1;
    }
    if (my_str_isalphanum(data->tab_parser[1]) == 0) {
        my_puterror("setenv: Variable name must contain alphanumeric \
characters.\n");
        return 1;
    }
    if (my_tablen(data->tab_parser) == 2)
        return add_var_env_with_no_value(data->tab_parser, data->env);
    if (my_tablen(data->tab_parser) == 3)
        return add_var_env_with_value(data->tab_parser, data->env);
    return 0;
}

int check_and_launch_mybuiltins(sh_data_t *data)
{
    if (data->tab_parser == NULL)
        return 2;
    if (data->nb_commands == 1 &&
    my_strcmp(data->tab_parser[0], "cd") == 0)
        return cd_builtin(data);
    if (data->nb_commands == 1 &&
    my_strcmp(data->tab_parser[0], "unsetenv") == 0)
        return unsetenv_builtin(data->tab_parser, data->env);
    if (my_strcmp(data->tab_parser[0], "setenv") == 0)
        return setenv_builtin(data);
    if (my_strcmp(data->tab_parser[0], "env") == 0)
        return env_builtin(data);
    if (my_strcmp(data->tab_parser[0], "!") == 0) {
        display_history(data->pwd, data);
        return OK;
    }
    return 2;
}

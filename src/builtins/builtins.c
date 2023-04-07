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

static int env_child_exec(char **tab_command, sh_data_t sh_data, char **env,
char **tab)
{
    if (sh_data.nb_commands > 1) {
        pipes_connexion(sh_data);
    }
    if (my_tablen(tab) == 1) {
        for (int i = 0; env[i] != NULL; i++) {
            my_putstr(env[i]);
            write(1, "\n", 1);
        }
        free_child_env(tab_command, sh_data, tab);
        exit(0);
    }
    my_puterror("env: '");
    my_puterror(tab[1]);
    my_puterror("': No such file or directory\n");
    free_child_env(tab_command, sh_data, tab);
    exit(1);
}

static int env_parent_exec(pid_t pid, int wstatus, sh_data_t sh_data)
{
    if (sh_data.nb_actual_command > 0) {
        close(sh_data.pipes[sh_data.nb_actual_command - 1][0]);
        close(sh_data.pipes[sh_data.nb_actual_command - 1][1]);
    }
    waitpid(pid, &wstatus, 0);
    return WEXITSTATUS(wstatus);
}

int env_builtin(char **tab_command, sh_data_t sh_data, char **tab, char **env)
{
    int wstatus = 0;
    if (tab == NULL)
        return 84;
    if (sh_data.nb_actual_command < sh_data.nb_commands - 1)
        pipe(sh_data.pipes[sh_data.nb_actual_command]);
    pid_t pid = fork();
    if (pid < 0)
        return 84;
    if (pid == 0) {
        return env_child_exec(tab_command, sh_data, env, tab);
    } else
        return env_parent_exec(pid, wstatus, sh_data);
}

int setenv_builtin(char **tab_command, sh_data_t sh_data, char **tab,
char ***env)
{
    if (my_tablen(tab) == 1)
        return env_builtin(tab_command, sh_data, tab, *env);
    if (sh_data.nb_commands != 1)
        return 2;
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

int check_and_launch_mybuiltins(char **tab_command, sh_data_t sh_data)
{
    if (sh_data.tab_parser == NULL)
        return 2;
    if (sh_data.nb_commands == 1 &&
    my_strcmp(sh_data.tab_parser[0], "cd") == 0)
        return cd_builtin(sh_data.tab_parser, *sh_data.env);
    if (sh_data.nb_commands == 1 &&
    my_strcmp(sh_data.tab_parser[0], "unsetenv") == 0)
        return unsetenv_builtin(sh_data.tab_parser, sh_data.env);
    if (my_strcmp(sh_data.tab_parser[0], "setenv") == 0)
        return setenv_builtin(tab_command, sh_data, sh_data.tab_parser,
        sh_data.env);
    if (my_strcmp(sh_data.tab_parser[0], "env") == 0)
        return env_builtin(tab_command, sh_data, sh_data.tab_parser,
        *(sh_data.env));
    return 2;
}

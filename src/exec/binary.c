/*
** EPITECH PROJECT, 2023
** binary
** File description:
** binary
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include "struct.h"
#include "header.h"
#include "my.h"

int exec_with_path(char **tab, char **env, char *path)
{
    char *path_with_benary = malloc(sizeof(char) *
    (my_strlen(path) + my_strlen(tab[0]) + 2));
    path_with_benary[my_strlen(path) + my_strlen(tab[0]) + 1] = '\0';
    my_strcpy(path_with_benary, path);
    path_with_benary[my_strlen(path_with_benary) + 1] = '\0';
    path_with_benary[my_strlen(path_with_benary)] = '/';
    my_strcat(path_with_benary, tab[0]);
    execve(path_with_benary, tab, env);
    free(path_with_benary);
    return 0;
}

static int child_exec(sh_data_t *data)
{
    char **path = my_str_to_word_array(
    get_inside_var_env(*data->env, "PATH="), ':');
    execve(data->tab_parser[0], data->tab_parser, *data->env);
    if (errno == 8) {
        fprintf(stderr, "%s: Exec format error. Wrong Architecture.\n",
        data->parser);
        free_tab(path);
        free_data(*data);
        exit(126);
    }
    if (slash_in_str(data->tab_parser[0]) == 0) {
        for (int i = 0; path[i] != NULL; i++) {
            exec_with_path(data->tab_parser, *data->env, path[i]);
        }
    }
    display_child_error(data->tab_parser[0]);
    free_tab(path);
    free_data(*data);
    exit(1);
}

void put_stdout_in_file(redirection_t redirection)
{
    char *str = NULL;
    str = load_fd_in_str(redirection.pipe_redirection_right[0]);
    if (redirection.simple_redirection_right == 1)
        redirection.fd_open = open(redirection.filename, O_CREAT | O_WRONLY |
        O_TRUNC, S_IRWXU);
    if (redirection.double_redirection_right == 1)
        redirection.fd_open = open(redirection.filename, O_CREAT | O_WRONLY |
        O_APPEND, S_IRWXU);
    write(redirection.fd_open, str, my_strlen(str));
    free(redirection.filename);
    free(redirection.pipe_redirection_right);
    free(str);
}

static int parent_exec(pid_t pid, int wstatus, sh_data_t data)
{
    if (data.nb_actual_command > 0) {
        close(data.pipes[data.nb_actual_command - 1][0]);
        close(data.pipes[data.nb_actual_command - 1][1]);
    }
    if (data.nb_commands < 1 || data.nb_actual_command ==
    data.nb_commands - 1)
        waitpid(pid, &wstatus, WUNTRACED);
    else
        waitpid(pid, &wstatus, WNOHANG | WUNTRACED);
    if ((data.nb_actual_command == data.nb_commands - 1) &&
    (data.redirection.filename != NULL))
        put_stdout_in_file(data.redirection);
    display_exec_error(wstatus);
    return WEXITSTATUS(wstatus) + WTERMSIG(wstatus) + WCOREDUMP(wstatus);
}

int check_and_launch_binary(sh_data_t *data)
{
    int wstatus = 0;
    if (data->tab_parser == NULL)
        return 84;
    if ((data->nb_actual_command == data->nb_commands - 1) &&
    (data->redirection.filename != NULL))
        pipe(data->redirection.pipe_redirection_right);
    if (data->nb_actual_command < data->nb_commands - 1)
        pipe(data->pipes[data->nb_actual_command]);
    pid_t pid = fork();
    if (pid < 0)
        return 84;
    if (pid == 0) {
        child_connection(*data);
        return child_exec(data);
    } else {
        return parent_exec(pid, wstatus, *data);
    }
}

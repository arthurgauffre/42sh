/*
** EPITECH PROJECT, 2023
** binary
** File description:
** binary
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
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

static int child_exec(char **tab_command, sh_data_t sh_data, char **tab)
{
    char **path = my_str_to_word_array(
        get_inside_var_env(*sh_data.env, "PATH="), ':');
    execve(tab[0], sh_data.tab_parser, *sh_data.env);
    for (int i = 0; path[i] != NULL; i++) {
        exec_with_path(sh_data.tab_parser, *sh_data.env, path[i]);
    }
    my_puterror(sh_data.tab_parser[0]);
    my_puterror(": Command not found.\n");
    free_tab(path);
    free_tab(tab);
    free_tab(sh_data.tab_parser);
    free_tab(tab_command);
    free(sh_data.old_parser);
    free_int_tab(sh_data.pipes);
    free_tab(*sh_data.env);
    exit(1);
}

static int parent_exec(pid_t pid, int wstatus, sh_data_t sh_data)
{
    if (sh_data.nb_actual_command > 0) {
        close(sh_data.pipes[sh_data.nb_actual_command - 1][0]);
        close(sh_data.pipes[sh_data.nb_actual_command - 1][1]);
    }
    waitpid(pid, &wstatus, 0);
    if ((WTERMSIG(wstatus)) == 11)
        my_puterror("Segmentation fault");
    if ((WTERMSIG(wstatus)) == 8)
        my_puterror("Floating exception");
    if ((WCOREDUMP(wstatus)) == 128)
        my_puterror(" (core dumped)\n");
    if (WTERMSIG(wstatus) == 11 && WCOREDUMP(wstatus) != 128)
        my_puterror("\n");
    return WEXITSTATUS(wstatus) + WTERMSIG(wstatus) + WCOREDUMP(wstatus);
}

int check_and_launch_binary(char **tab_command, sh_data_t sh_data, char **tab)
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
        if (sh_data.nb_commands > 1) {
            pipes_connexion(sh_data);
        }
        return child_exec(tab_command, sh_data, tab);
    } else {
        return parent_exec(pid, wstatus, sh_data);
    }
}

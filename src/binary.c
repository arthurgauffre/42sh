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

int child_exec(char **tab, char **env, char *parser)
{
    char **path = my_str_to_word_array(get_inside_var_env(env, "PATH="), ':');
    execve(tab[0], tab, env);
    for (int i = 0; path[i] != NULL; i++) {
        exec_with_path(tab, env, path[i]);
    }
    my_puterror(tab[0]);
    my_puterror(": Command not found.\n");
    free_tab(path);
    free_tab(tab);
    free_tab(env);
    free(parser);
    exit(1);
}

int check_and_launch_binary(char **tab, char **env, char *parser)
{
    int wstatus = 0;
    if (tab == NULL)
        return 84;
    pid_t pid = fork();
    if (pid < 0)
        return 84;
    if (pid == 0) {
        return child_exec(tab, env, parser);
    } else {
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
}

/*
** EPITECH PROJECT, 2023
** display_history
** File description:
** display the history
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "header.h"
#include "struct.h"

char *get_path_history(char *path_history)
{
    char *path = malloc(sizeof(char) * strlen(path_history) + 15);
    path = strcpy(path, path_history);
    path = strcat(path, "/.history_42sh");
    return path;
}

int display_history_child(char *path_history, sh_data_t *data)
{
    if (data->nb_commands > 1)
        pipes_connexion(*data);
    char *path = get_path_history(path_history);
    char *history = load_file_in_mem(path);
    write(1, history, strlen(history));
    write(1, "\n", 1);
    free(history);
    free(path);
    free_data(*data);
    exit(0);
}

int display_history(sh_data_t *data)
{
    int wstatus = 0;
    if (data->tab_parser == NULL)
        return 84;
    if (data->nb_actual_command < data->nb_commands - 1)
        pipe(data->pipes[data->nb_actual_command]);
    pid_t pid = fork();
    if (pid < 0)
        return KO;
    if (pid == 0)
        return display_history_child(data->pwd, data);
    if (data->nb_actual_command > 0) {
        close(data->pipes[data->nb_actual_command - 1][0]);
        close(data->pipes[data->nb_actual_command - 1][1]);
    }
    waitpid(pid, &wstatus, 0);
    return WEXITSTATUS(wstatus);
}

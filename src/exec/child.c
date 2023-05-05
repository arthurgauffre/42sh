/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-42sh-arthur.gauffre
** File description:
** child
*/

#include <unistd.h>
#include "header.h"
#include "struct.h"
#include "my.h"

void child_connection(sh_data_t data)
{
    if (data.nb_commands > 1) {
        pipes_connexion(data);
    }
    if ((data.nb_actual_command == data.nb_commands - 1) &&
    (data.redirection.filename != NULL)) {
        dup2(data.redirection.pipe_redirection[1], STDOUT_FILENO);
        close(data.redirection.pipe_redirection[0]);
        close(data.redirection.pipe_redirection[1]);
    }
}

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

void child_connection(sh_data_t sh_data)
{
    if (sh_data.nb_commands > 1) {
        pipes_connexion(sh_data);
    }
    if ((sh_data.nb_actual_command == sh_data.nb_commands - 1) &&
    (sh_data.redirection.filename != NULL)) {
        dup2(sh_data.redirection.pipe_redirection[1], STDOUT_FILENO);
        close(sh_data.redirection.pipe_redirection[0]);
        close(sh_data.redirection.pipe_redirection[1]);
    }
}

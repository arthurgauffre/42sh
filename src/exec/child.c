/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-42sh-arthur.gauffre
** File description:
** child
*/

#include <unistd.h>
#include <fcntl.h>
#include "header.h"
#include "struct.h"
#include "my.h"

static void redirection_connection(sh_data_t data)
{
    int fd = 0;
    if ((data.nb_actual_command == data.nb_commands - 1) &&
    (data.redirection.simple_redirection_left == 1)) {
        pipe(data.redirection.pipe_redirection_left);
        fd = open(data.redirection.filename_or_ending_input, O_RDONLY);
        dup2(fd, STDIN_FILENO);
        close(fd);
    }
    if ((data.nb_actual_command == data.nb_commands - 1) &&
    (data.redirection.double_redirection_left == 1)) {
        pipe(data.redirection.pipe_redirection_left);
        fd = open("my_left_double_redirection", O_RDONLY);
        dup2(fd, STDIN_FILENO);
        close(fd);
    }
}

void child_connection(sh_data_t data)
{
    if (data.nb_commands > 1) {
        pipes_connexion(data);
    }
    if ((data.nb_actual_command == data.nb_commands - 1) &&
    (data.redirection.filename != NULL)) {
        dup2(data.redirection.pipe_redirection_right[1], STDOUT_FILENO);
        close(data.redirection.pipe_redirection_right[0]);
        close(data.redirection.pipe_redirection_right[1]);
    }
    redirection_connection(data);
}

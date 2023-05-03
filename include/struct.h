/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-42sh-arthur.gauffre
** File description:
** struct
*/


#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct redirection_s {
        int fd_open;
        int *pipe_redirection;
        char *filename;
        int simple_redirection;
        int double_redirection;
    } redirection_t;

    typedef struct sh_data_s {
        char *old_parser;
        char **tab_parser;
        char **tab_pipe;
        char ***env;
        int nb_commands;
        int nb_actual_command;
        int **pipes;
        redirection_t redirection;
    } sh_data_t;

#endif /* !STRUCT_H_ */

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
        int *pipe_redirection_right;
        int *pipe_redirection_left;
        char *filename;
        char *filename_or_ending_input;
        char *str_double_redirection;
        int simple_redirection_right;
        int double_redirection_right;
        int simple_redirection_left;
        int double_redirection_left;
    } redirection_t;

    typedef struct sh_data_s {
        char *parser;
        char *old_parser;
        char *command;
        char *command_and;
        char **tab_and;
        char *command_or;
        char *pwd;
        char **tab_or;
        char **tab_command;
        char **tab_parser;
        char **tab_pipe;
        char **tab;
        char ***env;
        int null_command;
        int exit_shell;
        int nb_commands;
        int return_value;
        int nb_actual_command;
        int **pipes;
        redirection_t redirection;
    } sh_data_t;

    typedef struct spliter_s {
        int len_tab;
        char *temp_str;
        char *tab_str;
        char **tab;
        int i;
        int start;
        int len;
        int end;
    } spliter_t;

    typedef struct history_data_s {
        int nbr;
        char *time;
        char *command;
    }history_data_t;

    typedef struct history_s {
        history_data_t data;
        struct history_s *next;
        struct history_s *prev;
    }history_t;

#endif /* !STRUCT_H_ */

/*
** EPITECH PROJECT, 2023
** structures
** File description:
** all the struct of the project
*/

#ifndef STRUCT_H
    #define STRUCT_H

    typedef struct sh_data_s {
        char **tab_parser;
        char ***env;
        char **tab_pipe;
        int **pipes;
        char *old_parser;
        int nb_commands;
        int nb_actual_command;
    } sh_data_t;

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

#endif /* !STRUCT_H */

/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** init_redirection
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "struct.h"
#include "header.h"
#include "my.h"

static char *cut_redirection_left_in_str(char *str)
{
    int len_redirection_left = 0;
    int len_redirection_right = 0;
    int nb_right_chevron = nb_chevron_right(str);
    char **tab_redirection_left = my_str_to_word_array(str, '<');
    char **tab_redirection_right = my_str_to_word_array(str, '>');
    len_redirection_left = my_strlen(tab_redirection_left[0]);
    if (tab_redirection_right[1] != NULL)
        len_redirection_right = my_strlen(tab_redirection_right[1]);
    free(str);
    str = malloc(sizeof(char) *
    (len_redirection_left + len_redirection_right + nb_right_chevron + 1));
    str = strcpy(str, tab_redirection_left[0]);
    if (tab_redirection_right[1] != NULL) {
        if (nb_right_chevron > 1)
            str = strcat(str, ">>\0");
        else
            str = strcat(str, ">\0");
        str = strcat(str, tab_redirection_right[1]);
    }
    return str;
}

static char *init_redirection_left(redirection_t *redirection, char *parser)
{
    char **tab = NULL;
    char **tab_file_or_ending_input;
    tab = my_str_to_word_array(parser, '<');
    if (my_tablen(tab) > 1) {
        tab_file_or_ending_input = my_str_to_word_array(tab[1], ' ');
        redirection->filename_or_ending_input =
        my_strdup(tab_file_or_ending_input[0]);
        if (nb_chevron_left(parser) == 1)
            redirection->simple_redirection_left = 1;
        else
            redirection->double_redirection_left = 1;
        redirection->pipe_redirection_left = malloc(sizeof(int) * 2);
        free_tab(tab_file_or_ending_input);
        parser = cut_redirection_left_in_str(parser);
    }
    free_tab(tab);
    return parser;
}

static char *init_redirection_right(redirection_t *redirection, char *parser)
{
    char **tab = NULL;
    char **tab_file;
    tab = my_str_to_word_array(parser, '>');
    if (my_tablen(tab) > 1) {
        tab_file = my_str_to_word_array(tab[1], ' ');
        redirection->filename = my_strdup(tab_file[0]);
        if (nb_chevron_right(parser) == 1)
            redirection->simple_redirection_right = 1;
        else
            redirection->double_redirection_right = 1;
        redirection->pipe_redirection_right = malloc(sizeof(int) * 2);
        free(parser);
        parser = my_strdup(tab[0]);
        free_tab(tab_file);
    }
    free_tab(tab);
    return parser;
}

char *init_redirection(char *parser, sh_data_t *data)
{
    int fd = 0;
    data->redirection.filename = NULL;
    data->redirection.str_double_redirection = NULL;
    data->redirection.double_redirection_left = 0;
    data->redirection.simple_redirection_left = 0;
    data->redirection.simple_redirection_right = 0;
    parser = init_redirection_left(&data->redirection, parser);
    parser = init_redirection_right(&data->redirection, parser);
    if (data->redirection.double_redirection_left == 1) {
        fd = open("my_left_double_redirection", O_CREAT | O_WRONLY | O_TRUNC,
        S_IRWXU);
        data->redirection.str_double_redirection =
        double_left_redirect_input(data->redirection.filename_or_ending_input);
        write(fd, data->redirection.str_double_redirection,
        my_strlen(data->redirection.str_double_redirection));
        free(data->redirection.str_double_redirection);
    }
    return parser;
}

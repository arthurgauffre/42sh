/*
** EPITECH PROJECT, 2023
** shell
** File description:
** shell
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "header.h"
#include "my.h"

static int exit_shell(char *parser, int return_value)
{
    free(parser);
    if (!is_echo())
        my_putstr("exit\n");
    return return_value;
}

int check_exit(char *parser)
{
    if (my_strlen(parser) > 3 && my_strncmp(parser, "exit", 4) == 0 &&
    (parser[4] == ' ' || parser[4] == '\0')) {
        if (all_space_or_tab(&parser[4]) == 1) {
            write(2, "exit: Expression Syntax.\n", 25);
            return 2;
        }
        return 1;
    }
    return 0;
}

int exit_shell_with_command(char *parser, int return_value)
{
    my_putstr("exit\n");
    free(parser);
    return return_value;
}

int loop_command(char *parser, int return_value, char ***env, int exit_value)
{
    char **tab = NULL;
    if (!my_strlen(parser) == 0 && all_space_or_tab(parser) == 1 &&
    exit_value != 2) {
        tab = my_str_to_word_array(parser, ';');
        for (int i = 0; tab[i] != NULL; i++)
            return_value = check_and_launch_command(tab[i], env);
        free(tab);
        free(parser);
    } else
        free(parser);
    return return_value;
}

int start_shell(char ***env)
{
    int exit_value = 0;
    int return_value = 0;
    char *parser = NULL;
    while (1) {
        if (!is_echo())
            prompt();
        if ((parser = read_terminal()) == NULL)
            return exit_shell(parser, return_value);
        if (parser[my_strlen(parser) - 1] == '\n')
            parser = my_str_cut(parser, 1, 1);
        if ((exit_value = check_exit(parser)) == 1) {
            return exit_shell_with_command(parser, return_value);
        }
        return_value = loop_command(parser, return_value, env, exit_value);
    }
    return return_value;
}

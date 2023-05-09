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
#include <string.h>
#include "struct.h"
#include "header.h"
#include "my.h"

static int exit_shell(sh_data_t data)
{
    free(data.parser);
    if (!is_echo())
        my_putstr("exit\n");
    return data.return_value;
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

int loop_command(sh_data_t *data, int exit_value)
{
    if (!my_strlen(data->parser) == 0 && all_space_or_tab(data->parser) == 1 &&
    exit_value != 2) {
        data->tab_command = my_str_to_word_array(data->parser, ';');
        for (int i = 0; data->tab_command[i] != NULL; i++) {
            data->command = data->tab_command[i];
            data->return_value = check_and_launch_command(data);
        }
        free_tab(data->tab_command);
        free(data->parser);
    } else
        free(data->parser);
    return data->return_value;
}

int start_shell(char ***env)
{
    int exit_value = 0;
    sh_data_t data = init_data(env);
    while (1) {
        if (!is_echo())
            print_prompt("$> ");
        if ((data.parser = read_terminal()) == NULL)
            return exit_shell(data);
        if (data.parser[my_strlen(data.parser) - 1] == '\n')
            data.parser = my_str_cut(data.parser, 1, 1);
        if (is_null_command(data.parser) == 0 &&
        (exit_value = check_exit(data.parser)) == 1)
            return exit_shell_with_command(data.parser, data.return_value);
        if ((data.return_value = is_null_command(data.parser)) != 0)
            data.return_value =
            invalid_null_function(data.parser, data.return_value);
        else
            data.return_value = loop_command(&data, exit_value);
    }
    return data.return_value;
}

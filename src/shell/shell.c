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
    char **tab = my_str_to_word_array(parser, ' ');
    if (my_strcmp(tab[0], "exit") == 0) {
        if (my_tablen(tab) == 1) {
            free_tab(tab);
            return 1;
        }
        write(2, "exit: Expression Syntax.\n", 25);
    }
    free_tab(tab);
    return 0;
}

int loop_command(sh_data_t *data)
{
    if (!my_strlen(data->parser) == 0 && all_space_or_tab(data->parser) == 1) {
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
    sh_data_t data = init_data(env);
    while (data.exit_shell == 1) {
        if (!is_echo())
            print_prompt("$> ");
        if ((data.parser = read_terminal()) == NULL)
            return exit_shell(data);
        if (data.parser[my_strlen(data.parser) - 1] == '\n')
            data.parser = my_str_cut(data.parser, 1, 1);
        if ((data.return_value = is_null_command(data.parser)) != 0)
            data.return_value =
            invalid_null_function(data.parser, data.return_value);
        else
            data.return_value = loop_command(&data);
    }
    return data.return_value;
}

/*
** EPITECH PROJECT, 2023
** read_terminal
** File description:
** read the terminal's input
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
#include "struct.h"


void print_prompt(char const *prompt_str)
{
    if (!is_echo()) {
        prompt(prompt_str);
    }
}

char *read_terminal(sh_data_t *data, char const *prompt)
{
    if (!is_echo())
        print_prompt(prompt);
    char *line = NULL;
    size_t len = 0;
    if (isatty(STDIN_FILENO) == 1) {
        line = get_command(prompt, data);
    } else if (getline(&line, &len, stdin) == -1)
        return NULL;
    history(line, data->pwd);
    line = backslash_check_count(line, data);
    return line;
}

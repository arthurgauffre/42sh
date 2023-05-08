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

char *get_command(void);

void print_prompt(char const *prompt_str)
{
    if (!is_echo()) {
        prompt(prompt_str);
    }
}

char *read_terminal(void)
{
    if (isatty(STDIN_FILENO) == 1)
        return get_command();
    char *line = NULL;
    size_t len = 0;
    if (getline(&line, &len, stdin) == -1)
        return NULL;
    line = backslash_check_count(line);
    return line;
}

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

void print_prompt(char const *prompt_str)
{
    if (!is_echo()) {
        prompt(prompt_str);
    }
}

char *read_terminal(void)
{
    char *line = NULL;
    size_t len = 0;
    if (getline(&line, &len, stdin) == -1)
        return NULL;
    line = backslash_check_count(line);
    return line;
}

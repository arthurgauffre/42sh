/*
** EPITECH PROJECT, 2023
** read_terminal
** File description:
** read the terminal's input
*/

#include <stdio.h>
#include <unistd.h>

char *read_terminal(void)
{
    char *line = NULL;
    size_t len = 0;
    if (getline(&line, &len, stdin) == -1)
        return NULL;
    return line;
}

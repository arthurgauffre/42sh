/*
** EPITECH PROJECT, 2023
** read_terminal
** File description:
** read the terminal's input
*/

#include <stdio.h>
#include <unistd.h>
char *get_command(void);

char *read_terminal(void)
{
    if (isatty(STDIN_FILENO) == 1)
        return get_command();
    char *line = NULL;
    size_t len = 0;
    if (getline(&line, &len, stdin) == -1)
        return NULL;
    return line;
}

/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** init_line_editing
*/

#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
int my_tab_len(char **tab);

void init_term(struct termios *termio)
{
    struct termios term;
    tcgetattr(0, &term);
    *termio = term;
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &term);
}

int *init_index(char **history)
{
    int *index = malloc(sizeof(int) * 4);
    index[0] = -1;
    index[1] = 0;
    index[2] = my_tab_len(history);
    index[3] = index[2];
    return index;
}

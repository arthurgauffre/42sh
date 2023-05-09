/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get_input
*/

#include <unistd.h>
#include "header.h"

int get_dir(int *index, int c)
{
    read(0, &c, 1);
    read(0, &c, 1);
    switch (c) {
    case 'C':
        if (index[0] < index[1] - 2) {
            index[0] += 1;
        }
        break;
    case 'D':
        if (index[0] > -1) {
            index[0] += -1;
        }
        break;
    }
    return 0;
}

char *get_ch(int c, char *command, int *index)
{
    if (c == 27) {
        get_dir(index, c);
        return command;
    }
    if (c == 127) {
        if (index[0] != -1)
            command = sup_char(command, index);
    } else {
        command = add_char(command, c, index);
    }
    return command;
}

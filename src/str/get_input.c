/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get_input
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
char *add_char(char *command, int c, int *index);
char *sup_char(char *commande, int *index);
int my_strlen(char const *str);

void go_up(int *index, char **history)
{
    if (index[2] != 0) {
        index[2]--;
        index[0] = my_strlen(history[index[2]]) - 1;
        index[1] = my_strlen(history[index[2] + 1]) + 1;
    }
}

void go_down(int *index, char **history)
{
    if (index[2] < index[3]) {
        index[2]++;
        index[0] = my_strlen(history[index[2]]) - 1;
        index[1] = my_strlen(history[index[2] - 1]) + 1;
    }
}

char *do_suppr(char c, int *index, char *command)
{
    read(0, &c, 1);
    if (c != '~')
        return command;
    if (command == NULL)
        return NULL;
    int i = index[0] + 1;
    int len = strlen(command);
    if (len == 1 && i == 0) {
        free(command);
        index[1]--;
        return NULL;
    }
    if (i >= 1) {
        for (; command[i] != '\0'; i++) {
            command[i] = command[i + 1];
        }
    }
    index[1] = strlen(command) + 1;
    command = realloc(command, len);
    return command;
}

int get_cequence(int *index, char c, char **history)
{
    read(0, &c, 1);
    if(c != 91)
        return 1;
    read(0, &c, 1);
    switch (c) {
    case '3':
        history[index[2]] = do_suppr(c, index, history[index[2]]);
        break;
    case 'A':
        go_up(index, history);
        break;
    case 'B':
        go_down(index, history);
        break;
    case 'C':
        index[1] = my_strlen(history[index[2]]);
        if (index[0] < index[1] - 1)
            index[0] += 1;
        break;
    case 'D':
        if (index[0] > -1)
            index[0] += -1;
        break;
    }
    return 0;
}

char *get_ch(int c, char *command, int *index, char **history)
{
    if (c == 9) {
        for (int i = 0; i < 4; i++)
            command = add_char(command, ' ', index);
        return command;
    }
    if (c == '\e') {
        get_cequence(index, c, history);
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

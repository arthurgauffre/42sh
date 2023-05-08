/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-42sh-arthur.gauffre
** File description:
** test2
*/
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>

int get_dir(int *index, int c);
char *get_ch(int c, char *command, int *index);

char *sup_char(char *commande, int *index)
{
    if (commande == NULL)
        return NULL;
    int i = index[0];
    int len = strlen(commande);
    if (len == 1 && i == 0) {
        free(commande);
        index[0]--;
        index[1]--;
        return NULL;
    }
    if (i >= 0) {
        for (; commande[i] != '\0'; i++) {
            commande[i] = commande[i + 1];
        }
    }
    index[0]--;
    index[1]--;
    return realloc(commande, len);
}

char *add_char(char *command, int c, int *index)
{
    char save = '\0';
    if (command == NULL) {
        command = malloc(sizeof(char) * 2);
        command[0] = c;
        command[1] = '\0';
        index[0] = 0;
        index[1] = 2;
        return command;
    }
    index[1] += 1;
    command = realloc(command, sizeof(char) * index[1]);
    for (int i = index[0] + 1; i < index[1];i++) {
        save = command[i];
        command[i] = c;
        c = save;
    }
    index[0] += 1;
    return command;
}

int print_line(char *command, int *index)
{
    printf("\r");
    for (int i = 0; i < index[1] + 4; i++)
        printf(" ");
    printf("\r");
    printf("$> ");
    if (command != NULL)
        printf("%s", command);
    printf("\r");
    for (int i = 0; i < index[0] + 4; i++)
        printf("\033[C");
    return 0;
}

char *command_null(void)
{
    char *str = malloc(2);
    if (str == NULL)
        return NULL;
    str[0] = '\n';
    str[1] = '\0';
    return str;
}

char *get_command(void)
{
    int index[2];
    index[0] = -1;
    index[1] = 0;
    char *command = NULL;
    struct termios term;
    tcgetattr(0, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &term);
    char c;
    while (read(0, &c, 1) > 0 && c != 10) {
        command = get_ch(c, command, index);
        print_line(command, index);
        fflush(stdout);
    }
    if (command == NULL)
        command = command_null();
    printf("\n");
    return command;
}

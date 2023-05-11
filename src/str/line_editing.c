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

#include "struct.h"

int my_tab_len(char **tab);
char *get_ch(int c, char *command, int *index, char **history);
char **add_str(char **tab, char *new_var);
char **get_text(sh_data_t *data);
char *my_strdup(char const *src);
void free_tab(char **tab);
void init_term(struct termios *termio);
int *init_index(char **history);

char *sup_char(char *command, int *index)
{
    if (command == NULL)
        return NULL;
    int i = index[0];
    int len = strlen(command);
    if (len == 1 && i == 0) {
        free(command);
        index[0]--;
        index[1]--;
        return NULL;
    }
    if (i >= 0) {
        for (; command[i] != '\0'; i++) {
            command[i] = command[i + 1];
        }
    }
    index[0]--;
    index[1] = strlen(command) + 1;
    return realloc(command, len);
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
    command = realloc(command, sizeof(char) * (strlen(command) + 2));
    index[1] = strlen(command) + 2;
    for (int i = index[0] + 1; i < index[1]; i++) {
        save = command[i];
        command[i] = c;
        c = save;
    }
    index[0] += 1;
    return command;
}

int print_line(char *command, int *index, char const *prompt_char)
{
    printf("\r");
    for (int i = 0; i < index[1] + (int)strlen(prompt_char); i++)
        printf(" ");
    printf("\r");
    printf("%s", prompt_char);
    if (command != NULL)
        printf("%s", command);
    printf("\r");
    if (index[0] == -2)
        index[0]++;
    for (int i = 0; i < index[0] +  strlen(prompt_char) + 1; i++)
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

char *get_command(char const *prompt_char, sh_data_t *data)
{
    struct termios term;
    char *command = NULL;
    char **history = get_text(data);
    char c;
    int *index = init_index(history);
    init_term(&term);
    history = add_str(history, NULL);
    while (read(0, &c, 1) > 0 && c != 10) {
        if (c == 4)return NULL;
        history[index[2]] = get_ch(c, history[index[2]], index, history);
        print_line(history[index[2]], index, prompt_char);
        fflush(stdout);
    }
    if (history[index[2]] == NULL)history[index[2]] = command_null();
    printf("\n");
    command = my_strdup(history[index[2]]);
    tcsetattr(0, TCSANOW, &term);
    free(index);
    free_tab(history);
    return command;
}

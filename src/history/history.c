/*
** EPITECH PROJECT, 2023
** history
** File description:
** register all the commands in a file named .history_42sh
*/

#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "header.h"
#include "my.h"

static void cut_str(char *str, int start, int end, char *new_str)
{
    int len = strlen(str);
    if (start >= 0 && end < len && start <= end) {
        strncpy(new_str, str + start, end - start + 1);
    } else {
        new_str[0] = '\0';
    }
}

static char *get_time(void)
{
    time_t current_time = 0;
    char *time_array = NULL;
    char *new_time = NULL;
    char **time_tab = NULL;
    current_time = time(NULL);
    time_array = ctime(&current_time);
    time_tab = my_str_to_word_array(time_array, ' ');
    new_time = malloc(sizeof(char) * (my_strlen(time_tab[3]) - 2));
    new_time[my_strlen(time_tab[3]) - 3] = '\0';
    free_tab(time_tab);
    cut_str(time_array, 11, 15, new_time);
    return new_time;
}

history_t *set_history_last_line(history_t *head, char *input)
{
    int number = count_nodes(head) + 1;
    history_data_t data =
    {.nbr = number,
    .time = get_time(),
    .command = malloc(sizeof(char) * my_strlen(input) + 1)};
    data.command[my_strlen(input)] = '\0';
    strcpy(data.command, input);
    head = add_node(head, data);
    return head;
}

history_t *set_history_list(char **history_array, char *input)
{
    history_t *history_list = NULL;
    for (int i = 0; history_array[i] != NULL; i++) {
        char **history_splited = my_str_to_word_array(history_array[i], '\t');
        history_data_t data =
        {.nbr = atoi(history_splited[0]),
        .time = malloc(sizeof(char) * my_strlen(history_splited[1]) + 1),
        .command = malloc(sizeof(char) * my_strlen(history_splited[2]) + 1)};
        strcpy(data.time, history_splited[1]);
        strcpy(data.command, history_splited[2]);
        history_list = add_node(history_list, data);
        free_tab(history_splited);
    }
    history_list = set_history_last_line(history_list, input);

    return history_list;
}

int history(char *input, char *history_path)
{
    char *path = get_path_history(history_path);
    char *history = load_file_in_mem(path);
    FILE *fd = fopen(path, "w+");
    char *time = get_time();
    history_t *history_list = NULL;
    if (history != NULL) {
        char **history_array = my_str_to_word_array(history, '\n');
        history_list = set_history_list(history_array, input);
        print_list(history_list, input, fd);
        free_list(history_list);
        free_tab(history_array);
    } else
        fprintf(fd, "%6d\t%5s\t%s\n", 1, time, input);
    fclose(fd);
    free(history);
    free(time);
    free(path);
    return 0;
}

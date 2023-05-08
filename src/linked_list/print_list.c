/*
** EPITECH PROJECT, 2023
** print_list
** File description:
** print the data of the list
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "my.h"

int print_list(history_t *head, char *input, FILE *fd)
{
    if (fd == NULL)
        return 84;
    history_t *temp = head;
    for (; temp->next != NULL; temp = temp->next) {
        if (strcmp(temp->data.command, input) != 0) {
            fprintf(fd, "%6d\t%5s\t%s\n", temp->data.nbr, temp->data.time,
            temp->data.command);
        }
    }
    fprintf(fd, "%6d\t%5s\t%s\n", temp->prev->data.nbr + 1, temp->data.time,
    temp->data.command);
    return 0;
}

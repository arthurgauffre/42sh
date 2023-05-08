/*
** EPITECH PROJECT, 2023
** free_list
** File description:
** free the list
*/

#include <stdlib.h>
#include "structures.h"

void free_list(history_t *head)
{
    history_t *current = head;
    while (current != NULL) {
        history_t *next = current->next;
        free(current->data.command);
        free(current->data.time);
        free(current);
        current = next;
    }
}

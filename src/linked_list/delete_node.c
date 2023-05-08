/*
** EPITECH PROJECT, 2023
** delete_node
** File description:
** delete the node given as parameter
*/

#include <stdlib.h>
#include "structures.h"

void delete_node(history_t **head, history_t *node_to_delete)
{
    history_t *current = *head;
    if (node_to_delete == *head)
        *head = node_to_delete->next;
    else {
        while (current->next != NULL && current->next != node_to_delete) {
            current = current->next;
        }
        if (current->next != NULL)
            current->next = node_to_delete->next;
    }
    if (node_to_delete->next != NULL)
        node_to_delete->next->prev = node_to_delete->prev;
    if (node_to_delete->prev != NULL)
        node_to_delete->prev->next = node_to_delete->next;
    free(node_to_delete->data->command);
    free(node_to_delete->data->time);
    free(node_to_delete);
}

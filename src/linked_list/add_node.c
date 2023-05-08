/*
** EPITECH PROJECT, 2023
** add_node
** File description:
** add node in a linked list
*/

#include <stdlib.h>
#include "structures.h"

history_t *add_node(history_t *head, history_data_t data)
{
    history_t *new_node = malloc(sizeof(history_t));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (head == NULL)
        return new_node;
    history_t *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = NULL;
    return head;
}

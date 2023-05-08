/*
** EPITECH PROJECT, 2023
** count_nodes
** File description:
** count the number of nodes
*/

#include <unistd.h>

#include "structures.h"

int count_nodes(history_t *head)
{
    history_t *current = head;
    int len = 0;
    for (; current != NULL; current = current->next) {
        len++;
    }
    return len;
}

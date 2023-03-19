/*
** EPITECH PROJECT, 2023
** free_tab
** File description:
** free the tab
*/

#include <stdlib.h>

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

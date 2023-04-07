/*
** EPITECH PROJECT, 2023
** tablen
** File description:
** return size of tab
*/

#include <unistd.h>

int my_tablen(char **tab)
{
    int nb = 0;
    while (tab[nb] != NULL)
        nb++;
    return nb;
}

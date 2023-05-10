/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** tab_handeling
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "header.h"

int my_tab_len(char **tab)
{
    if (tab == NULL)
        return 0;
    int compteur = 0;
    for (; tab[compteur] != NULL; ++compteur) {}
    return compteur;
}

char **tab_null(char *new_var)
{
    char **tab = malloc(sizeof(char *) * 2);
    if (new_var == NULL)
        tab[0] = NULL;
    else
        tab[0] = strdup(new_var);
    tab[1] = NULL;
    return tab;
}

char **add_str(char **tab, char *new_var)
{
    int i = 0;
    if (tab == NULL)
        return tab_null(new_var);
    char **new_tab =
    malloc(sizeof(char *) * my_tab_len(tab) + sizeof(char *) * 2);
    for (; tab[i] != NULL;i++) {
        new_tab[i] = strdup(tab[i]);
    }
    if (new_var == NULL)
        new_tab[i] = NULL;
    else
        new_tab[i] = strdup(new_var);
    new_tab[i + 1] = NULL;
    free_tab(tab);
    return new_tab;
}

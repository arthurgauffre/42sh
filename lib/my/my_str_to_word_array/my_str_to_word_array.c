/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_str_to_word_array.h"
#include "my.h"

int nb_word(char const *str, char separator)
{
    int nb = 0;
    int count = 0;
    while (str[count] != '\0') {
        if (str[count] != separator) {
            nb += 1;
            count = parcour_word(str, count, separator);
        } else {
            count += 1;
        }
    }
    return nb;
}

char **find_word(char const *str, my_str_to_word_array_t *count,
char **tab, char separator)
{
    if (str[count->count_str] != separator) {
        tab[count->count_tab] = get_word(str, count->count_str, separator);
        if (tab[count->count_tab] == NULL)
            return NULL;
        count->count_str = parcour_word(str, count->count_str, separator);
        count->count_tab += 1;
    } else {
        count->count_str += 1;
    }
    return tab;
}

char **my_str_to_word_array(char const *str, char separator)
{
    char **tab = NULL;
    my_str_to_word_array_t count = {0};
    tab = malloc(sizeof(char *) * (nb_word(str, separator) + 1));
    if (tab == NULL)
        return NULL;
    tab[nb_word(str, separator)] = NULL;
    while (str[count.count_str] != '\0') {
        tab = find_word(str, &count, tab, separator);
        if (tab == NULL)
            return NULL;
    }
    return tab;
}

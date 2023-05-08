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

static int check_word(char const *str, int count, char separator, int *nb)
{
    if (str == NULL || nb == NULL)
        return -1;
    if (str[count] != separator) {
        *nb += 1;
        if ((count = parcour_word(str, count, separator)) == -1)
            return -1;
    } else {
        count += 1;
    }
    return count;
}

static int nb_word(char const *str, char separator)
{
    int nb = 0;
    int count = 0;
    if (str == NULL)
        return -1;
    while (str[count] != '\0') {
        if ((count = check_word(str, count, separator, &nb)) == -1)
            return -1;
    }
    return nb;
}

static char **find_word(char const *str, my_str_to_word_array_t *count,
char **tab, char separator)
{
    if (str == NULL || count == NULL || tab == NULL)
        return NULL;
    if (str[count->count_str] != separator) {
        if ((tab[count->count_tab] = get_word(str, count->count_str,
        separator)) == NULL)
            return NULL;
        if (tab[count->count_tab] == NULL)
            return NULL;
        if ((count->count_str = parcour_word(str, count->count_str,
        separator)) == -1)
            return NULL;
        count->count_tab += 1;
    } else {
        count->count_str += 1;
    }
    return tab;
}

char **my_str_to_word_array(char const *str, char separator)
{
    char **tab = NULL;
    int nbr_word = 0;
    if (str == NULL)
        return NULL;
    if ((nbr_word = nb_word(str, separator)) == -1)
        return NULL;
    my_str_to_word_array_t count = {0};
    tab = malloc(sizeof(char *) * (nbr_word + 1));
    if (tab == NULL)
        return NULL;
    tab[nbr_word] = NULL;
    while (str[count.count_str] != '\0') {
        tab = find_word(str, &count, tab, separator);
        if (tab == NULL)
            return NULL;
    }
    return tab;
}

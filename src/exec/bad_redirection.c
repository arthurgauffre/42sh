/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** bad_redirection
*/

#include "header.h"
#include "my.h"

int bad_redirection(char *str)
{
    char **tab = my_str_to_word_array(str, '>');
    if (nb_chevron(str) >= 2 && my_tablen(tab) > 2) {
        free_tab(tab);
        return 1;
    }
    free_tab(tab);
    return 0;
}

/*
** EPITECH PROJECT, 2023
** len_word
** File description:
** len_word
*/

#include <stddef.h>
#include "my.h"

int len_word(char const *str, int count, char separator)
{
    int nb = 0;

    if (str == NULL)
        return -1;
    while (str[count] != '\0' && str[count] != separator) {
        nb += 1;
        count += 1;
    }
    return nb;
}

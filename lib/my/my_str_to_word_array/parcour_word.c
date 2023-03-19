/*
** EPITECH PROJECT, 2023
** parcour_word
** File description:
** parcour_word
*/

#include <stdbool.h>
#include "my.h"

int parcour_word(char const *str, int count, char separator)
{
    while (str[count] != '\0' && str[count] != separator)
        count += 1;
    return count;
}

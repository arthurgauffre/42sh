/*
** EPITECH PROJECT, 2023
** parcour_word
** File description:
** parcour_word
*/

#include <unistd.h>
#include "my.h"

int parcour_word(char const *str, int count, char separator)
{
    if (str == NULL)
        return -1;
    while (str[count] != '\0' && str[count] != separator)
        count += 1;
    return count;
}

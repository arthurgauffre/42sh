/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** len str
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int size = 0;

    if (str == NULL)
        return -1;
    for (; str[size] != '\0'; size++);
    return size;
}

/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** return str cpy
*/

#include <unistd.h>

char *my_strcpy(char *dest, char const *src)
{
    int count = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    for (; src[count] != '\0'; count++)
        dest[count] = src[count];
    dest[count] = '\0';
    return dest;
}

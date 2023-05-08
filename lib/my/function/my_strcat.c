/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** return char
*/

#include <unistd.h>

char *my_strcat(char *dest, char const *src)
{
    int count_dest = 0;
    int count_src = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    while (dest[count_dest] != '\0')
        count_dest += 1;
    while (src[count_src] != '\0') {
        dest[count_dest] = src[count_src];
        count_dest += 1;
        count_src += 1;
    }
    return dest;
}

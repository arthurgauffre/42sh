/*
** EPITECH PROJECT, 2022
** my_strncat
** File description:
** return n char
*/

#include <unistd.h>
#include "my.h"

char *my_strncat(char *dest ,char const *src ,int nb)
{
    int count_dest = 0;
    int count_src = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    for (; dest[count_dest] != '\0'; count_dest++);
    while (src[count_src] != '\0' && count_src < nb) {
        dest[count_dest] = src[count_src];
        count_dest += 1;
        count_src += 1;
    }
    return dest;
}

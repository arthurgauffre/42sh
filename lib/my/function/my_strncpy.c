/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** task02
*/

#include <unistd.h>
#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int count = 0;
    int len_src = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    if ((len_src = my_strlen(src)) == -1)
        return NULL;
    while (src[count] != '\0' && count < n) {
        dest[count] = src[count];
        count += 1;
    }
    if (n > len_src) {
        while (dest[count] != '\0') {
            dest[count] = '\0';
            count += 1;
        }
    }
    return dest;
}

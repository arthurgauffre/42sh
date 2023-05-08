/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** return int
*/

#include <unistd.h>

int my_strcmp(char const *s1, char const *s2)
{
    int count = 0;

    if (s1 == NULL || s2 == NULL)
        return -256;
    while (s1[count] != '\0' || s2[count] != '\0') {
        if (s1[count] != s2[count])
            return s1[count] - s2[count];
        count += 1;
    }
    return s1[count] - s2[count];
}

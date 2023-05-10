/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** slash_in_str
*/

#include <unistd.h>

int slash_in_str(char *str)
{
    if (str == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '/')
            return 1;
    }
    return 0;
}

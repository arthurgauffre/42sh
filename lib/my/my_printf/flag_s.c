/*
** EPITECH PROJECT, 2022
** flag_s
** File description:
** flag_s
*/

#include <stdarg.h>
#include "my.h"

int function_s(const char *format, int count, va_list list, int precision)
{
    char *str = va_arg(list, char *);
    int taille = 0;
    if (precision < 0) {
        precision = my_strlen(str);
    }
    while (str[taille] != '\0' && taille < precision) {
        my_putchar(str[taille]);
        taille += 1;
    }
    return (0);
}

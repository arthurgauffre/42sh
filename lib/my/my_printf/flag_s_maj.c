/*
** EPITECH PROJECT, 2022
** flag_S
** File description:
** flag_S
*/

#include <stdarg.h>
#include "my.h"

int my_put_octal_v2(const char *format, char nbr)
{
    if (nbr < 8) {
        my_putchar(nbr + 48);
    } else {
        my_put_octal_v2(format,  nbr / 8);
        my_putchar(nbr % 8 + 48);
    }
    return (0);
}

int function_s_maj(const char *format, int count, va_list list, int precision)
{
    char *str = va_arg(list, char *);
    int taille = 0;
    while (str[taille] != '\0' && taille < precision) {
        if (str[taille] < 32 || str[taille] > 126) {
            my_putchar('\\');
            my_put_octal_v2(format, str[taille]);
        } else {
            my_putchar(str[taille]);
        }
        taille += 1;
    }
    return (0);
}

/*
** EPITECH PROJECT, 2022
** flag_c
** File description:
** flag_c
*/

#include <stdarg.h>
#include "my.h"

int function_c(const char *format, int count, va_list list, int precision)
{
    char ch = va_arg(list, int);
    if (ch < 32 || ch >= 127) {
        return 0;
    } else {
        my_putchar(ch);
    }
    return 0;
}

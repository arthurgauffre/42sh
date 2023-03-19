/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** the same as printf system fonction
*/

#include <stdarg.h>
#include "my.h"

int my_printf(const char *format, ...)
{
    va_list list;
    va_start(list, format);
    int i = 0;
    int count = 0;

    while (format[i] != '\0') {
        if (format[i] == '%') {
            i += 1;
            i = find_flag(format[i], i, format, list);
        } else {
            my_putchar(format[i]);
            count += 1;
        }
        i += 1;
    }
    va_end(list);
}

/*
** EPITECH PROJECT, 2022
** flag_n
** File description:
** flag_n
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int function_n(char const *format, int count, va_list list, int precision)
{
    *va_arg(list, int*) = count - 1;
    return (0);
}

/*
** EPITECH PROJECT, 2022
** find_flag
** File description:
** function that fing the flag and run the function according to this
*/

#include <stddef.h>
#include "my.h"

char flag[] = {'d', 'i', 'u', 's', 'c', 'e', 'f', 'n', '%', 'o',
'E', 'F', 'x', 'X', 'N'};
int (*flag_function[])(char const *, int, va_list, int) = {&function_d,
    &function_i, &function_u, &function_s, &function_c, &function_e,
    &function_f, &function_n, &function_percentage, &function_o,
    &function_e_maj, &function_f_maj, &function_x,
    &function_x_maj};

int if_precision(char my_flag, int count, char const *format, va_list list)
{
    int precision = 0;
    int l = count;
    for (int k = count + 1; format[k] >= '0' && format[k] <= '9'; k++) {
        precision += (int)(format[k] - '0');
        precision = precision * 10;
        l = k;
    }
    for (int i = 0; flag[i] != 'N'; i++) {
        if (flag[i] == format[l + 1]) {
            return flag_function[i](format, count, list, precision / 10), l + 1;
        }
    }
}

int if_not_precision(char my_flag, int count, char const *format, va_list list)
{
    for (int i = 0; flag[i] != 'N'; i++) {
        if (flag[i] == my_flag) {
            return flag_function[i](format, count, list, -1), count;
        }
    }
    return count;
}

int find_flag(char my_flag, int count, char const *format, va_list list)
{
    if (format[count] == '.') {
        return if_precision(my_flag, count, format, list);
    } else {
        return if_not_precision(my_flag, count, format, list);
    }
}

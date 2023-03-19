/*
** EPITECH PROJECT, 2023
** is_alpha_num
** File description:
** is_alpha_num
*/

#include <stdbool.h>

bool is_alpha_num(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
    (ch >= '0' && ch <= '9'))
        return true;
    return false;
}

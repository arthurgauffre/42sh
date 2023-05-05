/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** display
*/

#include <unistd.h>

int my_putchar(char c)
{
    if (write(1, &c, 1) == -1)
        return -1;
    return 0;
}

/*
** EPITECH PROJECT, 2023
** prompt
** File description:
** prompt
*/

#include <unistd.h>

void prompt(void)
{
    write(1, "$> ", 3);
}

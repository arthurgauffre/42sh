/*
** EPITECH PROJECT, 2023
** prompt
** File description:
** prompt
*/

#include <unistd.h>
#include <string.h>

void prompt(char const *prompt_str)
{
    write(1, prompt_str, strlen(prompt_str));
}

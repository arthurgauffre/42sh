/*
** EPITECH PROJECT, 2023
** pwd
** File description:
** pwd
*/

#include <stdlib.h>
#include <unistd.h>

char *get_pwd(void)
{
    char *pwd_value = malloc(sizeof(char) * 1000);
    pwd_value = getcwd(pwd_value, 999);
    return pwd_value;
}

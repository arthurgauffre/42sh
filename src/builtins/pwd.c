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
    char *pwd_value = NULL;
    pwd_value = getcwd(pwd_value, 0);
    return pwd_value;
}

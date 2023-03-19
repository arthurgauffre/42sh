/*
** EPITECH PROJECT, 2023
** main
** File description:
** main of the program
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "header.h"
#include "my.h"



int main(int ac, char *const *const av, char **env)
{
    if (ac != 1 || av[1] != NULL)
        return KO;
    char **my_env = my_envcpy(env);
    if (my_env == NULL)
        return KO;
    return mysh(my_env);
}

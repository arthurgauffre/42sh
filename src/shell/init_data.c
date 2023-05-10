/*
** EPITECH PROJECT, 2023
** init_data
** File description:
** init the data struct
*/

#include "struct.h"
#include "header.h"

sh_data_t init_data(char ***env)
{
    sh_data_t data = {0};
    data.exit_shell = 1;
    data.command = NULL;
    data.command_and = NULL;
    data.command_or = NULL;
    data.old_parser = NULL;
    data.pipes = NULL;
    data.parser = NULL;
    data.tab = NULL;
    data.tab_and = NULL;
    data.tab_command = NULL;
    data.tab_or = NULL;
    data.tab_parser = NULL;
    data.tab_pipe = NULL;
    data.env = env;
    data.pwd = get_pwd();
    return data;
}

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
    data.env = env;
    data.pwd = get_pwd();
    return data;
}

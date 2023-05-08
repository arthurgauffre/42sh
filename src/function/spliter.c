/*
** EPITECH PROJECT, 2023
** spliter
** File description:
** spliter
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "my.h"

static char *my_strndup(char const *src, int len)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));
    return my_strncpy(str, src, len);
}

static spliter_t init_struct_spliter(char *str)
{
    spliter_t spliter;
    spliter.len_tab = 1;
    spliter.temp_str = str;
    spliter.tab_str = NULL;
    spliter.tab = NULL;
    spliter.i = 0;
    spliter.start = 0;
    spliter.len = 0;
    spliter.end = 0;
    return spliter;
}

static spliter_t loop_spliter(spliter_t spliter, char *str, char *separator)
{
    if (my_strncmp(&str[spliter.end], separator, my_strlen(separator)) == 0) {
        spliter.len = spliter.end - spliter.start;
        spliter.tab_str = my_strndup(&str[spliter.start], spliter.len);
        spliter.tab_str[spliter.len] = '\0';
        spliter.tab[spliter.i++] = spliter.tab_str;
        spliter.start = spliter.end + my_strlen(separator);
        spliter.end = spliter.start;
    } else {
        spliter.end++;
    }
    return spliter;
}

char **split_str_to_tab_with_wtr_separator(char *str, char *separator)
{
    spliter_t spliter = init_struct_spliter(str);
    while ((spliter.temp_str = strstr(spliter.temp_str, separator))) {
        spliter.len_tab++;
        spliter.temp_str += my_strlen(separator);
    }
    spliter.tab = malloc(sizeof(char*) * (spliter.len_tab + 1));
    spliter.tab[spliter.len_tab] = NULL;
    while (str[spliter.end] != '\0')
        spliter = loop_spliter(spliter, str, separator);
    spliter.len = spliter.end - spliter.start;
    spliter.tab_str = my_strndup(&str[spliter.start], spliter.len);
    spliter.tab_str[spliter.len] = '\0';
    spliter.tab[spliter.i++] = spliter.tab_str;
    return spliter.tab;
}

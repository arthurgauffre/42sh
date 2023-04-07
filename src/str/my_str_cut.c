/*
** EPITECH PROJECT, 2023
** my_str_start_cut
** File description:
** cut x char of start string
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char *my_str_cut(char *str, int nb, int start_or_end)
{
    int count = 0;
    char *str_cut = malloc(sizeof(char) * (my_strlen(str) - nb + 1));
    if (str_cut == NULL)
        return NULL;
    str_cut[my_strlen(str) - nb] = '\0';
    if (start_or_end == 0) {
        while (str[count + nb] != '\0') {
            str_cut[count] = str[count + nb];
            count++;
        }
    } else {
        while (count != my_strlen(str) - nb) {
            str_cut[count] = str[count];
            count++;
        }
    }
    free(str);
    return str_cut;
}

/*
** EPITECH PROJECT, 2023
** my_realloc
** File description:
** realloc str
*/

#include <stdlib.h>
#include <string.h>

char *my_realloc(char *str, int size) {
    if (str == NULL) {
        str = malloc(sizeof(char) * (size + 1));
        return str;
    }
    int i = 0;
    int new_size = strlen(str) + size;
    char *output = malloc(sizeof(char) * (new_size + 1));
    if (output == NULL)
        return NULL;
    for (; str[i] != '\0'; i++) {
        output[i] = str[i];
    }
    free(str);
    output[i] = '\0';

    return output;
}

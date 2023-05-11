/*
** EPITECH PROJECT, 2023
** back slash handling
** File description:
** back_slash_handling
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "header.h"

static int react_whether_back_slash(char* parser, int i)
{
    switch (parser[i]) {
        case ('n'):
            return '\n';
        case ('t'):
            printf("\t");
            fflush(stdout);
            return '\t';
        case ('r'):
            return '\r';
        case ('b'):
            return '\b';
        case ('\\'):
            return '\\';
        case ('a'):
            return '\a';
        case ('v'):
            return '\v';
    }
    return 0;
}

static char *backslash_check(char *parser, int counter)
{
    char *new_parser = malloc(sizeof(char) * counter + 1);
    memset(new_parser, '\0', counter + 1);
    int j = 0;
    for (int i = 0; parser[i] != '\0' && j < counter; i++) {
        if (parser[i] == '\\' && parser[i + 1] == '\\') {
            i = i + 2;
            new_parser[j] = react_whether_back_slash(parser, i);
            j++;
            continue;
        }
        if (parser[i] == '\\' && parser[i + 1] != '\\') {
            continue;
        }
        new_parser[j] = parser[i];
        j++;
    }
    return new_parser;
}

static int counter_fonc(char const *parser)
{
    int counter = 0;
    for (int i = 0; parser[i] != '\0'; i++) {
        if (parser[i] == '\\' && parser[i + 1] != '\\') {
            continue;
        }
        counter++;
    }
    return counter;
}

char *backslash_check_count(char *parser)
{
    int counter = 0;
    char *new_parser = NULL;
        counter = counter_fonc(parser);
        new_parser = backslash_check(parser, counter);
    return new_parser;
}

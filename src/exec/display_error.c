/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-42sh-arthur.gauffre
** File description:
** display_error
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "header.h"
#include "my.h"

int display_child_error(char *str)
{
    my_puterror(str);
    int fd = open(str, O_RDONLY);
    if (fd == -1)
        write(2, ": Command not found.\n", 21);
    else {
        write(2, ": Permission denied.\n", 21);
        close(fd);
    }
    return OK;
}

void display_exec_error(int wstatus)
{
    if ((WTERMSIG(wstatus)) == 11)
        my_puterror("Segmentation fault");
    if ((WTERMSIG(wstatus)) == 8)
        my_puterror("Floating exception");
    if ((WCOREDUMP(wstatus)) == 128)
        my_puterror(" (core dumped)\n");
    if (WTERMSIG(wstatus) == 11 && WCOREDUMP(wstatus) != 128)
        my_puterror("\n");
}

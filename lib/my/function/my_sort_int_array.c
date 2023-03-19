/*
** EPITECH PROJECT, 2022
** my_sort_int_array
** File description:
** task06
*/

#include <stddef.h>

void my_swap(int *a, int *b);

int min(int i, int *array, int size)
{
    int min = array[size - 1];
    for (int j = i; j < size; j++) {
        if (array[j] < array[min]) {
            min = j;
        }
    }
    return min;
}

void my_sort_int_array(int *array, int size)
{
    return;
}

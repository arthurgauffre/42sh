/*
** EPITECH PROJECT, 2022
** myt
** File description:
** contains the prototypes of all the functuins exposed
*/

#include <stdarg.h>
#include <stdbool.h>

#ifndef TEST_H_
    #define TEST_H_
    int my_putchar(char c);
    int my_isneg(int nb);
    int my_strcmp(char const *s1, char const *s2);
    int my_put_nbr(int nb);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strupcase(char *str);
    int my_putstr(char const *str);
    char *my_strlowcase(char *str);
    int my_strlen(char const *str);
    char *my_strcapitalize(char *str);
    int my_str_isalpha(char const *str);
    void my_sort_int_array(int *tab, int size);
    char *my_strdup(char const *src);
    int my_str_isnum(char const *str);
    int my_compute_power_rec(int nb, int power);
    int my_str_islower(char const *str);
    int my_compute_square_root(int nb);
    int my_str_isupper(char const *str);
    int my_is_prime(int nb);
    int my_str_isprintable(char const *str);
    int my_showstr(char const *str);
    char *my_strcpy(char *dest, char const *src);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strcat(char *dest, char const *src);
    char *my_revstr(char *str);
    char *my_strncat(char *dest, char const *src, int nb);
    char **my_str_to_word_array(char const *str, char separator);
    int my_puterror(char const *str);
    bool is_alpha_num(char ch);
    int parcour_word(char const *str, int count, char separator);
    char *get_word(char const *str, int count, char separator);
    int len_word(char const *str, int count, char separator);

#endif /* TEST_H_ */

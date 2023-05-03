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
    void my_putchar(char c);
    char *my_strstr(char *str, char const *to_find);
    int my_isneg(int nb);
    int my_strcmp(char const *s1, char const *s2);
    int my_put_nbr(int nb);
    int my_strncmp(char const *s1, char const *s2, int n);
    void my_swap(int *a, int *b);
    char *my_strupcase(char *str);
    int my_putstr(char const *str);
    char *my_strlowcase(char *str);
    int my_strlen(char const *str);
    char *my_strcapitalize(char *str);
    int my_getnbr(char const *str);
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
    int my_find_prime_sup(int nb);
    int my_showstr(char const *str);
    char *my_strcpy(char *dest, char const *src);
    int my_showmem(char const *str, int size);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strcat(char *dest, char const *src);
    char *my_revstr(char *str);
    char *my_strncat(char *dest, char const *src, int nb);
    char **my_str_to_word_array(char const *str, char separator);
    int if_1(char ch);
    char **for_1(int count, char const *str, char *new_str, char **tab);
    int my_printf(const char *format, ...);
    int function_c(const char *format, int count, va_list list, int precision);
    int function_i(char const *format, int count, va_list list, int precision);
    int function_s(const char *format, int count, va_list list, int precision);
    int function_o(char const *format, int count, va_list list, int precision);
    int function_e(char const *format, int count, va_list list, int precision);
    int function_f(const char *format, int count, va_list list, int precision);
    int function_u(char const *format, int count, va_list list, int precision);
    int function_d(const char *format, int count, va_list list, int precision);
    int function_n(char const *format, int count, va_list list, int precision);
    int function_x(char const *format, int count, va_list list, int precision);
    int function_percentage(char const *format, int count, va_list list,
    int precision);
    int function_e_maj(const char *format, int count, va_list list,
    int precision);
    int function_f_maj(const char *format, int count, va_list list,
    int precision);
    int function_x_maj(char const *format, int count, va_list list,
    int precision);
    int find_flag(char my_flag, int count, char const *format, va_list list);
    int count_digit(unsigned int nbr_tpm);
    int my_puterror(char const *str);
    bool is_alpha_num(char ch);
    int parcour_word(char const *str, int count, char separator);
    char *get_word(char const *str, int count, char separator);
    int len_word(char const *str, int count, char separator);

#endif /* TEST_H_ */

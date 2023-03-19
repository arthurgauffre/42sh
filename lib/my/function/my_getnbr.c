/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** task05
*/

int my_len(char const *str);
int negat(char const *str_3);
int first_digit(char const *str_2);
int my_atoi(char nb_char);

int my_len(char const *str)
{
    int tail;
    tail = 0;
    while (str[tail] != '\0') {
        tail += 1;
    }
    return (tail);
}

int negat(char const *str_3)
{
    int count_2;
    int i;
    int ne_or_po;
    ne_or_po = 1;
    i = 0;
    while (str_3[i] <= '0' || str_3[i] >= '9') {
        if (str_3[i] == 45) {
            ne_or_po *= -1;
        }
        i += 1;
    }
    return (ne_or_po);
}

int first_digit(char const *str_2)
{
    int count;
    int frst_dg;
    count = my_len(str_2) - 1;
    frst_dg = 0;
    while ((str_2[frst_dg] < '0' || str_2[frst_dg] > '9') && frst_dg <= count) {
        frst_dg += 1;
    }
    return (frst_dg);
}

int char_before_int(char const *str, int digit)
{
    int count = 0;
    while (count < digit) {
        if (str[count] != 45 && str[count] != 43) {
            return (1);
        }
        count += 1;
    }
    return (0);
}

int my_getnbr(char const *str)
{
    int digit;
    int p_o_n;
    int long a;
    a = 0;
    digit = first_digit(str);
    p_o_n = negat(str);
    if (char_before_int(str, digit) == 1) {
        return (0);
    }
    while (str[digit] >= '0' && str[digit] <= '9') {
        a += (int)(str[digit] - '0');
        a *= 10;
        digit += 1;
        if ((a * p_o_n) / 10 > 2147483647 || (a * p_o_n) / 10 < -2147483648) {
            return (0);
        }
    }
    a = a * p_o_n / 10 ;
    return (a);
}

/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** return int
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int count;
    count = 0;
    while ((s1[count] != '\0' || s2[count] != '\0') && count < n - 1) {
        if (s1[count] != s2[count]) {
            return (s1[count] - s2[count]);
        }
        count += 1;
    }
    return (s1[count] - s2[count]);
}

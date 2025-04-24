/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that returns a number, sent to the functions as a string.
*/

#include "my.h"

static bool check_limits(long nb, int neg)
{
    if (nb > 2147483647 && neg % 2 == 0)
        return false;
    if (nb > 2147483648 && neg % 2 == 1)
        return false;
    return true;
}

int my_getnbr(char const *str)
{
    long nb = 0;
    int prev = -1;
    int neg = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        while ((my_char_isnum(str[i]) == 1 && (i - prev <= 1 || prev == -1))
            && check_limits(nb, neg) == true) {
            nb = (nb * 10) + (str[i] - '0');
            prev = i;
            i++;
        }
        if (check_limits(nb, neg) == false)
            return 0;
        if (str[i] == '-' && prev == -1)
            neg++;
    }
    if (neg % 2 == 1)
        nb *= (-1);
    return nb;
}

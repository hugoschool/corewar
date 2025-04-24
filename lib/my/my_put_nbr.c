/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that displays the number
** given as a parameter.
*/

#include "my.h"

int my_put_nbr(int nb)
{
    long nb_1 = nb;

    if (nb_1 < 0) {
        my_putchar('-');
        nb_1 = nb_1 * -1;
    }
    if (nb_1 > 9) {
        my_put_nbr(nb_1 / 10);
    }
    my_putchar(nb_1 % 10 + '0');
    return 0;
}

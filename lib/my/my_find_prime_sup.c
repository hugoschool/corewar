/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that returns the smallest prime
** number that is greater than, or equal to,
** the number given as a parameter.
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int rep = nb;
    int found = 0;

    if (rep <= 1) {
        return 2;
    } else if (rep >= 2147483647) {
        return 0;
    }
    while (found == 0) {
        if (my_is_prime(rep) == 1) {
            found = 1;
        } else {
            rep++;
        }
    }
    return rep;
}

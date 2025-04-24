/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that returns 1 if the number is prime and 0 if not.
*/

#include "my.h"

int my_is_prime(int nb)
{
    if (nb <= 1) {
        return 0;
    }
    for (int i = 2; i <= nb / 2 && i < 50000; i++) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}

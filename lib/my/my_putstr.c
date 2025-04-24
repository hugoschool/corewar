/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that displays, one-by-one,
** the characters of a string.
*/

#include "my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}

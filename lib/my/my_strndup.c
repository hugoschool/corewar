/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that allocates memory and copies
** the string given as argument in it.
*/

#include "my.h"

char *my_strndup(char const *src, int nb)
{
    char *dest = malloc(sizeof(char) * nb + 1);

    my_strncpy(dest, src, nb);
    dest[nb] = '\0';
    return dest;
}

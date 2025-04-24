/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that allocates memory and copies
** the string given as argument in it.
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    my_strcpy(dest, src);
    return dest;
}

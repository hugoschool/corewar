/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** Returns the length of a NULL terminated array.
*/

#include "my.h"

int my_array_length(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return i;
}

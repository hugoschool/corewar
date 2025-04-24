/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that frees the inside of a my_str_to_*_array.
*/

#include "my.h"

void free_my_str_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

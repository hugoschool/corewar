/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** Reproduce calloc usage.
*/

#include "my.h"

void *my_calloc(int nmemb, int size)
{
    void *arr = malloc(size * nmemb);

    my_memset(arr, 0, nmemb);
    return arr;
}

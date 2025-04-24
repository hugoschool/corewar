/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that concatenates n characters
** of the src string to the end of the dest string.
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    while (i < nb) {
        dest[dest_len + i] = src[i];
        i++;
    }
    return dest;
}

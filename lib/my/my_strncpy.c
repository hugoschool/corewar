/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that copies n characters from a string into another.
** The destination string will already have
** enough memory to contain n characters.
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++) {
        if (i > my_strlen(src)) {
            dest[i] = '\0';
        } else {
            dest[i] = src[i];
        }
    }
    return dest;
}

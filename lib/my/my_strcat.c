/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that concatenates two strings.
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    return dest;
}

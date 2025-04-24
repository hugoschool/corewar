/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** Reproduce the behavior of the strchr function.
*/

#include "my.h"

char *my_strchr(char *s, int c)
{
    int i = 0;

    for (; s[i] != '\0'; i++)
        if (s[i] == c)
            return &s[i];
    if (c == '\0')
        return &s[i];
    return NULL;
}

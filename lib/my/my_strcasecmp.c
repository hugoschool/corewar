/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** Case insensitive my_strcmp
*/

#include "my.h"

static char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int my_strcasecmp(char const *s1, char const *s2)
{
    for (int i = 0; i <= my_strlen(s1) && i <= my_strlen(s2); i++) {
        if (to_lower(s1[i]) != to_lower(s2[i]))
            return s1[i] - s2[i];
    }
    return 0;
}

/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that reverses a string.
*/

#include "my.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char new_str[len];

    my_strcpy(new_str, str);
    for (int i = 0; i < len; i++) {
        str[i] = new_str[len - i - 1];
    }
    return str;
}

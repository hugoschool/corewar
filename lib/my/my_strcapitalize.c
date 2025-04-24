/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that capitalizes the first letter of each word.
*/

#include "my.h"

static int is_az(char c)
{
    if ('0' <= c && c <= '9') {
        return 2;
    } else if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
        return 1;
    } else {
        return 0;
    }
}

char *my_strcapitalize(char *str)
{
    int len = my_strlen(str);

    my_strlowcase(str);
    if (is_az(str[0]) == 1) {
        str[0] = str[0] - 32;
    }
    for (int i = 0; i < len; i++) {
        if (is_az(str[i]) == 0 && is_az(str[i + 1]) == 1 && i < len) {
            str[i + 1] = str[i + 1] - 32;
        }
    }
    return str;
}

/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** Reproduce the behavior of the strstr function.
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int len_str = my_strlen(str);
    int len_to_find = my_strlen(to_find);
    int cmp;

    if (len_str <= 0)
        return NULL;
    if (len_to_find <= 0)
        return str;
    for (int i = 0; str[i] != '\0'; i++) {
        cmp = my_strncmp(&str[i], to_find, len_to_find);
        if (cmp == 0) {
            return &str[i];
        }
    }
    return NULL;
}

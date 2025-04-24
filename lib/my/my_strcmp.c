/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** DOES NOT REPRODUCE THE BEHAVIOR OF THE STRCMP FUNCTION EXACTLY:
** Does almost the same as strcmp, except when the string is different,
** it returns the ascii difference between the first 2 different characters,
** instead of returning 1 or -1.
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; i <= my_strlen(s1) && i <= my_strlen(s2); i++) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}

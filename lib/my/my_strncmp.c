/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** DOES NOT REPRODUCE THE BEHAVIOR OF THE STRNCMP FUNCTION EXACTLY:
** See description of strcmp.
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n && (s1[i] != '\0' && s2[i] != '\0'); i++) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}

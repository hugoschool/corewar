/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that copies a string into another.
** The destination string will already have enough
** memory to copy the source string.
*/

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

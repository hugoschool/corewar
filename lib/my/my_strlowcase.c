/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that puts every letter of every word in it in lowercase.
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    return str;
}

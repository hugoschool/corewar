/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that puts every letter of every word in it in uppercase.
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ('a' <= str[i] && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    return str;
}

/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that returns 1 if the char passed as
** parameter is an alphabetical character.
*/

int my_char_alpha(char c)
{
    if ((48 <= c && c <= 57) || (65 <= c && c <= 90) || (97 <= c && c <= 122))
        return 1;
    else
        return 0;
}

/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that returns 1 if the char passed as
** parameter is a number between 0-9.
*/

int my_char_isnum(char c)
{
    if (c < 48 || c > 57) {
        return 0;
    } else {
        return 1;
    }
}

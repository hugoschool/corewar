/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that returns the length of an integer
*/

int my_intlen(int i)
{
    int nbr = 1;

    if (i == -2147483648)
        return 11;
    if (i < 0) {
        nbr++;
        i *= -1;
    }
    while (i > 9) {
        i = i / 10;
        nbr++;
    }
    return nbr;
}

/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that returns 1 if the string passed as
** parameter only contains alphabetical characters and
** 0 if the string contains another type of character.
*/

int my_str_isalpha(char const *str)
{
    int nbr = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 122 || str[i] < 65 || (91 <= str[i] && str[i] <= 96)) {
            nbr = 0;
        }
    }
    return nbr;
}

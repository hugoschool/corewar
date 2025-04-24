/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that returns 1 if the string passed
** as parameter only contains lowercase alphabetical
** characters and 0 otherwise.
*/

int my_str_islower(char const *str)
{
    int nbr = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 97 || 122 < str[i]) {
            nbr = 0;
        }
    }
    return nbr;
}

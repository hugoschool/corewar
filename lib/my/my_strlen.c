/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that counts and returns the number of characters
** found in the string passed as parameter.
*/

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }
    return count;
}

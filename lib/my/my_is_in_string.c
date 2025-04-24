/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** DEPRECATED: use my_strchr instead. This will be soon moved to libextras.
** Check if an element (char) is present within a string (char *).
*/

int my_is_in_string(char *string, char element)
{
    int nbr = 0;

    for (int i = 0; string[i] != '\0'; i++)
        if (string[i] == element)
            return 1;
    return nbr;
}

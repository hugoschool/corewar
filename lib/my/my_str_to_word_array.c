/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that splits a string into words.
*/

#include "my.h"

static int count_splits(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_alpha(str[i]) == 0)
            nb++;
    }
    return nb;
}

static int word_length(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_alpha(str[i]) == 1)
            nb++;
        else
            break;
    }
    return nb;
}

static int process_all_words(char **array, char const *str)
{
    int i = 0;
    int k = 0;
    int word_l = 0;

    for (int j = 0; j < my_strlen(str); j++) {
        word_l = word_length(&str[j]);
        if (word_l == 0)
            continue;
        array[i] = malloc(sizeof(char) * word_l + 1);
        for (k = 0; k < word_l; k++)
            array[i][k] = str[k + j];
        array[i][k] = '\0';
        j += word_l;
        i++;
    }
    return i;
}

char **my_str_to_word_array(char const *str)
{
    char **array;
    int splits_amount = count_splits(str) + 1;
    int i = 0;

    if (my_char_alpha(str[my_strlen(str) - 1]) == 1)
        splits_amount += 1;
    array = malloc(sizeof(char *) * splits_amount);
    i = process_all_words(array, str);
    array[i] = NULL;
    return array;
}

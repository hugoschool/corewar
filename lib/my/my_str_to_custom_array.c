/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that splits a string into words.
*/

#include "my.h"

static int count_splits(char const *str, char split_c)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == split_c)
            nb++;
    }
    return nb;
}

static int word_length(char const *str, char split_c)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != split_c)
            nb++;
        else
            break;
    }
    return nb;
}

static int process_all_words(char **array, char const *str, char split_c)
{
    int i = 0;
    int k = 0;
    int word_l = 0;

    for (int j = 0; j < my_strlen(str); j++) {
        word_l = word_length(&str[j], split_c);
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

char **my_str_to_custom_array(char const *str, char split_c)
{
    char **array;
    int splits_amount = count_splits(str, split_c) + 1;
    int i = 0;

    if (str[my_strlen(str) - 1] != split_c)
        splits_amount += 1;
    array = malloc(sizeof(char *) * splits_amount);
    i = process_all_words(array, str, split_c);
    array[i] = NULL;
    return array;
}

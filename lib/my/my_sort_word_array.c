/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that, using ascii order, sorts the words received via
** my_str_to_word_array. The sort should be executed by switching the
** array’s pointers.
*/

#include "my.h"

static void check_word(char **array, int j)
{
    if (my_strcmp(array[j - 1], array[j]) > 0) {
        my_swap((int *)&array[j], (int *)&array[j - 1]);
    }
}

int my_sort_word_array(char **tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        for (int j = 1; tab[j] != 0; j++) {
            check_word(tab, j);
        }
    }
    return 0;
}

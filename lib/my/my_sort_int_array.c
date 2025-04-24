/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that sorts an integer array in
** ascending order, given a pointer to the first
** element of the array and its size.
*/

#include "my.h"

static void check_int(int *array, int j)
{
    if (array[j - 1] > array[j]) {
        my_swap(&array[j], &array[j - 1]);
    }
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size; j++) {
            check_int(array, j);
        }
    }
}

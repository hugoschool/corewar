/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that swaps the content of
** two integers, whose addresses are given
** as a parameter.
*/

void my_swap(void *a, void *b)
{
    int swap;

    swap = *(int *)a;
    *(int *)a = *(int *)b;
    *(int *)b = swap;
}

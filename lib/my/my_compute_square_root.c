/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function that returns the square root
** (if it is a whole number) of the
** number given as argument.
*/

int my_compute_square_root(int nb)
{
    int rep = 0;

    for (int i = 0; i <= 46400; i++) {
        if (i * i == nb) {
            rep = i;
        }
    }
    return rep;
}

/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** Fills the first n bytes of s array with char c.
** Reproduces memset (same prototype except for size_t).
*/

void *my_memset(void *s, int c, int n)
{
    for (int i = 0; i < n; i++)
        ((char *)s)[i] = c;
    return s;
}

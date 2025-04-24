/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** A function which takes a character and
** displays that character.
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

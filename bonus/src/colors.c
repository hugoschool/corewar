/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** colors.c
*/

#include "raylib.h"
#include "corewar.h"

const Color colors[] = {
    RED,
    BLUE,
    GREEN,
    ORANGE
};

Color get_champ_color(int nb_player)
{
    return colors[(nb_player % (MAX_CHAMPIONS_AMT + 1)) - 1];
}

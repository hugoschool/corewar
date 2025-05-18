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

Color get_champ_color(champion_t *champion)
{
    return colors[(champion->nb_player % (MAX_CHAMPIONS_AMT + 1)) - 1];
}

/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** gameloop.c
*/

#include "corewar.h"

void update_champions(champion_t **champ)
{
    for (int i = 0; champ[i] != NULL; i++) {
        if (!champ[i]->alive)
            champ[i]->dead = true;
        champ[i]->alive = false;
    }
}

bool champs_alive(champion_t **champ)
{
    int alive = 0;

    for (int i = 0; champ[i] != NULL; i++) {
        if (!champ[i]->dead)
            alive++;
    }
    if (alive > 0)
        return true;
    return false;
}

void do_instructions(unsigned char map[MEM_SIZE], champion_t *champs)
{
    for (int i = 0; i < champs->nb_procs; i++)
        if (!champs->dead)
            instructions(map, champs, i);
}

void gameloop(unsigned char map[MEM_SIZE], champion_t **champ)
{
    int cycles = 0;
    int nb_alive = 0;
    int delta_cycles = 0;
    int nb_delta = 0;

    for (; true; cycles++) {
        if (!champs_alive(champ))
            break;
        for (int i = 0; champ[i] != NULL; i++)
            do_instructions(map, champ[i]);
        if (cycles == CYCLE_TO_DIE - (nb_delta * CYCLE_DELTA)) {
            cycles = 0;
            delta_cycles++;
            update_champions(champ);
        }
        if (delta_cycles == 40) {
            nb_delta++;
            delta_cycles = 0;
        }
    }
}

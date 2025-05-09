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
    if (alive > 1)
        return true;
    for (int i = 0; champ[i] != NULL; i++)
        if (!champ[i]->dead)
            mini_printf("The player %d(%s) has won.\n",
                champ[i]->nb_player, champ[i]->header.prog_name);
    return false;
}

void set_alive(champion_t **champs, int player_nb)
{
    for (int i = 0; champs[i] != NULL; i++) {
        if (!champs[i]->dead && champs[i]->nb_player == player_nb) {
            mini_printf("The player %d(%s) is alive.\n",
            champs[i]->nb_player, champs[i]->header.prog_name);
            champs[i]->alive = true;
        }
    }
}

void do_instructions(unsigned char map[MEM_SIZE], champion_t **champs,
    int index)
{
    int nb_player = 0;

    for (int i = 0; i < champs[index]->nb_procs; i++)
        if (!champs[index]->dead) {
            nb_player = instructions(map, champs[index], i);
            set_alive(champs, nb_player);
        }
}

void gameloop(unsigned char map[MEM_SIZE], flags_t *flags, champion_t **champ)
{
    int cycles = 0;
    int delta_cycles = 0;
    int nb_delta = 0;

    for (; true; cycles++) {
        if (!champs_alive(champ))
            break;
        for (int i = 0; champ[i] != NULL; i++)
            do_instructions(map, champ, i);
        print_map_cycle(flags, map, cycles);
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

/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** gameloop.c
*/

#include "corewar.h"

void update_champions_and_cycles(champion_t **champ, int *cycles)
{
    for (int i = 0; champ[i] != NULL; i++) {
        if (!champ[i]->alive)
            champ[i]->dead = true;
        for (int j = 0; j < champ[i]->nb_procs; j++) {
            champ[i]->procs[j].dead = champ[i]->procs[j].alive == true ?
                false : true;
            champ[i]->procs[j].alive = false;
        }
        champ[i]->alive = false;
    }
    *cycles = 0;
}

bool champs_alive(champion_t **champ)
{
    int alive = 0;
    static int nb_last = 0;

    for (int i = 0; champ[i] != NULL; i++) {
        if (!champ[i]->dead) {
            alive++;
            nb_last = champ[i]->nb_player;
        }
    }
    if (alive > 1)
        return true;
    for (int i = 0; champ[i] != NULL; i++)
        if (champ[i]->nb_player == nb_last)
            mini_printf("The player %d(%s) has won.\n",
                champ[i]->nb_player, champ[i]->header.prog_name);
    return false;
}

void set_alive(champion_t **champs, int player_nb, int *nb_live)
{
    for (int i = 0; champs[i] != NULL; i++) {
        if (!champs[i]->dead && champs[i]->nb_player == player_nb) {
            mini_printf("The player %d(%s) is alive.\n",
            champs[i]->nb_player, champs[i]->header.prog_name);
            champs[i]->alive = true;
            (*nb_live) += 1;
        }
    }
}

void do_instructions(unsigned char map[MEM_SIZE], champion_t **champs,
    int index, int *nb_live)
{
    int nb_player = 0;

    for (int i = 0; i < champs[index]->nb_procs; i++)
        if (!champs[index]->dead) {
            nb_player = instructions(map, champs[index], i);
            set_alive(champs, nb_player, nb_live);
        }
}

void gameloop(unsigned char map[MEM_SIZE], flags_t *flags, champion_t **champ)
{
    int cycles = 0;
    int nb_delta = 0;
    int tot_cycles = 0;
    int nb_live = 0;

    for (; true; cycles++) {
        if (!champs_alive(champ))
            break;
        for (int i = 0; champ[i] != NULL; i++)
            do_instructions(map, champ, i, &nb_live);
        print_map_cycle(flags, map, cycles);
        if (nb_live >= NBR_LIVE) {
            nb_delta++;
            nb_live = 0;
        }
        if (cycles >= (CYCLE_TO_DIE - (nb_delta * CYCLE_DELTA)))
            update_champions_and_cycles(champ, &cycles);
        tot_cycles++;
    }
    mini_printf("Number of cycles: %d\n", tot_cycles);
}

/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** champions.c
*/

#include "corewar.h"

void set_up_reg(process_t *proc, int r1)
{
    proc->registers[0] = r1 + 1;
    for (int i = 1; i < REG_NUMBER; i++) {
        proc->registers[i] = 0;
    }
}

int update_nb_player(champion_t *champion, int prog_number, int champ_i)
{
    if (prog_number != -1)
        champion->nb_player = prog_number;
    else {
        champion->nb_player = champ_i;
        champ_i++;
    }
    return champ_i;
}

champion_t **setup_champions(flags_t *flags)
{
    int amount = flags->champions_amt;
    int champ_i = 1;
    champion_t **champ = malloc(sizeof(champion_t *) * (amount + 1));

    for (int i = 0; i < amount; i++) {
        champ[i] = malloc(sizeof(champion_t));
        champ[i]->procs = malloc(sizeof(process_t));
        champ_i = update_nb_player(champ[i], flags->champions[i].prog_number,
            champ_i);
        champ[i]->alive = true;
        champ[i]->dead = false;
        champ[i]->nb_procs = 1;
        champ[i]->procs[0].cycles = 0;
        champ[i]->procs[0].alive = false;
        champ[i]->procs[0].carry = false;
        champ[i]->procs[0].dead = false;
        set_up_reg(&(champ[i]->procs[0]), i);
    }
    champ[amount] = NULL;
    return champ;
}

void free_champions(champion_t **champions)
{
    for (int i = 0; champions[i] != NULL; i++) {
        free(champions[i]->procs);
        free(champions[i]);
    }
    free(champions);
}

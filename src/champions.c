/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** champions.c
*/

#include "corewar.h"

champion_t **setup_champion(int amount)
{
    champion_t **champ = malloc(sizeof(champion_t *) * (amount + 1));

    for (int i = 0; i < amount; i++) {
        champ[i] = malloc(sizeof(champion_t));
        champ[i]->procs = malloc(sizeof(process_t));
        champ[i]->nb_player = i + 1;
        champ[i]->alive = false;
        champ[i]->dead = false;
        champ[i]->nb_procs = 1;
        champ[i]->procs[0].cycles = 0;
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

/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** live.c
*/

#include "corewar.h"

int live(char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    mini_printf("The player %d(%s) is alive.\n", champ->nb_player,
        champ->header.prog_name);
    champ->procs[proc_index].index += 5;
    return 0;
}

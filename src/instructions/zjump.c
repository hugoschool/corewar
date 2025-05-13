/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** zjump.c
*/

#include "corewar.h"

int do_zjump(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    short nb = (map[champ->procs[proc_index].index + 1] << 8) +
        map[champ->procs[proc_index].index + 2];

    if (champ->procs[proc_index].carry)
        champ->procs[proc_index].index += nb % IDX_MOD;
    else
        champ->procs[proc_index].index += 3;
    return 0;
}

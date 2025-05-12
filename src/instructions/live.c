/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** live.c
*/

#include "corewar.h"

int live(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    champ->procs[proc_index].index += 5;
    champ->procs[proc_index].alive = true;
    return map[champ->procs[proc_index].index - 1];
}

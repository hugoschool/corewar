/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** ld.c
*/

#include "corewar.h"

int do_ld(char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    champ->procs[proc_index].index += 7;
    return 0;
}

int do_lld(char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    champ->procs[proc_index].index += 7;
    return 0;
}

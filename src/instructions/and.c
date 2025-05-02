/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** and.c
*/

#include "corewar.h"

int do_and(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    champ->procs[proc_index].index += 11;
    return 0;
}

int do_or(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    champ->procs[proc_index].index += 11;
    return 0;
}

int do_xor(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    champ->procs[proc_index].index += 11;
    return 0;
}

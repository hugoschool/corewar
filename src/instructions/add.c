/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** add.c
*/

#include "corewar.h"

int do_add(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    champ->procs[proc_index].index += 5;
    return 0;
}

int do_sub(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    champ->procs[proc_index].index += 5;
    return 0;
}

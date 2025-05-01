/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** fork.c
*/

#include "corewar.h"

int do_fork(char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    champ->procs[proc_index].index += 3;
    return 0;
}

int do_lfork(char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    champ->procs[proc_index].index += 3;
    return 0;
}

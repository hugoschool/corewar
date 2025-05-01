/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** zjump.c
*/

#include "corewar.h"

int do_zjump(char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    champ->procs[proc_index].index += 3;
    return 0;
}

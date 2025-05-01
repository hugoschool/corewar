/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** aff.c
*/

#include "corewar.h"

int do_aff(char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    champ->procs[proc_index].index += 2;
    return 0;
}

/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** ldi.c
*/

#include "corewar.h"

int do_ldi(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    champ->procs[proc_index].index += 7;
    return 0;
}

int do_lldi(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    champ->procs[proc_index].index += 7;
    return 0;
}

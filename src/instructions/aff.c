/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** aff.c
*/

#include "corewar.h"

int do_aff(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    int index = champ->procs[proc_index].index;
    int val = map[index + 2] < REG_NUMBER ?
        champ->procs[proc_index].registers[map[index + 2] - 1] : 0;

    mini_printf("%c\n", val % 256);
    champ->procs[proc_index].index += 3;
    return 0;
}

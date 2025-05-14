/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** live.c
*/

#include "corewar.h"

int live(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    int index = champ->procs[proc_index].index + 1;
    int value = (map[index] << 24) + (map[index + 1] << 16) +
        (map[index + 2] << 8) + map[index + 3];

    champ->procs[proc_index].alive = true;
    champ->procs[proc_index].index += 5;
    return value;
}

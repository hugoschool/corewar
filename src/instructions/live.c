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
    int value = 0;

    while (index < 0)
        index += MEM_SIZE;
    value = (map[index % MEM_SIZE] << 24) +
        (map[(index + 1) % MEM_SIZE] << 16) +
        (map[(index + 2) % MEM_SIZE] << 8) + map[(index + 3) % MEM_SIZE];
    champ->procs[proc_index].alive = true;
    champ->procs[proc_index].index += 5;
    return value;
}

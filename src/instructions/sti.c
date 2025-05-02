/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** sti.c
*/

#include "corewar.h"

int do_sti(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    int index = champ->procs[proc_index].index;
    uint8_t arg1[2] = {map[index + 3], map[index + 4]};
    uint8_t arg2[2] = {map[index + 5], map[index + 6]};
    uint16_t targ1 = (arg1[0] << 8) + arg1[1];
    uint16_t targ2 = (arg2[0] << 8) + arg2[1];
    int where = targ1 + targ2 + index;
    uint8_t replace[4] = {
        champ->procs[proc_index].registers[map[index + 2] - 1] << 24,
        champ->procs[proc_index].registers[map[index + 2] - 1] << 16,
        champ->procs[proc_index].registers[map[index + 2] - 1] << 8,
        champ->procs[proc_index].registers[map[index + 2] - 1] << 0};

    for (int i = 0; i < 4; i++)
        map[where + i] = replace[i];
    champ->procs[proc_index].index += 7;
    return 0;
}

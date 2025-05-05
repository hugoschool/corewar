/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** sti.c
*/

#include "corewar.h"

uint16_t get_len(unsigned char map[MEM_SIZE], int index, args_type_t type,
    int *nb_bytes)
{
    uint16_t arg = 0;
    if (type == 1) {
        (*nb_bytes)++;
        arg = map[index + *nb_bytes];
    }
    if (type == 2) {
        (*nb_bytes) += 2;
        arg = (map[index + *nb_bytes - 1] << 8) + map[index + *nb_bytes];
    }
    return arg;
}

int do_sti(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    int index = champ->procs[proc_index].index;
    args_type_t *params = byte_to_args(map[index + 1]);
    int count_bytes = 2;
    uint16_t targ1 = get_len(map, index, params[1], &count_bytes);
    uint16_t targ2 = get_len(map, index, params[2], &count_bytes);
    int where = targ1 + targ2 + index;
    uint8_t replace[4] = {
        champ->procs[proc_index].registers[map[index + 2] - 1] << 24,
        champ->procs[proc_index].registers[map[index + 2] - 1] << 16,
        champ->procs[proc_index].registers[map[index + 2] - 1] << 8,
        champ->procs[proc_index].registers[map[index + 2] - 1] << 0};

    for (int i = 0; i < 4; i++)
        map[where + i] = replace[i];
    champ->procs[proc_index].index += count_bytes + 1;
    return 0;
}

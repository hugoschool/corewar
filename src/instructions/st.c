/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** st.c
*/

#include "corewar.h"

static void rep_map(int val, unsigned char map[MEM_SIZE], int index)
{
    map[index] = (val << 24);
    map[index + 1] = val << 16;
    map[index + 2] = val << 8;
    map[index + 3] = val << 0;
}

int do_st(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    int index = champ->procs[proc_index].index;
    args_type_t *types = byte_to_args(map[index + 1]);
    int val = 0;

    if (types[1] == 1) {
        val = champ->procs->registers[map[index + 2] - 1];
        champ->procs[proc_index].registers[map[index + 3] - 1] = val;
    }
    if (types[1] == 3) {
        val = (map[index + 3] << 8) + map[index + 4];
        rep_map(champ->procs[proc_index].registers[map[index + 2] - 1],
            map, index + (val % IDX_MOD));
    }
    champ->procs[proc_index].index += 7;
    free(types);
    return 0;
}

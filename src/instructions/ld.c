/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** ld.c
*/

#include "corewar.h"

int get_value(unsigned char map[MEM_SIZE], process_t *proc, args_type_t type)
{
    int index = proc->index;
    int value = 0;

    if (type == 2) {
        value = (map[index + 2] << 24) + (map[index + 3] << 16) +
            (map[index + 4] << 8) + map[index + 5];
        proc->index += 6;
    }
    if (type == 3) {
        value = (map[index + 2] << 8) + map[index + 3];
        proc->index += 4;
    }
    return value;
}

int get_val_ind(unsigned char map[MEM_SIZE], int index)
{
    return (map[index] << 24) + (map[index + 1] << 16) + (map[index + 2] << 8)
        + map[index];
}

static void main_ld(unsigned char map[MEM_SIZE], champion_t *champ,
    int proc_index, bool lld)
{
    int index = champ->procs[proc_index].index;
    args_type_t *types = byte_to_args(map[get_correct_index(index + 1)]);
    int val = get_value(map, &(champ->procs[proc_index]), types[0]);

    index = champ->procs[proc_index].index;
    if (lld)
        val %= IDX_MOD;
    if (types[0] != 3)
        champ->procs[proc_index].registers[map[get_correct_index(index)] - 1] = val;
    else
        champ->procs[proc_index].registers[map[get_correct_index(index)] - 1] = get_val_ind(map,
            val);
    champ->procs[proc_index].carry = val == 0 ? 1 : 0;
    champ->procs[proc_index].index += 1;
    free(types);
}

int do_ld(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    main_ld(map, champ, proc_index, false);
    return 0;
}

int do_lld(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    main_ld(map, champ, proc_index, true);
    return 0;
}

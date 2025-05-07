/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** and.c
*/

#include "corewar.h"

static int index_nb_bytes(args_type_t *types)
{
    int bytes = 0;

    for (int i = 0; i < 2; i++)
        bytes += get_nb_bytes(types[i]);
    bytes += 3;
    return bytes;
}

static int value_of_type(process_t *proc, args_type_t type,
    unsigned char map[MEM_SIZE], int *index)
{
    int cur_val = 0;

    if (type == 1) {
        cur_val = proc->registers[map[*index] - 1];
        *index++;
    }
    if (type == 2) {
        cur_val = (map[*index] << 24) + (map[*index + 1] << 16) +
            (map[*index + 2] << 8) + map[*index + 3];
        index += 4;
    }
    return cur_val;
}

int do_and(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    int index = champ->procs[proc_index].index + 1;
    args_type_t *types = byte_to_args(map[index]);
    int value = 0;
    int cur_val = 0;

    index++;
    for (int i = 0; i < 2; i++) {
        cur_val = value_of_type(&(champ->procs[proc_index]), types[i],
            map, &index);
        if (value == 0)
            value = cur_val;
        else
            value = value & cur_val;
    }
    champ->procs[proc_index].registers[map[index] - 1] = value;
    champ->procs[proc_index].index += index_nb_bytes(types);
    free(types);
    return 0;
}

int do_or(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    champ->procs[proc_index].index += 11;
    return 0;
}

int do_xor(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    champ->procs[proc_index].index += 11;
    return 0;
}

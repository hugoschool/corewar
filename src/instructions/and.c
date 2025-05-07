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
    unsigned char map[MEM_SIZE], int index)
{
    int value = 0;

    if (type == 1)
        value = proc->registers[map[index] - 1];
    if (type == 2)
        value = (map[index] << 24) + (map[index + 1] << 16) +
            (map[index + 2] << 8) + map[index + 3];
    if (type == 3)
        value = (map[index] << 8) + map[index + 1];
    return value;
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
            map, index);
        index += get_nb_bytes(types[i]);
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
    int index = champ->procs[proc_index].index + 1;
    args_type_t *types = byte_to_args(map[index]);
    int value = 0;
    int cur_val = 0;

    index++;
    for (int i = 0; i < 2; i++) {
        cur_val = value_of_type(&(champ->procs[proc_index]), types[i],
            map, index);
        index += get_nb_bytes(types[i]);
        if (value == 0)
            value = cur_val;
        else
            value = value | cur_val;
    }
    champ->procs[proc_index].registers[map[index] - 1] = value;
    champ->procs[proc_index].index += index_nb_bytes(types);
    free(types);
    return 0;
}

int do_xor(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    int index = champ->procs[proc_index].index + 1;
    args_type_t *types = byte_to_args(map[index]);
    int value = 0;
    int cur_val = 0;

    index++;
    for (int i = 0; i < 2; i++) {
        cur_val = value_of_type(&(champ->procs[proc_index]), types[i],
            map, index);
        index += get_nb_bytes(types[i]);
        if (value == 0)
            value = cur_val;
        else
            value = value ^ cur_val;
    }
    champ->procs[proc_index].registers[map[index] - 1] = value;
    champ->procs[proc_index].index += index_nb_bytes(types);
    free(types);
    return 0;
}

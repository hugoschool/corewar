/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** ldi.c
*/

#include "corewar.h"

static int ldi_nb_bytes(args_type_t *types)
{
    int bytes = 0;

    for (int i = 0; i < 2; i++)
        bytes += get_nb_bytes(types[i]);
    bytes += 3;
    return bytes;
}

static int get_value(process_t proc, args_type_t type,
    unsigned char map[MEM_SIZE], int index)
{
    int value = 0;

    if (type == 1)
        value = proc.registers[map[index] - 1];
    else
        value = (map[index] << 8) + map[index + 1];
    return value;
}

static void main_ldi(unsigned char map[MEM_SIZE], champion_t *champ,
    int proc_index, bool lldi)
{
    int index = champ->procs[proc_index].index + 1;
    args_type_t *types = byte_to_args(map[index]);
    int value = 0;

    get_value(champ->procs[proc_index], types[0], map, index + 1);
    index += get_nb_bytes(types[0]);
    value += get_value(champ->procs[proc_index], types[1], map, index);
    index += get_nb_bytes(types[1]);
    if (!lldi)
        value = value % IDX_MOD;
    champ->procs[proc_index].registers[map[index + 3] - 1] = value;
    champ->procs[proc_index].index += ldi_nb_bytes(types);
    free(types);
}

int do_ldi(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    main_ldi(map, champ, proc_index, false);
    return 0;
}

int do_lldi(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    main_ldi(map, champ, proc_index, true);
    return 0;
}

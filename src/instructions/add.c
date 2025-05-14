/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** add.c
*/

#include "corewar.h"

static void add_or_sub(process_t *proc, unsigned char map[MEM_SIZE],
    int index, bool sub)
{
    int first_register = map[index] < REG_NUMBER ?
        proc->registers[map[index] - 1] : 0;
    int second_register = map[index + 1] < REG_NUMBER ?
        proc->registers[map[index + 1] - 1] : 0;
    int value = 0;

    if (map[index + 2] >= REG_NUMBER)
        return;
    if (!sub)
        value = first_register + second_register;
    else
        value = first_register - second_register;
    proc->registers[map[index + 2] - 1] = value;
    proc->carry = proc->registers[map[index + 2] - 1] == 0 ? 1 : 0;
}

int do_add(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    int index = champ->procs[proc_index].index + 2;

    add_or_sub(&champ->procs[proc_index], map, index, false);
    champ->procs[proc_index].index += get_inst_size(map[index - 1]);
    return 0;
}

int do_sub(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    int index = champ->procs[proc_index].index + 2;

    add_or_sub(&champ->procs[proc_index], map, index, true);
    champ->procs[proc_index].index += get_inst_size(map[index - 1]);
    return 0;
}

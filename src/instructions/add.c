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
    int first_register = proc->registers[map[index]];
    int second_register = proc->registers[map[index + 1]];

    if (!sub)
        proc->registers[map[index + 2]] = first_register + second_register;
    else
        proc->registers[map[index + 2]] = first_register - second_register;
}

int do_add(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    int index = champ->procs[proc_index].index + 2;

    add_or_sub(&champ->procs[proc_index], map, index, false);
    champ->procs[proc_index].index += 5;
    return 0;
}

int do_sub(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    int index = champ->procs[proc_index].index + 2;

    add_or_sub(&champ->procs[proc_index], map, index, true);
    printf("r%d: %d\n", map[index + 2], champ->procs[proc_index].registers[map[index + 2]]);
    champ->procs[proc_index].index += 5;
    return 0;
}

/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** instructions.c
*/

#include "corewar.h"

op_t get_instruction(unsigned char map[MEM_SIZE], int index)
{
    int i = 0;

    for (; op_tab[i].code != 0; i++)
        if (op_tab[i].code == map[index])
            return op_tab[i];
    return op_tab[i];
}

void instructions(unsigned char map[MEM_SIZE], champion_t *champ,
    int proc_index)
{
    op_t inst = get_instruction(map, champ->procs[proc_index].index);

    if (champ->procs[proc_index].cycles >= inst.nbr_cycles) {
        do_inst[inst.code](map, champ, proc_index);
        champ->procs[proc_index].cycles = 0;
    } else
        champ->procs[proc_index].cycles++;
    if (champ->procs[proc_index].index >= MEM_SIZE)
        champ->procs[proc_index].index = 0;
}

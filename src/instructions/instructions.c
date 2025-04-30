/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** instructions.c
*/

#include "corewar.h"

op_t get_instruction(char map[MEM_SIZE], int index)
{
    int i = 0;

    for (; op_tab[i].code != 0; i++)
        if (op_tab[i].code == map[index])
            return op_tab[i];
    return op_tab[i];
}

void instructions(char map[MEM_SIZE], process_t *proc)
{
    op_t inst = get_instruction(map, proc->index);

    printf("%s\n", inst.mnemonique);
    // inst.do_inst(map, proc->index);
}

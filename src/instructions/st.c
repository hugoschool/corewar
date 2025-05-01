/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** st.c
*/

#include "corewar.h"

int do_st(char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    champ->procs[proc_index].index += 7;
    return 0;
}

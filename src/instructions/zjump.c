/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** zjump.c
*/

#include "corewar.h"

int do_zjump(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    uint8_t nb1 = map[champ->procs[proc_index].index + 1];
    uint8_t nb2 = map[champ->procs[proc_index].index + 2];
    int16_t nb3 = (nb1 << 8) + (nb2);

    nb3 = nb3 % IDX_MOD;
    champ->procs[proc_index].index += nb3;
    return 0;
}

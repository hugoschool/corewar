/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** zjump.c
*/

#include "corewar.h"

int do_zjump(char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    int nb1 = map[champ->procs[proc_index].index + 1];
    int nb2 = map[champ->procs[proc_index].index + 2];
    int nb3 = nb1 +nb2;

    champ->procs[proc_index].index += nb3;
    return 0;
}

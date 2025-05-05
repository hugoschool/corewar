/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** fork.c
*/

#include "corewar.h"

int create_new_proc(unsigned char map[MEM_SIZE], champion_t *champ, int p_index)
{
    uint8_t params[2] = {map[champ->procs[p_index].index + 1],
        map[champ->procs[p_index].index + 1]};
    int16_t t_param = params[0] << 8 + params[1] << 0;

    champ->procs = realloc(champ->procs, sizeof(process_t) *
        (champ->nb_procs + 1));
    champ->nb_procs++;
    champ->procs[champ->nb_procs - 1].cycles = 0;
    for (int i = 0; i < REG_NUMBER; i++) {
        champ->procs[champ->nb_procs - 1].registers[i] =
            champ->procs[p_index].registers[i];
    }
    champ->procs[champ->nb_procs - 1].index = t_param;
}

int do_fork(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    create_new_proc(map, champ, proc_index);
    champ->procs[champ->nb_procs - 1].index %= IDX_MOD;
    champ->procs[proc_index].index += 3;
    return 0;
}

int do_lfork(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index)
{
    create_new_proc(map, champ, proc_index);
    champ->procs[proc_index].index += 3;
    return 0;
}

/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** sti_ray.c
*/

#include "corewar.h"
#include "raylib.h"
#include "bonus.h"

int get_len_ray(unsigned char map[MEM_SIZE], process_t *proc, args_type_t type,
    int *nb_bytes)
{
    int arg = 0;

    if (type == 1) {
        (*nb_bytes)++;
        arg = map[proc->index + *nb_bytes];
        arg = proc->registers[arg - 1];
    }
    if (type == 2) {
        (*nb_bytes) += 2;
        arg = (map[proc->index + *nb_bytes - 1] << 8) +
            map[proc->index + *nb_bytes];
    }
    return arg;
}

int sti_ray(map_t *map, champion_t *champ, int proc_index)
{
    int index = champ->procs[proc_index].index;
    args_type_t *params = byte_to_args(map->byte[index + 1]);
    int count_bytes = 2;
    int targ1 = get_len_ray(map->byte, &(champ->procs[proc_index]), params[1],
        &count_bytes);
    int targ2 = get_len_ray(map->byte, &(champ->procs[proc_index]), params[2],
        &count_bytes);
    int where = targ1 + targ2 + index;
    int reg = champ->procs[proc_index].registers
        [get_reg_index(map->byte[index + 2])];
    uint8_t replace[4] = {reg << 24, reg << 16, reg << 8, reg << 0};

    for (int i = 0; i < 4; i++) {
        map->byte[(where + i) % MEM_SIZE] = replace[i];
        map->color[(where + i) % MEM_SIZE] = get_champ_color(champ->nb_player);
    }
    champ->procs[proc_index].index += count_bytes + 1;
    free(params);
    return 0;
}

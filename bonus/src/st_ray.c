/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** st_ray.c
*/

#include "corewar.h"
#include "raylib.h"
#include "bonus.h"

static void rep_map(int val, map_t *map, int index, int player_nb)
{
    map->byte[index] = (val << 24);
    map->byte[index + 1] = val << 16;
    map->byte[index + 2] = val << 8;
    map->byte[index + 3] = val << 0;
    for (int i = 0; i < 4; i++)
        map->color[index + i] = colors[player_nb - 1];
}

int st_ray(map_t *map, champion_t *champ, int proc_index)
{
    int index = champ->procs[proc_index].index;
    args_type_t *types = byte_to_args(map->byte[index + 1]);
    int val = 0;

    if (types[1] == 1 && map->byte[index + 2] <= REG_NUMBER && map->byte[index + 2] > 0 &&
        map->byte[index + 3] <= REG_NUMBER && map->byte[index + 3] > 0) {
        val = champ->procs[proc_index].registers[map->byte[index + 2] - 1];
        champ->procs[proc_index].registers[map->byte[index + 3] - 1] = val;
    }
    if (types[1] == 3 && map->byte[index + 2] <= REG_NUMBER && map->byte[index + 2] > 0) {
        val = (map->byte[index + 3] << 8) + map->byte[index + 4];
        rep_map(champ->procs[proc_index].registers[map->byte[index + 2] - 1],
            map, index + (val % IDX_MOD), champ->nb_player);
    }
    champ->procs[proc_index].index += get_inst_size(map->byte[index + 1]);
    free(types);
    return 0;
}

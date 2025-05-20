/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** vm_ray.c
*/

#include "corewar.h"
#include "bonus.h"
#include "raylib.h"

bool add_to_map_and_champ(map_t *map,
    flag_prog_t champ, int index, champion_t *champion)
{
    struct stat info;

    fseek(champ.fp, 0, SEEK_SET);
    printf("pg_name: %s\n", champ.prog_name);
    if (stat(champ.prog_name, &info) == -1)
        return false;
    fread(&(champion->header), sizeof(header_t), 1, champ.fp);
    if (ltb_endian(champion->header.magic) != COREWAR_EXEC_MAGIC)
        return false;
    if (champ.load_address != -1)
        champion->procs[0].index = champ.load_address % MEM_SIZE;
    else
        champion->procs[0].index = index;
    fread(&(map->byte[champion->procs[0].index]), sizeof(char),
        info.st_size - sizeof(header_t), champ.fp);
    for (uint64_t i = champion->procs[0].index; i <
        champion->procs[0].index + info.st_size - sizeof(header_t); i++) {
        map->color[i] = get_champ_color(champion->nb_player % 4);
        map->is_index[i] = false;
   }
    return true;
}

int do_vm_ray(flags_t *flags)
{
    map_t map;
    int index = 0;
    champion_t **champ = setup_champions(flags);
    bool restart = false;

    for (int i = 0; i < MEM_SIZE; i++) {
        map.byte[i] = 0;
        map.color[i] = RAYWHITE;
        map.is_index[i] = false;
    }
    for (int i = 0; i < flags->champions_amt; i++) {
        if (!add_to_map_and_champ(&map, flags->champions[i], index, champ[i])) {
            free_champions(champ);
            return 84;
        }
        champ[i]->count_dead = 0;
        index += MEM_SIZE / flags->champions_amt;
    }
    restart = gameloop_ray(&map, flags, champ);
    print_map(map.byte);
    free_champions(champ);
    return restart;
}

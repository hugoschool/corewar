/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** inst_ray.c
*/

#include "corewar.h"
#include "raylib.h"
#include "bonus.h"
#include "llist.h"

op_t get_instruction_ray(unsigned char map[MEM_SIZE], int index)
{
    int i = 0;

    for (; op_tab[i].code != 0; i++) {
        if (op_tab[i].code == map[index]) {
            return op_tab[i];
        }
    }
    return op_tab[i];
}

int inst_ray(map_t *map, champion_t *champ, int proc_index, float speed, linked_list_t **list)
{
    op_t inst = get_instruction_ray(map->byte, champ->procs[proc_index].index);
    int nb_player = 0;
    char *inst_str = NULL;

    if (champ->procs[proc_index].index >= MEM_SIZE)
        champ->procs[proc_index].index = 0;
    if (champ->procs[proc_index].cycles >= inst.nbr_cycles) {
        if (inst.code == 0) {
            champ->procs[proc_index].index++;
            return 0;
        }
        if (!champ->procs[proc_index].dead) {
            inst_str = calloc((my_strlen(inst.mnemonique) + my_strlen(champ->header.prog_name) + 10), sizeof(char));
            sprintf(inst_str, "%s: %s", champ->header.prog_name, inst.mnemonique);
            push_to_list(list, inst_str);
            if (inst.code == 3)
                st_ray(map, champ, proc_index);
            else if (inst.code == 0x0b)
                sti_ray(map, champ, proc_index);
            else
                nb_player = do_inst[inst.code - 1](map->byte, champ, proc_index);
        }
        champ->procs[proc_index].cycles = 0;
    } else
        champ->procs[proc_index].cycles += (int)speed;
    return nb_player;
}

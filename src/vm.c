/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** vm.c
*/

#include "corewar.h"

int add_to_map_and_champ(unsigned char map[MEM_SIZE],
    flag_prog_t champ, int index, champion_t *champion)
{
    struct stat info;

    fseek(champ.fp, 0, SEEK_SET);
    stat(champ.prog_name, &info);
    fread(&(champion->header), sizeof(header_t), 1, champ.fp);
    if (champ.load_address != -1)
        champion->procs[0].index = champ.load_address;
    else
        champion->procs[0].index = index;
    fread(&map[champion->procs[0].index], sizeof(char),
        info.st_size - sizeof(header_t), champ.fp);
    return 0;
}

int do_vm(flags_t *flags)
{
    unsigned char map[MEM_SIZE];
    int index = 0;
    champion_t **champ = setup_champions(flags);

    for (int i = 0; i < MEM_SIZE; i++)
        map[i] = 0;
    for (int i = 0; i < flags->champions_amt; i++) {
        add_to_map_and_champ(map, flags->champions[i], index, champ[i]);
        index += MEM_SIZE / flags->champions_amt;
    }
    gameloop(map, flags, champ);
    print_map(map);
    free_champions(champ);
    return 0;
}

/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** vm.c
*/

#include "corewar.h"

int add_to_map_and_champ(unsigned char map[MEM_SIZE],
    flag_prog_t champ, int champ_s, champion_t *champion)
{
    struct stat info;

    fseek(champ.fp, 0, SEEK_SET);
    stat(champ.prog_name, &info);
    fread(&(champion->header), sizeof(header_t), 1, champ.fp);
    champion->procs[0].index = champ_s;
    fread(&map[champ_s], sizeof(char), info.st_size - sizeof(header_t),
        champ.fp);
    return 0;
}

void temp_debug(champion_t **champs, unsigned char map[MEM_SIZE])
{
    for (int i = 0; i < MEM_SIZE; i++)
        printf("%02x", map[i]);
    printf("\n");
    for (int i = 0; champs[i] != NULL; i++) {
        printf("%s %d\n", champs[i]->header.prog_name, champs[i]->nb_player);
    }
}

int do_vm(flags_t *champions)
{
    unsigned char vm[MEM_SIZE];
    int index = 0;
    champion_t **champ = setup_champion(champions->champions_amt);

    for (int i = 0; i < MEM_SIZE; i++)
        vm[i] = 0;
    for (int i = 0; champions->champions[i].active == true; i++) {
        add_to_map_and_champ(vm, champions->champions[i], index, champ[i]);
        index += MEM_SIZE / champions->champions_amt;
    }
    gameloop(vm, champ);
    temp_debug(champ, vm);
    free_champions(champ);
    return 0;
}

/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** vm.c
*/

#include "corewar.h"

int add_to_map(unsigned char map[MEM_SIZE], flag_prog_t *champ, int champ_s)
{
    struct stat info;
    header_t tmp;

    fseek(champ->fp, 0, SEEK_SET);
    stat(champ->prog_name, &info);
    fread(&tmp, sizeof(header_t), 1, champ->fp);
    fread(&map[champ_s], sizeof(char), info.st_size - sizeof(header_t), champ->fp);
    return 0;
}

int vm(flags_t *champions)
{
    unsigned char vm[MEM_SIZE];
    int champ_s = 0;

    for (int i = 0; i < MEM_SIZE; i++)
        vm[i] = 0;
    for (int i = 0; champions->champions[i].active == true; i++, champ_s += MEM_SIZE / 4)
        add_to_map(vm, &(champions->champions[i]), champ_s);
    for (int i = 0; i < MEM_SIZE; i++)
        printf("%02x", vm[i]);
    printf("\n");
    return 0;
}

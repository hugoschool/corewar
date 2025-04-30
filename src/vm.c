/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** vm.c
*/

#include "corewar.h"

int add_to_map_and_proc(unsigned char map[MEM_SIZE],
    flag_prog_t *champ, int champ_s, process_t *proc)
{
    struct stat info;

    fseek(champ->fp, 0, SEEK_SET);
    stat(champ->prog_name, &info);
    fread(&(proc->champion->header), sizeof(header_t), 1, champ->fp);
    proc->index = champ_s;
    fread(&map[champ_s], sizeof(char), info.st_size - sizeof(header_t),
    champ->fp);
    return 0;
}

process_t **setup_process(int amount)
{
    process_t **proc = malloc(sizeof(process_t *) * (amount + 1));

    for (int i = 0; i < amount; i++) {
        proc[i] = malloc(sizeof(process_t));
        proc[i]->index = 0;
        proc[i]->champion = malloc(sizeof(champion_t));
        proc[i]->champion->nb_player = 0;
    }
    proc[amount] = NULL;
    return proc;
}

int vm(flags_t *champions)
{
    unsigned char vm[MEM_SIZE];
    int champ_s = 0;
    process_t **proc = setup_process(champions->champions_amt);

    for (int i = 0; i < MEM_SIZE; i++)
        vm[i] = 0;
    for (int i = 0; champions->champions[i].active == true; i++,
        champ_s += MEM_SIZE / champions->champions_amt) {
            add_to_map_and_proc(vm, &(champions->champions[i]), champ_s, proc[i]);
        }
    for (int i = 0; i < MEM_SIZE; i++)
        printf("%02x", vm[i]);
    printf("\n");
    for (int i = 0; proc[i] != NULL; i++) {
        printf("%s %d\n", proc[i]->champion->header.prog_name, proc[i]->index);
        instructions(vm, proc[i]);
    }

    return 0;
}

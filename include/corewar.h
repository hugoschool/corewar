/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar.h
*/

#ifndef COREWAR_H_
    #define COREWAR_H_

    #include "my.h"
    #include "op.h"
    #include <stdbool.h>
    #include <stdio.h>
    #include <sys/stat.h>

    #define MAX_CHAMPIONS_AMT 4

// Flags
typedef struct {
    bool active;
    int prog_number;
    int load_address;
    char *prog_name;
    FILE *fp;
} flag_prog_t;

typedef struct flags_s {
    int dump;
    flag_prog_t *champions;
    int champions_amt;
} flags_t;

flags_t *parse_flags(int argc, char **argv);
void free_flags(flags_t *flags);

//Process
typedef struct {
    int index;
    int registers[REG_NUMBER];
    int cycles;
} process_t;

// Champions
typedef struct champion_s {
    header_t header;
    process_t *procs;
    int nb_procs;
    int nb_player;
    bool alive;
    bool dead;
} champion_t;
champion_t **setup_champion(int amount);
void free_champions(champion_t **champions);

// Arena
typedef struct arena_s {
    unsigned char arena[MEM_SIZE];
    champion_t champions[MAX_CHAMPIONS_AMT];
} arena_t;
int do_vm(flags_t *champions);
void gameloop(unsigned char map[MEM_SIZE], champion_t **champ);

// Instructions
void instructions(unsigned char map[MEM_SIZE],
    champion_t *champ, int proc_index);
int live(char map[MEM_SIZE], champion_t *champ, int pro_index);
int do_st(char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_add(char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_sub(char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_and(char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_or(char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_xor(char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_zjump(char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_ld(char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_lld(char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_ldi(char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_lldi(char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_sti(char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_fork(char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_lfork(char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_aff(char map[MEM_SIZE], champion_t *champ, int proc_index);

extern int const(*do_inst[])(char map[MEM_SIZE],
    champion_t *champ, int proc_index);
#endif

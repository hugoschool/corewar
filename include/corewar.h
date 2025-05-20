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
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <limits.h>
    #include <stdint.h>
    #include <time.h>

    #define DEFAULT_FLAG_NB -1
    #define MAX_CHAMPIONS_AMT 4

    #define ANSI_RED "\033[1;31m"
    #define ANSI_RESET "\033[0;0m"

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
    bool carry;
    bool alive;
    bool dead;
} process_t;

// Champions
typedef struct champion_s {
    header_t header;
    process_t *procs;
    int nb_procs;
    int nb_player;
    clock_t count_dead;
    bool alive;
    bool dead;
} champion_t;
champion_t **setup_champions(flags_t *flags);
void free_champions(champion_t **champions);

// Arena
int do_vm(flags_t *flags);
void gameloop(unsigned char map[MEM_SIZE], flags_t *flags, champion_t **champ);

// Instructions
int instructions(unsigned char map[MEM_SIZE],
    champion_t *champ, int proc_index);
int live(unsigned char map[MEM_SIZE], champion_t *champ, int pro_index);
int do_st(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_add(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_sub(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_and(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_or(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_xor(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_zjump(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_ld(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_lld(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_ldi(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_lldi(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_sti(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_fork(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_lfork(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index);
int do_aff(unsigned char map[MEM_SIZE], champion_t *champ, int proc_index);

typedef int (*inst_t)(unsigned char map[MEM_SIZE],
    champion_t *champ, int proc_index);

extern const inst_t do_inst[];

//Utils
void print_map(unsigned char map[MEM_SIZE]);
void print_map_cycle(flags_t *flags, unsigned char map[MEM_SIZE], int cycles);
int ltb_endian(int little);
args_type_t *byte_to_args(uint8_t byte);
int get_nb_bytes(args_type_t args);
int get_inst_size(unsigned char coding_byte);
int get_correct_index(int index);


#endif

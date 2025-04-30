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

// Champions
typedef struct champion_s {
    header_t header;
    int registers[REG_NUMBER];
    int nb_player;
} champion_t;

typedef struct {
    int index;
    champion_t *champion;
} process_t;

// Arena
typedef struct arena_s {
    unsigned char arena[MEM_SIZE];
    champion_t champions[MAX_CHAMPIONS_AMT];
} arena_t;
int vm(flags_t *champions);

// Instructions
void instructions(char map[MEM_SIZE], process_t *proc);
int live(char map[MEM_SIZE], process_t *fork);
#endif

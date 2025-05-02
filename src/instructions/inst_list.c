/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** inst_list.c
*/

#include "corewar.h"

int const(*do_inst[])(unsigned char map[MEM_SIZE],
    champion_t *champ, int nb_proc) = {
    live,
    do_ld,
    do_st,
    do_add,
    do_sub,
    do_and,
    do_or,
    do_xor,
    do_zjump,
    do_ldi,
    do_sti,
    do_fork,
    do_lld,
    do_lldi,
    do_lfork,
    do_aff
};

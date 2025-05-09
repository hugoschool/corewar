/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** print_map.c
*/

#include "corewar.h"

static char handle_hex_char(int nb)
{
    if (nb == 10)
        return 'A';
    if (nb == 11)
        return 'B';
    if (nb == 12)
        return 'C';
    if (nb == 13)
        return 'D';
    if (nb == 14)
        return 'E';
    if (nb == 15)
        return 'F';
    return nb + '0';
}

void print_hex(unsigned char nb)
{
    char hex[3];
    int i = 0;

    while (nb >= 16) {
        hex[i] = handle_hex_char(nb % 16);
        nb = nb / 16;
        i++;
    }
    hex[i] = handle_hex_char(nb % 16);
    if (i == 0) {
        i++;
        hex[i] = '0';
    }
    hex[i + 1] = '\0';
    mini_printf("%s", my_revstr(hex));
}

void print_map(unsigned char map[MEM_SIZE])
{
    for (int i = 0; i < MEM_SIZE; i++) {
        if (map[i] != 0)
            mini_printf(ANSI_RED);
        print_hex(map[i]);
        if (map[i] != 0)
            mini_printf(ANSI_RESET);
    }
    mini_printf("\n");
}

void print_map_cycle(flags_t *flags, unsigned char map[MEM_SIZE], int cycles)
{
    if (flags->dump == cycles) {
        print_map(map);
    }
}

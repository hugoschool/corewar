/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** main.c
*/

#include "corewar.h"

static int print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("./corewar [-dump nbr_cycle] ");
    my_putstr("[[-n prog_number] [-a load_address] prog_name]...\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("-dump nbr_cycle dumps the memory after the nbr_cycle");
    my_putstr(" execution (if the round isn't already over) with the");
    my_putstr(" following format: 32 bytes/line in hexadecimal");
    my_putstr(" (A0BCDEFE1DD3...)\n");
    my_putstr("-n prog_number sets the next program's number. By default,");
    my_putstr(" the first free number in the parameter order\n");
    my_putstr("-a load_address sets the next program's loading address. When");
    my_putstr(" no address is specified, optimize the addresses so that the ");
    my_putstr(" processes are as far away from each other as possible. ");
    my_putstr("The addresses are MEM_SIZE modulo.\n");
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return 84;
    if (my_strcmp(argv[1], "-h") == 0)
        return print_help();
    return 84;
}

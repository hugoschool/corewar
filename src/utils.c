/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** utils.c
*/

#include "corewar.h"

// Little to big endian converter
int ltb_endian(int little)
{
    int bits[4];
    int result;

    bits[0] = (little & 0x000000ff) << 24;
    bits[1] = (little & 0x0000ff00) << 8;
    bits[2] = (little & 0x00ff0000) >> 8;
    bits[3] = (little & 0xff000000) >> 24;
    result = bits[0] | bits[1] | bits[2] | bits[3];
    return result;
}

args_type_t *byte_to_args(uint8_t byte)
{
    args_type_t *args = malloc(sizeof(args_type_t) * (sizeof(uint8_t) * 4));

    args[0] = byte >> 6;
    args[1] = (byte >> 4) & 0b11;
    args[2] = (byte >> 2) & 0b11;
    args[3] = (byte) & 0b11;
    return args;
}

int get_nb_bytes(args_type_t args)
{
    if (args == 1)
        return 1;
    if (args == 2)
        return DIR_SIZE;
    if (args == 3)
        return IND_SIZE;
    return 0;
}

int get_reg_index(unsigned char map_i)
{
    return map_i < REG_NUMBER ? map_i - 1 : 0;
}

int get_inst_size(unsigned char coding_byte)
{
    args_type_t *types = byte_to_args(coding_byte);
    int size = 2;

    for (int i = 0; i < 4; i++) {
        size += get_nb_bytes(types[i]);
    }
    free(types);
    return size;
}

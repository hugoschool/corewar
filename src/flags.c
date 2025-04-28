/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** flags.c
*/

#include "corewar.h"

void free_flags(flags_t *flags)
{
    for (int i = 0; i < MAX_CHAMPIONS_AMT; i++) {
        if (flags->champions[i].fp)
            fclose(flags->champions[i].fp);
    }
    free(flags->champions);
    free(flags);
}

static flags_t *init_flags(void)
{
    flags_t *flags = malloc(sizeof(flags_t));

    if (!flags)
        return NULL;
    flags->dump = 0;
    flags->champions = NULL;
    return flags;
}

static flag_prog_t *init_champions(void)
{
    flag_prog_t *champions = malloc(sizeof(flag_prog_t) * MAX_CHAMPIONS_AMT);

    if (!champions)
        return NULL;
    for (int i = 0; i < MAX_CHAMPIONS_AMT; i++) {
        champions[i].active = false;
        champions[i].load_address = 0;
        champions[i].prog_name = NULL;
        champions[i].prog_number = 0;
        champions[i].fp = NULL;
    }
    return champions;
}

static int handle_prog_number(flag_prog_t *champion, int argc, char **argv,
    int *i)
{
    if (*i < argc && my_strcmp(argv[*i], "-n") == 0) {
        if (*i + 1 < argc && my_getnbr(argv[*i + 1]) > 0) {
            champion->prog_number = my_getnbr(argv[*i + 1]);
            *i += 2;
            return 1;
        } else
            return -1;
    }
    return 0;
}

static int handle_load_address(flag_prog_t *champion, int argc, char **argv,
    int *i)
{
    if (*i < argc && my_strcmp(argv[*i], "-a") == 0) {
        if (*i + 1 < argc && my_getnbr(argv[*i + 1]) > 0) {
            champion->load_address = my_getnbr(argv[*i + 1]);
            *i += 2;
            return 1;
        } else
            return -1;
    }
    return 0;
}

static int handle_prog_name(flag_prog_t *champion, int argc, char **argv,
    int *i)
{
    if (*i >= argc)
        return 0;
    champion->active = true;
    champion->prog_name = argv[*i];
    return 1;
}

static flag_prog_t *parse_champions(int argc, char **argv, int start)
{
    flag_prog_t *champions = init_champions();
    int x = 0;

    if (!champions)
        return NULL;
    for (int i = start; i < argc && x < MAX_CHAMPIONS_AMT; i++) {
        if (handle_prog_number(&champions[x], argc, argv, &i) == -1
            || handle_load_address(&champions[x], argc, argv, &i) == -1
            || handle_prog_name(&champions[x], argc, argv, &i) == -1) {
            free(champions);
            return NULL;
        }
        x++;
    }
    if (x >= MAX_CHAMPIONS_AMT) {
        free(champions);
        return NULL;
    }
    return champions;
}

static int handle_parse_dump(flags_t *flags, int argc, char **argv, int *start)
{
    if (my_strcmp(argv[*start], "-dump") == 0)
        if (*start + 1 < argc && my_getnbr(argv[*start + 1]) > 0) {
            flags->dump = my_getnbr(argv[*start + 1]);
            *start += 2;
            return 1;
        } else
            return -1;
    else
        return 0;
}

static bool verify_champions(flag_prog_t *champions)
{
    int x = 0;

    for (int i = 0; i < MAX_CHAMPIONS_AMT; i++) {
        if ((champions[i].prog_number != 0
            || champions[i].load_address != 0)
            && !champions[i].active)
            return false;
        if (!champions[i].active)
            break;
        champions[i].fp = fopen(champions[i].prog_name, "r");
        if (!champions[i].fp)
            return false;
        x++;
    }
    if (x == 1)
        return false;
    return true;
}

flags_t *parse_flags(int argc, char **argv)
{
    flags_t *flags = init_flags();
    int start = 1;

    if (!flags)
        return NULL;
    if (handle_parse_dump(flags, argc, argv, &start) == -1) {
        free_flags(flags);
        return NULL;
    }
    flags->champions = parse_champions(argc, argv, start);
    if (!flags->champions) {
        free_flags(flags);
        return NULL;
    }
    if (!verify_champions(flags->champions)) {
        free_flags(flags);
        return NULL;
    }
    return flags;
}

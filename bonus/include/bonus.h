/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** bonus.h
*/

#ifndef BONUS_COREWAR_H_
    #define BONUS_COREWAR_H_

    #define FONT_SIZE 11
    #define SCREEN_WIDTH 1920
    #define SCREEN_HIGHT 1080
    #include <stdio.h>
    #include "corewar.h"
    #include "raylib.h"

typedef enum GameScreen { LOGO = 0, GAMEPLAY, ENDING } GameScreen;
extern const Color colors[];
typedef struct {
    unsigned char byte[MEM_SIZE];
    Color color[MEM_SIZE];
    bool is_index[MEM_SIZE];
} map_t;
void dispay_player(champion_t **champs, int cycles);
void display_end(champion_t **champ, int cycles);
int do_vm_ray(flags_t *flags);
void gameloop_ray(map_t *map, flags_t *flags, champion_t **champ);
void display_player_index(champion_t **champ, map_t *map);
#endif

/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** bonus.h
*/

#ifndef BONUS_COREWAR_H_
    #define BONUS_COREWAR_H_

    #define FONT_SIZE 11
    #define INIT_X 5
    #define INIT_Y 1080 / 3
    #define SCREEN_HEIGHT 1080
    #define SCREEN_WIDTH 1920
    #include <stdio.h>
    #include "corewar.h"
    #include "raylib.h"
    #include "../lib/llist/llist.h"

// Menu
typedef enum GameScreen {
    LOGO = 0,
    GAMEPLAY,
    ENDING
} GameScreen;

// Colors
extern const Color colors[];
Color get_champ_color(int nb_player);

// Display
typedef struct {
    unsigned char byte[MEM_SIZE];
    Color color[MEM_SIZE];
    bool is_index[MEM_SIZE];
} map_t;
void display_player(champion_t **champs, int cycles, linked_list_t *list);
void display_end(champion_t **champ, int cycles, Texture2D skid);
void display_player_index(champion_t **champ, map_t *map);

// History
typedef struct {
    char *str;
    int nb_player;
} history_t;
void display_history(linked_list_t *list);

// VM
int do_vm_ray(flags_t *flags);
void gameloop_ray(map_t *map, flags_t *flags, champion_t **champ);
int inst_ray(map_t *map, champion_t *champ, int proc_index, linked_list_t **list);
int sti_ray(map_t *map, champion_t *champ, int proc_index);
int st_ray(map_t *map, champion_t *champ, int proc_index);

#endif

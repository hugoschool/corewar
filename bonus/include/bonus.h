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

// Flags
    #define KEYGEN_SCREEN_WIDTH 600
    #define KEYGEN_SCREEN_HEIGHT 600

    #define KEYGEN_MAX_WIDTH KEYGEN_SCREEN_WIDTH

    #define KEYGEN_TITLE_SCROLLING_TEXT "The Core War"
    #define KEYGEN_TITLE_FONT_SIZE 50
    #define KEYGEN_TITLE_SPEED 2
    #define KEYGEN_CREDITS_SCROLLING_TEXT "Made with <3 by Hugo ARNAL & Esteban HAZANAS"
    #define KEYGEN_CREDITS_FONT_SIZE 20
    #define KEYGEN_CREDITS_SPEED 2
    #define KEYGEN_SCROLLING_OFFSET 4

    #define KEYGEN_FILE_FONT_SIZE 10

    #define KEYGEN_BUTTON_WIDTH 70
    #define KEYGEN_BUTTON_HEIGHT 20
    #define KEYGEN_BUTTON_TEXT "Choose"

    #define KEYGEN_EXIT_BUTTON_TEXT "Exit to launch Corewar :p"

flag_prog_t *init_champions(void);
int get_champions_amount(flags_t *flags);
flags_t *handle_keygen(flags_t *flags);
flags_t *init_flags(void);

void scrolling_text(char *text, int *x, int y, int speed, int font_size, Color color, bool inverse);
int default_scrolling_text_x(char *text, int max_width, int font_size, bool inverse);

// Display
typedef struct {
    unsigned char byte[MEM_SIZE];
    Color color[MEM_SIZE];
    bool is_index[MEM_SIZE];
} map_t;
void display_player(champion_t **champs, int cycles, linked_list_t *list);
void display_end(champion_t **champ, int cycles, Texture2D skid, Music music);
void display_player_index(champion_t **champ, map_t *map);
void display_dead(champion_t **champ);

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

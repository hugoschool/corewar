/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** gameloop.c
*/

#include "bonus.h"
#include "corewar.h"
#include "raylib.h"
#define _GNU_SOURCE

void update_champions_and_cycles(champion_t **champ, int *cycles)
{
    for (int i = 0; champ[i] != NULL; i++) {
        if (!champ[i]->alive)
            champ[i]->dead = true;
        for (int j = 0; j < champ[i]->nb_procs; j++) {
            champ[i]->procs[j].dead = champ[i]->procs[j].alive == true ?
                false : true;
            champ[i]->procs[j].alive = false;
        }
        champ[i]->alive = false;
    }
    *cycles = 0;
}

bool champs_alive(champion_t **champ, GameScreen *screen)
{
    int alive = 0;
    static int nb_last = 0;

    for (int i = 0; champ[i] != NULL; i++) {
        if (!champ[i]->dead) {
            alive++;
            nb_last = champ[i]->nb_player;
        }
    }
    if (alive > 1)
        return true;
    for (int i = 0; champ[i] != NULL; i++) {
        if (champ[i]->nb_player == nb_last) {
            mini_printf("The player %d(%s) has won.\n",
            champ[i]->nb_player, champ[i]->header.prog_name);
        }
    }
    *screen = ENDING;
    return false;
}

void set_alive(champion_t **champs, int player_nb, int *nb_live)
{
    for (int i = 0; champs[i] != NULL; i++) {
        if (!champs[i]->dead && champs[i]->nb_player == player_nb) {
            mini_printf("The player %d(%s) is alive.\n",
            champs[i]->nb_player, champs[i]->header.prog_name);
            champs[i]->alive = true;
            (*nb_live) += 1;
        }
    }
}

void do_instructions(unsigned char map[MEM_SIZE], champion_t **champs,
    int index, int *nb_live)
{
    int nb_player = 0;

    for (int i = 0; i < champs[index]->nb_procs; i++)
        if (!champs[index]->dead) {
            nb_player = instructions(map, champs[index], i);
            set_alive(champs, nb_player, nb_live);
        }
}

bool set_pause(bool pause)
{
    if (IsKeyPressed(KEY_SPACE))
        pause = !pause;
    return pause;
}

bool run_one_cycle(unsigned char map[MEM_SIZE], flags_t *flags, champion_t **champ, int *tot_cycles, GameScreen *screen, bool pause)
{
    static int cycles = 0;
    static int nb_delta = 0;
    static int nb_live = 0;
    char lives[24];
    char nb_cycles[34];

    if (pause == true && *screen != ENDING) {
        if (!champs_alive(champ, screen))
            return true;
        for (int i = 0; champ[i] != NULL; i++)
            do_instructions(map, champ, i, &nb_live);
        print_map_cycle(flags, map, cycles);
        if (nb_live >= NBR_LIVE) {
            nb_delta++;
            nb_live = 0;
        }
        if (cycles >= (CYCLE_TO_DIE - (nb_delta * CYCLE_DELTA)))
            update_champions_and_cycles(champ, &cycles);
        cycles++;
        (*tot_cycles)++;
    }
    if (*screen == GAMEPLAY) {
        sprintf(lives, "Lives: %d / 40", nb_live);
        DrawText(lives, SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3 - 20, 20, RAYWHITE);
        sprintf(nb_cycles, "Cycles: %d / %d", cycles, CYCLE_TO_DIE - (nb_delta * CYCLE_DELTA));
        DrawText(nb_cycles, SCREEN_WIDTH / 1.5, SCREEN_HEIGHT / 3 - 20, 20 , RAYWHITE);
    }
    return false;
}

void display_map(map_t *map, const int screenWidth, champion_t **champ, int cycles)
{
    char buf[3] = "";
    int x = INIT_X;
    int y = INIT_Y;

    display_player(champ, cycles);
    display_player_index(champ, map);
    for (int i = 0; i < MEM_SIZE; i++, x+= 20) {
        if (x >= screenWidth - (INIT_X * 2)) {
            x = INIT_X;
            y += 10;
        }
        if (map->is_index[i]) {
            DrawRectangle(x, y, 11, 11, GRAY);
            map->is_index[i] = false;
        }
        snprintf(buf, 3, "%02X", map->byte[i]);
        DrawText(buf, x, y, FONT_SIZE, map->color[i]);
    }
}

void display_logo(champion_t **champ, Texture2D space)
{
    char pres[COMMENT_LENGTH * 2 + PROG_NAME_LENGTH];
    int y = 0;

    DrawTexture(space, 0, 0, WHITE);
    DrawText("The Core War", SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3, 60, YELLOW);
    for (int i = 0; champ[i] != NULL; i++) {
        sprintf(pres, "Player:%i name:%s comment:%s", champ[i]->nb_player, champ[i]->header.prog_name, champ[i]->header.comment);
        DrawText(pres, SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2 + y, 30, RED);
        y += 40;
    }
    DrawText("Press 'space' to start", 10, 10 , 30, WHITE);
}

void gameloop_ray(map_t *map, flags_t *flags, champion_t **champ)
{
    bool pause = 0;
    GameScreen screen = LOGO;
    int cycles = 0;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Corewar");
    bool ended = false;
    Image space_i = LoadImage("ressources/space.png");
    Texture2D space_t = LoadTextureFromImage(space_i);
    SetTargetFPS(120);

    while (!WindowShouldClose()) {
        pause = set_pause(pause);
        if (pause == 1 && screen != ENDING)
            screen = GAMEPLAY;
        BeginDrawing();
        ClearBackground(BLACK);
        if (screen == LOGO)
            display_logo(champ, space_t);
        if (screen == GAMEPLAY)
            display_map(map, SCREEN_WIDTH, champ, cycles);
        if (screen == ENDING)
            display_end(champ, cycles);
        ended = run_one_cycle(map->byte, flags, champ, &cycles, &screen, pause);
        EndDrawing();
    }
    UnloadImage(space_i);
    UnloadTexture(space_t);
    CloseWindow();
    return;
}

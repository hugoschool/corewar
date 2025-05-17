/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** gameloop.c
*/

#include "../include/bonus.h"
#include "corewar.h"
#include "raylib.h"
#define _GNU_SOURCE

#define INIT_X 5
#define INIT_Y 1080 / 3

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
    for (int i = 0; champ[i] != NULL; i++)
        if (champ[i]->nb_player == nb_last) {
            mini_printf("The player %d(%s) has won.\n",
                champ[i]->nb_player, champ[i]->header.prog_name);
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

void run_one_cycle(unsigned char map[MEM_SIZE], flags_t *flags, champion_t **champ, int *tot_cycles, GameScreen *screen)
{
    static int cycles = 0;
    static int nb_delta = 0;
    static int nb_live = 0;

    if (!champs_alive(champ, screen))
        return;
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

void display_map(unsigned char map[MEM_SIZE], const int screenWidth, champion_t **champ, int cycles)
{
    char buf[3] = "";
    Color text_color = RAYWHITE;
    int x = INIT_X;
    int y = INIT_Y;

    dispay_player(champ, cycles);
    for (int i = 0; i < MEM_SIZE; i++, x+= 20) {
        if (x >= screenWidth - (INIT_X * 2)) {
            x = INIT_X;
            y += 10;
        }
        text_color = RAYWHITE;
        if (map[i] > 0)
            text_color = RED;
        snprintf(buf, 3, "%02X", map[i]);
        DrawText(buf, x, y, FONT_SIZE, text_color);
    }
}

void set_pause(int *pause)
{
    if (IsKeyPressed(KEY_SPACE))
    (*pause)++;
}

void display_logo(champion_t **champ, Texture2D space)
{
    char pres[COMMENT_LENGTH * 2 + PROG_NAME_LENGTH];
    int y = 0;

    DrawTexture(space, 0, 0, WHITE);
    DrawText("The Core War", SCREEN_WIDTH / 3, SCREEN_HIGHT / 3, 60, YELLOW);
    for (int i = 0; champ[i] != NULL; i++) {
        sprintf(pres, "Player:%i name:%s comment:%s", champ[i]->nb_player, champ[i]->header.prog_name, champ[i]->header.comment);
        DrawText(pres, SCREEN_WIDTH / 4, SCREEN_HIGHT / 2 + y, 30, RED);
        y += 40;
    }
    DrawText("Press 'space' to start", 10, 10 , 30, WHITE);
}

void gameloop(unsigned char map[MEM_SIZE], flags_t *flags, champion_t **champ)
{
    int pause = 0;
    GameScreen screen = LOGO;
    int cycles = 0;

    InitWindow(SCREEN_WIDTH, SCREEN_HIGHT, "Corewar");
    SetTargetFPS(120);
    Image space_i = LoadImage("ressources/space.png");
    Texture2D space_t = LoadTextureFromImage(space_i);
    while (!WindowShouldClose()) {
        set_pause(&pause);
        if (pause == 1)
            screen = GAMEPLAY;
        BeginDrawing();
        ClearBackground(BLACK);
        if (screen == LOGO)
            display_logo(champ, space_t);
        if (screen == GAMEPLAY)
            display_map(map, SCREEN_WIDTH, champ, cycles);
        if (screen == ENDING)
            display_end(champ, cycles);
        EndDrawing();
        if (pause % 2 != 0 && screen != ENDING)
            run_one_cycle(map, flags, champ, &cycles, &screen);
    }
    CloseWindow();
    UnloadImage(space_i);
    UnloadTexture(space_t);
    return;
}

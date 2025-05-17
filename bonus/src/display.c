/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** display.c
*/

#include "corewar.h"
#include "../include/bonus.h"
#include "raylib.h"



void dispay_player(champion_t **champs, int cycles)
{
    int disp = 10;
    char proc[100];

    for (int i = 0; champs[i] != NULL; i++) {
        DrawText(champs[i]->header.prog_name, disp, 20, 40, RED);
        DrawText("Live state:", disp, 80, 20, RAYWHITE);
        if (!(champs[i]->alive) && !(champs[i]->dead))
            DrawRectangle(disp + 120, 80, 40, 40, GRAY);
        if (champs[i]->alive && !(champs[i]->dead))
            DrawRectangle(disp + 120, 80, 40, 40, GREEN);
        if (!(champs[i]->alive) && champs[i]->dead)
            DrawRectangle(disp + 120, 80, 40, 40, RED);
        sprintf(proc, "nb of process: %d", champs[i]->nb_procs);
        DrawText(proc, disp, 120, 20, RAYWHITE);
        disp += SCREEN_WIDTH / 4;
    }
    sprintf(proc, "Total Cycles: %d", cycles);
    DrawText(proc, 20, SCREEN_HIGHT / 3 - 20, 20, RAYWHITE);
}

void display_end(champion_t **champ, int cycles)
{
    char winner[PROG_NAME_LENGTH + 40];
    int nb_winner = 0;

    for (int i = 0; champ[i] != 0; i++) {
        if (champ[i]->alive)
            nb_winner = i;
    }
    sprintf(winner, "The Winner is player n°%d(%s)", champ[nb_winner]->nb_player, champ[nb_winner]->header.prog_name);
    DrawText(winner, SCREEN_WIDTH / 3 - 140, SCREEN_HIGHT / 2 - 70, 70, YELLOW);
    sprintf(winner, "Total cycles: %d", cycles);
    DrawText(winner, SCREEN_WIDTH / 3, SCREEN_HIGHT / 1.5, 20, RAYWHITE);
}

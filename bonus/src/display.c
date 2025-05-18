/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** display.c
*/

#include "corewar.h"
#include "bonus.h"
#include "raylib.h"

void display_player(champion_t **champs, int cycles)
{
    int disp = 10;
    char proc[100];

    for (int i = 0; champs[i] != NULL; i++) {
        DrawText(champs[i]->header.prog_name, disp, 20, 40, get_champ_color(champs[i]));
        DrawText("Live state:", disp, 80, 20, RAYWHITE);
        if (!(champs[i]->alive) && !(champs[i]->dead))
            DrawRectangle(disp + 120, 80, 40, 40, GRAY);
        if (champs[i]->alive && !(champs[i]->dead))
            DrawRectangle(disp + 120, 80, 40, 40, GREEN);
        if (!(champs[i]->alive) && champs[i]->dead)
            DrawRectangle(disp + 120, 80, 40, 40, RED);
        sprintf(proc, "nb of process: %d", champs[i]->nb_procs);
        DrawText(TextFormat("nb of process: %d", champs[i]->nb_procs), disp, 120, 20, RAYWHITE);
        disp += SCREEN_WIDTH / 4;
    }
    sprintf(proc, "Total Cycles: %d", cycles);
    DrawText(proc, 20, SCREEN_HEIGHT / 3 - 20, 20, RAYWHITE);
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
    DrawText(TextFormat(winner), SCREEN_WIDTH / 3 - 140, SCREEN_HEIGHT / 2 - 70, 70, YELLOW);
    DrawText(TextFormat("Total cycles: %d", cycles), SCREEN_WIDTH / 3, SCREEN_HEIGHT / 1.5, 20, RAYWHITE);
}

void display_player_index(champion_t **champ, map_t *map)
{
    for (int i = 0; champ[i] != NULL; i++) {
        for (int j = 0; j < champ[i]->nb_procs; j++) {
            if (!champ[i]->dead && !champ[i]->procs[j].dead)
                map->is_index[champ[i]->procs[i].index] = true;
        }
    }
}

/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** display.c
*/

#include "corewar.h"
#include "bonus.h"
#include "raylib.h"
#include "llist.h"

void display_player(champion_t **champs, int cycles, linked_list_t *list)
{
    int disp = 10;
    char proc[100];
    Rectangle rect = {disp, 150, 200, 180};
    linked_list_t *tmp = list;
    int y = 150;
    history_t *data = NULL;

    for (int i = 0; champs[i] != NULL; i++) {
        y = 150;
        tmp = list;
        DrawText(champs[i]->header.prog_name, disp, 20, 40, get_champ_color(champs[i]->nb_player));
        DrawText("Live state:", disp, 80, 20, RAYWHITE);
        if (!(champs[i]->alive) && !(champs[i]->dead))
            DrawRectangle(disp + 120, 80, 40, 40, GRAY);
        if (champs[i]->alive && !(champs[i]->dead))
            DrawRectangle(disp + 120, 80, 40, 40, GREEN);
        if (!(champs[i]->alive) && champs[i]->dead)
            DrawRectangle(disp + 120, 80, 40, 40, RED);
        sprintf(proc, "nb of process: %d", champs[i]->nb_procs);
        DrawText(TextFormat("nb of process: %d", champs[i]->nb_procs), disp, 120, 20, RAYWHITE);
        rect.x = disp;
        DrawRectangleRounded(rect, 0.05, 0.05, WHITE);
        while (tmp != NULL && y < 200 + 130) {
            data = tmp->data;
            if (champs[i]->nb_player == data->nb_player) {
                DrawText(data->str, disp + 10, y, 20, get_champ_color(data->nb_player));
                y += 20;
            }
            tmp = tmp->next;
        }
        disp += SCREEN_WIDTH / 4;
    }
    sprintf(proc, "Total Cycles: %d", cycles);
    DrawText(proc, 20, SCREEN_HEIGHT / 3 - 20, 20, RAYWHITE);
}

void display_end(champion_t **champ, int cycles, Texture2D skid)
{
    char winner[PROG_NAME_LENGTH + 40];
    int nb_winner = 0;
    static float scrolling = 0.0f;

    scrolling -= 0.5f;
    if (scrolling <= -skid.width*2)
        scrolling = 0;
    for (int i = 0; champ[i] != 0; i++) {
        if (champ[i]->alive)
            nb_winner = i;
    }
    DrawTextureEx(skid, (Vector2){scrolling, 20}, 0.0f, 2.0f, WHITE);
    DrawTextureEx(skid, (Vector2){skid.width*2 + scrolling, 20}, 0.0f, 2.0f, WHITE);
    sprintf(winner, "The Winner is player n°%d(%s)", champ[nb_winner]->nb_player, champ[nb_winner]->header.prog_name);
    DrawText(TextFormat(winner), SCREEN_WIDTH / 3 - 140, SCREEN_HEIGHT / 2 - 70, 70, YELLOW);
    DrawText(TextFormat("Total cycles: %d", cycles), SCREEN_WIDTH / 3, SCREEN_HEIGHT / 1.5, 20, RAYWHITE);
}

void display_player_index(champion_t **champ, map_t *map)
{
    for (int i = 0; champ[i] != NULL; i++) {
        for (int j = 0; j < champ[i]->nb_procs; j++) {
            if (!champ[i]->dead && !champ[i]->procs[j].dead)
                map->is_index[(champ[i]->procs[j].index) % MEM_SIZE] = true;
        }
    }
}

void display_history(linked_list_t *list)
{
    static bool history = false;
    int i = SCREEN_WIDTH / 1.25;
    int y = 90;
    linked_list_t *tmp = list;
    Rectangle rect = {SCREEN_WIDTH / 1.25, 80, SCREEN_WIDTH / 6, 900};
    history_t *data = NULL;

    if (IsKeyPressed(KEY_H))
        history = !history;
    if (history) {
        DrawRectangleRounded(rect, 0.05, 0.05, WHITE);
        while (tmp != NULL && y < 950) {
            data = tmp->data;
            DrawText(data->str, i + 10, y, 40, get_champ_color(data->nb_player));
            y += 42;
            tmp = tmp->next;
        }
    }
}

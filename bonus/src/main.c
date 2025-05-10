/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** main.c
*/

#include "raylib.h"

int main(void)
{
    const int screenWidth = 500;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "Corewar");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("hello world :3", screenWidth / 2, screenHeight / 2, 20, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

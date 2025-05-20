/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** keygen.c
*/

#include "bonus.h"
#include "corewar.h"
#include "raylib.h"
#include <linux/limits.h>

// Yes we're disabling warnings because raygui & gui_window_file_dialog
// aren't checking some things uhhhhh but oh well
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wsign-compare"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#undef RAYGUI_IMPLEMENTATION

#define GUI_WINDOW_FILE_DIALOG_IMPLEMENTATION
#include "gui_window_file_dialog.h"
#pragma GCC diagnostic pop
#pragma GCC diagnostic pop

void set_champion(flags_t *flags, int i, char *text)
{
    flags->champions[i].active = true;
    flags->champions[i].prog_name = strdup(text);
}

void create_button(GuiWindowFileDialogState *file_dialog, int *selected_gui, char file_name[PATH_MAX], int i)
{
    int height = KEYGEN_SCREEN_HEIGHT / 2 + (KEYGEN_BUTTON_HEIGHT + 10) * i;

    if (GuiButton((Rectangle){
        KEYGEN_SCREEN_WIDTH - KEYGEN_BUTTON_WIDTH - 10,
        height,
        KEYGEN_BUTTON_WIDTH,
        KEYGEN_BUTTON_HEIGHT
    }, GuiIconText(ICON_FILE, KEYGEN_BUTTON_TEXT))) {
        *selected_gui = i;
        file_dialog->windowActive = true;
    }
    DrawText(TextFormat("FILE: %s", strlen(file_name) > 0 ? file_name : "None"), 10, height + (KEYGEN_FILE_FONT_SIZE / 2), KEYGEN_FILE_FONT_SIZE, GREEN);
}

flags_t *handle_keygen(flags_t *flags)
{
    flags->champions = init_champions();

    InitWindow(KEYGEN_SCREEN_WIDTH, KEYGEN_SCREEN_HEIGHT, "Core War Keygen --- TEAM FREAKY");
    GuiWindowFileDialogState file_dialog = InitGuiWindowFileDialog(GetWorkingDirectory());
    char file_name[MAX_CHAMPIONS_AMT][PATH_MAX] = {0};
    int selected_gui = -1;

    SetTargetFPS(60);

    int title_x = default_scrolling_text_x(KEYGEN_TITLE_SCROLLING_TEXT, KEYGEN_MAX_WIDTH, KEYGEN_TITLE_FONT_SIZE, false);
    int credits_x = default_scrolling_text_x(KEYGEN_CREDITS_SCROLLING_TEXT, KEYGEN_MAX_WIDTH, KEYGEN_CREDITS_FONT_SIZE, true);

    GuiSetStyle(DEFAULT, BACKGROUND_COLOR, 0x00000000);
    while (!WindowShouldClose()) {
        if (file_dialog.SelectFilePressed) {
            strncpy(file_name[selected_gui], TextFormat("%s" PATH_SEPERATOR "%s", file_dialog.dirPathText, file_dialog.fileNameText), PATH_MAX);
            set_champion(flags, selected_gui, file_name[selected_gui]);
            file_dialog.SelectFilePressed = false;
        }
        BeginDrawing();
        ClearBackground(BLACK);

        scrolling_text(KEYGEN_TITLE_SCROLLING_TEXT, &title_x, 20, KEYGEN_TITLE_SPEED, KEYGEN_TITLE_FONT_SIZE, GREEN, false);
        scrolling_text(KEYGEN_CREDITS_SCROLLING_TEXT, &credits_x, 60, KEYGEN_CREDITS_SPEED, KEYGEN_CREDITS_FONT_SIZE, GREEN, true);

        if (file_dialog.windowActive)
            GuiLock();

        for (int i = 0; i < MAX_CHAMPIONS_AMT; i++) {
            create_button(&file_dialog, &selected_gui, file_name[i], i);
        }
        if (get_champions_amount(flags) >= 2) {
            DrawText(KEYGEN_EXIT_BUTTON_TEXT, 0 + MeasureText(KEYGEN_EXIT_BUTTON_TEXT, 20), KEYGEN_SCREEN_HEIGHT - 20, 20, GREEN);
        }
        GuiUnlock();
        GuiWindowFileDialog(&file_dialog);
        EndDrawing();
    }
    CloseWindow();
    return flags;
}

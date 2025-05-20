/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** scrolling_text.c
*/

#include "bonus.h"
#include "raylib.h"
#include <string.h>

int default_scrolling_text_x(char *text, int max_width, int font_size, bool inverse)
{
    if (!inverse)
        return 0 - ((strlen(text) - KEYGEN_SCROLLING_OFFSET) * font_size);
    else
        return max_width + ((strlen(text) - KEYGEN_SCROLLING_OFFSET) * font_size);
}

void scrolling_text(char *text, int *x, int y, int speed, int font_size, Color color, bool inverse)
{
    int max = default_scrolling_text_x(text, KEYGEN_MAX_WIDTH, font_size, !inverse);

    if ((*x) != max)
        (*x) += !inverse ? speed : -speed;
    else
        (*x) = default_scrolling_text_x(text, KEYGEN_MAX_WIDTH, font_size, inverse);
    DrawText(text, *x, y, font_size, color);
}

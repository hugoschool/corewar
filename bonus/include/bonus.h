/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** bonus.h
*/

#ifndef BONUS_COREWAR_H_
    #define BONUS_COREWAR_H_

    #define FONT_SIZE 11
    #define SCREEN_WIDTH 1920
    #define SCREEN_HIGHT 1080
    #include <stdio.h>
    #include "corewar.h"

typedef enum GameScreen { LOGO = 0, GAMEPLAY, ENDING } GameScreen;
void dispay_player(champion_t **champs, int cycles);
void display_end(champion_t **champ, int cycles);
#endif

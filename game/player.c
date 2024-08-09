#include "player.h"
#include "raylib.h"
#include <stdio.h>
#include <math.h>

void InitPlayer(Player* player, int x, int y, int speedX, int speedY, int LastInput) {
    player->x = x;
    player->y = y;
    player->speedX = speedX;
    player->speedY = speedY;
    player->LastInput = LastInput;
}

void UpdatePlayer(Player* player) {
    if (IsKeyDown(KEY_W)) {
        player->y -= player->speedY;
        player->LastInput = 1;
        printf("W is pressed\n");
        printf("PlayerY: %d\n", player->y);
        printf("Player LastInput: %d\n", player->LastInput);
    }
    if (IsKeyDown(KEY_S)) {
        player->y += player->speedY;
        player->LastInput = 2;
        printf("S is pressed\n");
        printf("PlayerY: %d\n", player->y);
        printf("PlayerLastInput: %d\n", player->LastInput);
    }
    if (IsKeyDown(KEY_A)) {
        player->x -= player->speedX;
        player->LastInput = 3;
        printf("A is pressed\n");
        printf("PlayerX: %d\n", player->x);
        printf("PlayerLastInput: %d\n", player->LastInput);
    }
    if (IsKeyDown(KEY_D)) {
        player->x += player->speedX;
        player->LastInput = 4;
        printf("D is pressed\n");
        printf("PlayerX: %d\n", player->x);
        printf("PlayerLastInput: %d\n", player->LastInput);
    }
}

void DrawPlayer(Player* player) {
    DrawCircle(player->x, player->y, 15, VIOLET);
}
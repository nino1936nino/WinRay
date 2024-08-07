#include "player.h"
#include "raylib.h"
#include <stdio.h>
#include <math.h>

void InitPlayer(Player* player, int x, int y, int speedX, int speedY) {
    player->x = x;
    player->y = y;
    player->speedX = speedX;
    player->speedY = speedY;
}

void UpdatePlayer(Player* player) {
    if (IsKeyDown(KEY_W)) {
        player->y -= player->speedY;
        printf("W is pressed\n");
        printf("PlayerY: %d\n", player->y);
    }
    if (IsKeyDown(KEY_S)) {
        player->y += player->speedY;
        printf("S is pressed\n");
        printf("PlayerY: %d\n", player->y);
    }
    if (IsKeyDown(KEY_A)) {
        player->x -= player->speedX;
        printf("A is pressed\n");
        printf("PlayerX: %d\n", player->x);
    }
    if (IsKeyDown(KEY_D)) {
        player->x += player->speedX;
        printf("D is pressed\n");
        printf("PlayerX: %d\n", player->x);
    }
}

void DrawPlayer(Player* player) {
    DrawCircle(player->x, player->y, 15, VIOLET);
}
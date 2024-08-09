#pragma once

typedef struct Player {
    int x;
    int y;
    int speedX;
    int speedY;
    int LastInput;
} Player;

void InitPlayer(Player* player, int x, int y, int speedX, int speedY);
void UpdatePlayer(Player* player);
void DrawPlayer(Player* player);

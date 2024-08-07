#pragma once

#include "raylib.h"
#include "player.h"
typedef struct Bullet {
	int x;
	int y;
	int speedX;
	int speedY;
	float angle;
	int sizeX;
	int sizeY;
	Vector2 size;
	Vector2 origin;
}Bullet;

void SpawnBullet(Bullet* bullet, Player* player, int x, int y, int speedX, int speedY, float angle, int sizeX, int sizeY);

// Function to update a Bullet instance
void UpdateBullet(Bullet* bullet, int mouseX, int mouseY, Player* player);

// Function to draw a Bullet instance
void DrawBullet(Bullet* bullet);
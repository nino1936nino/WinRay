#pragma once

#include "raylib.h"
#include "player.h"
typedef struct Bullet {
	float x;
	float y;
	float speedX;
	float speedY;
	float sizeX;
	float sizeY;
	Vector2 size;
	Vector2 origin;
	Vector2 position;
	bool active;
}Bullet;

void InitBullet(Bullet* bullet, Player* player, int x, int y, int speedX, int speedY,  bool active);

// Function to update a Bullet instance
void FireBullet(Player* player, Bullet* bullet);

void UpdateBullet(Bullet* bullet, int screenWidth, int screenHeigth);

// Function to draw a Bullet instance
//void DrawBullet(Bullet* bullet);
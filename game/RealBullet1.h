#pragma once

#include "raylib.h"
#include "player.h"
#include <stdbool.h>
typedef struct BulletFR {
	int x;
	int y;
	int speedX;
	int speedY;
	float angle;
	int sizeX;
	int sizeY;
	Vector2 size;
	Vector2 origin;
	bool draw;
	int Active;

}BulletFR;

void InitBulletFR(Bullet* bullet, BulletFR* bulletFR, int x, int y, int speedX, int speedY, float angle, int sizeX, int sizeY, bool draw, int Active);

void UpdateBulletFR(Bullet* bullet, int MouseX, int MouseY, BulletFR* bulletFR);

void DrawBulletFR(BulletFR* bulletFR);

bool isBulletFiredRF(BulletFR* bulletFR);

bool BulletFRCanBeDrawn(BulletFR* bulletFR);
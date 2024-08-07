#include "raylib.h"
#include "player.h"
#include "Bullet.h"
#include "RealBullet1.h"
#include <stdbool.h>
#include <stdio.h>
#include <math.h>


void InitBulletFR(Bullet* bullet, BulletFR* bulletFR, int x, int y, int speedX, int speedY, float angle, int sizeX, int sizeY ,bool draw, int Active) {
    bulletFR->x = bullet->x;
    bulletFR->y = bullet->y;
    bulletFR->speedX = speedX;
    bulletFR->speedY = speedY;
    bulletFR->angle = bullet->angle;
    bulletFR->sizeX = sizeX;
    bulletFR->sizeY = sizeY;
    bulletFR->size.x = sizeX;
    bulletFR->size.y = sizeY;
    bulletFR->origin.x = sizeX / 2;
    bulletFR->origin.y = sizeY / 2;
    bulletFR->draw = draw;
    bulletFR->Active = Active;
}


bool isBulletFiredRF(BulletFR* bulletFR){
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        bulletFR->Active = 1;
        return true;
    }
    else {
        return false;
    }
}

bool BulletFRCanBeDrawn(BulletFR* bulletFR) {
    if ( bulletFR->draw == true) {
        DrawBulletFR(&bulletFR);
    }
}

void UpdateBulletFR(Bullet* bullet, int MouseX, int MouseY, BulletFR* bulletFR) {
    float dirX = MouseX - bullet->x;
    float dirY = MouseY - bullet->y;
    float length = sqrtf(dirX * dirX + dirY * dirY);

    if (length != 0) {
        dirX /= length;
        dirY /= length;
    }


    bulletFR->x += (int)(bulletFR->speedX );
    bulletFR->y += (int)(bulletFR->speedY );
    


    printf("%d\n", bulletFR->x);
    printf("%d\n", bulletFR->y);
    return bulletFR->draw = true;
}
void DrawBulletFR(BulletFR* bulletFR) {
    Rectangle rect = { bulletFR->x, bulletFR->y, bulletFR->size.x, bulletFR->size.y };
    Vector2 origin = { bulletFR->origin.x ,bulletFR->origin.y };
    DrawRectanglePro(rect, origin, bulletFR->angle * (180.0f / PI), GREEN);  // angle converted to degrees
}
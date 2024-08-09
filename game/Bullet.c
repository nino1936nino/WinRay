#include <math.h>
#include <stdio.h>
#include  "raylib.h"
#include "Bullet.h"
#include "player.h"



void InitBullet(Bullet* bullet, Player* player, float x, float y, float speedX, float speedY, bool active) {
    bullet->x = x;
    bullet->y = y;
    bullet->speedX = speedX;
    bullet->speedY = speedY;
    bullet->active = active;
}

void FireBullet(Player* player, Bullet* bullet) {
        bullet->x = player->x;
        bullet->y = player->y;
        bullet->active = true;
        /*
        switch (player->LastInput)
        {
        case 1: 
            bullet->speedX = 0;
            bullet->speedY = -bullet->speedY; 
            printf("LEFT\n");
            printf("X: %f  Y: %f, SPEEDX: %f \n", bullet->x, bullet->y, bullet->speedY);

            break;
        case 2: 
            bullet->speedX = 0;
            bullet->speedY = bullet->speedY; 
            printf("LEFT\n");
            printf("X: %f  Y: %f, SPEEDX: %f \n", bullet->x, bullet->y, bullet->speedY);
            break;
        case 3:
            bullet->speedX = -bullet->speedX; 
            bullet->speedY = 0;
            printf("LEFT\n");
            printf("X: %f  Y: %f, SPEEDX: %f \n", bullet->x, bullet->y, bullet->speedX);
            break;
        case 4: 
            bullet->speedX = bullet->speedX; 
            bullet->speedY = 0;
            printf("LEFT\n");
            printf("X: %f  Y: %f, SPEEDX: %f \n", bullet->x, bullet->y, bullet->speedX);
            break;
        }*/
}         


/*
void UpdateBullet(Bullet* bullet, Player* player) {

}
*/
void UpdateBullet(Bullet* bullet, int screenWidth, int screenHeigth) {
    if (bullet->active) {
        bullet->x += bullet->speedX * GetFrameTime();
        bullet->y += bullet->speedY * GetFrameTime();

        // Optional: Check if the bullet is out of bounds and deactivate it
        /*
        if (bullet->x < 0 || bullet->x > screenWidth ||
            bullet->y < 0 || bullet->y > screenHeigth) {
            bullet->active = false; // Deactivate the bullet
        }
        */
    }
}





/*
void DrawBullet(Bullet* bullet) {
    DrawCircle(bullet->x, bullet->y, 10, BLUE);
}
*/


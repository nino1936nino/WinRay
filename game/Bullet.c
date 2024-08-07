#include <math.h>
#include <stdio.h>
#include  "raylib.h"
#include "Bullet.h"
#include "player.h"



void SpawnBullet(Bullet* bullet, Player* player, int x, int y, int speedX, int speedY, float angle, int sizeX, int sizeY) {
    bullet->x = x;
    bullet->y = y;
    bullet->speedX = speedX;
    bullet->speedY = speedY;
    bullet->angle = angle;
    bullet->sizeX = sizeX;
    bullet->sizeY = sizeY;
    bullet->size.x = sizeX;
    bullet->size.y = sizeY;
    bullet->origin.x = sizeX/2;
    bullet->origin.y = sizeY/2;

}
void UpdateBullet(Bullet* bullet, int MouseX, int MouseY, Player* player) {
    /*bullet->angle = Vector2Normalize(Vector2Subtract(MouseX, player));
        //atan2(bullet->y -= MouseY, bullet->x -= MouseX);
    printf("%f\n",bullet->angle);
    printf("%d\n", bullet->x);
    printf("%d\n", bullet->y);
    printf("%d\n", bullet->sizeX);
    printf("%d\n", bullet->sizeY);


        Vector2 mousePos = { (float)MouseX, (float)MouseY };
    Vector2 bulletPos = { (float)bullet->x, (float)bullet->y };
    bullet->angle = Vector2Subtract(Vector2Normalize(mousePos, bulletPos));
*/

    // = atan2f(direction);
    float dirX = MouseX - bullet->x;
    float dirY = MouseY - bullet->y;
    float length = sqrtf(dirX * dirX + dirY * dirY);

    // Normalize direction
    if (length != 0) {
        dirX /= length;
        dirY /= length;
    }

    // Update bullet position
    bullet->x += (int)(bullet->speedX * dirX);
    bullet->y += (int)(bullet->speedY * dirY);

    // Calculate angle in radians
    bullet->angle = atan2f(dirY, dirX);

    //printf("Angle: %f\n", bullet->angle);
    //printf("Position: (%d, %d)\n", bullet->x, bullet->y);
    //printf("Size: (%d, %d)\n", bullet->sizeX, bullet->sizeY);


}
void DrawBullet(Bullet* bullet) {
    Rectangle rect = { bullet->x, bullet->y, bullet->size.x, bullet->size.y };
    Vector2 origin = { bullet->origin.x ,bullet->origin.y };
    DrawRectanglePro(rect, origin, bullet->angle * (180.0f / PI), RED);  // angle converted to degrees
    
}
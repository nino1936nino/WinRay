#include "raylib.h"
#include "player.h"
#include "Bullet.h"
#include "shop.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define BULLET_SPEED 300
#define BULLET_RADIUS 10


//------------------------------------------------------------------------------------
//https://github.com/raysan5/raylib/blob/master/src/raylib.h#L983
// DrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color);
//------------------------------------------------------------------------------------
int main(void)
{

    int screenWidth = 800;
    int screenHeight = 450;
    int PlayerSpeedX = 5;
    int PlayerSpeedY = 5;
    int PlayerPosX = 200;
    int PlayerPosY = 200;
    float BulletPosX = 0;
    float BulletPosY = 0;
    int LastInput = 0;
    float BulletSpeedX = 100;
    float BulletSpeedY = 100;
    SpawnShop();
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Try window resizing");

    SetTargetFPS(60);
    Player player;
    InitPlayer(&player, PlayerPosX, PlayerPosY, 15, 15,LastInput);
    //Bullet bullet;
    //InitBullet(&bullet, &player, BulletPosX, BulletPosY, BulletSpeedX, BulletSpeedY, 10, 20, false);

    Bullet* bullets = NULL; 
    int bulletCount = 0;

    // Main game loop
    while (!WindowShouldClose())    
    {
        UpdatePlayer(&player);
        int MouseX = GetMouseX();
        int MouseY = GetMouseY();

        
        BulletSpeedX = 0;
        BulletSpeedY = 0;
        
        //if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            BulletPosX = player.x;
            BulletPosY = player.y;
            //bullet.active = true;
            bulletCount++;
            bullets = (Bullet*)realloc(bullets, bulletCount * sizeof(Bullet));
            switch (player.LastInput)
            {
            case 1:
                BulletSpeedY = -BULLET_SPEED;
                printf("LEFT\n");
                printf("X: %f  Y: %f, SPEEDY: %f \n", BulletPosX, BulletPosY, BulletSpeedY);

                break;
            case 2:
                BulletSpeedY = BULLET_SPEED;
                printf("LEFT\n");
                printf("X: %f  Y: %f, SPEEDY: %f \n", BulletPosX, BulletPosY, BulletSpeedY);
                break;
            case 3:
                BulletSpeedX = -BULLET_SPEED;
                printf("LEFT\n");
                printf("X: %f  Y: %f, SPEEDX: %f \n", BulletPosX, BulletPosY, BulletSpeedX);
                break;
            case 4:
                BulletSpeedX = BULLET_SPEED;
                printf("LEFT\n");
                printf("X: %f  Y: %f, SPEEDX: %f \n", BulletPosX, BulletPosY, BulletSpeedX);
                break;
            }

            InitBullet(bullets[bulletCount - 1], &player, BulletPosX, BulletPosY, BulletSpeedX, BulletSpeedY, true);


        //}
        
        if (IsKeyPressed(KEY_P)) {
            screenHeight += 100;
            SetWindowSize(screenWidth, screenHeight);

        }
        for (int i = 0; i < bulletCount; i++) {
            if (bullets[i].active) {
                bullets[i].x += bullets[i].speedX * GetFrameTime();
                bullets[i].y += bullets[i].speedY * GetFrameTime();
            }
        }



        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawPlayer(&player);
        for (int i = 0; i < bulletCount; i++) {
            if (bullets[i].active) {
                DrawCircle(bullets[i].x, bullets[i].y, 10, BLUE);
            }
        }

        DrawText("WindowKill CloneTest", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    free(bullets);

    CloseWindow();        
    //--------------------------------------------------------------------------------------

    return 0;
}



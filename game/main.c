#include "raylib.h"
#include "player.h"
#include "Bullet.h"
#include "RealBullet1.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

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
    int BulletPosX = 0;
    int BulletPosY = 0;
    int BulletPosXFR = BulletPosX;
    int BulletPosYFR = BulletPosY;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow( screenWidth , screenHeight, "Try window resizing");
    
    SetTargetFPS(60);               
    Player player;
    InitPlayer(&player, PlayerPosX, PlayerPosY, PlayerSpeedX, PlayerSpeedY);
    Bullet bullet;
    SpawnBullet(&bullet, &player, BulletPosX, BulletPosY, 5, 5, 45.0f, 10, 20);
    BulletFR* bulletFR; 
    InitBulletFR(&bullet, &bulletFR, BulletPosXFR, BulletPosYFR, 15, 15, 45.0f, 15, 30, false, 0);
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //screenWidth = GetScreenWidth();
        //screenHeight = GetScreenHeight();

        int MouseX = GetMouseX();
        int MouseY = GetMouseY();

        
        UpdatePlayer(&player);
        UpdateBullet(&bullet, MouseX, MouseY, &player);
        if (IsKeyPressed(KEY_P)) {
            screenHeight += 100;
            SetWindowSize(screenWidth, screenHeight);

        }
        if (isBulletFiredRF(&bulletFR)) {
            UpdateBulletFR(&bullet, MouseX, MouseY, &bulletFR);
        }

        



        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawPlayer(&player);
        DrawBullet(&bullet);
        if (BulletFRCanBeDrawn(&bulletFR)) {
            DrawBulletFR(&bulletFR);
            //UpdateBulletFR(&bullet, MouseX, MouseY, &bulletFR);
        }
        
        DrawText("WindowKill CloneTest", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }


    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

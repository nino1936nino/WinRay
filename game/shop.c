
#include "raylib.h"
#include "shop.h"

void InitShop() {

}



void SpawnShop() {


    const int screenWidth = 200;
    const int screenHeight = 150;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("buy", 50, 50, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
}

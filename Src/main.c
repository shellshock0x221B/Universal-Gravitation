#include <raylib.h>
#include "elements.h"

int WindowHeight = 800;
int windowWidth = 1200;

int main(void) {
    InitWindow(windowWidth, WindowHeight, "Newton's Gravity Simulation - With Lines");
    SetTargetFPS(60);

    CreatePlants();
    createSat();

    while (!WindowShouldClose()) {
        UpdatePhysics();

        BeginDrawing();
        ClearBackground(BLACK);

        DrawPlants(); 

    EndDrawing();
    }

    CloseWindow();
    return 0;
}

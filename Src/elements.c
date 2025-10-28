#include "elements.h"
#include <math.h>
#include <raylib.h>

Plants plant[Plants_Num];
Plants Sat[Plants_Num];

void CreatePlants() {
    for (int i = 0; i < Plants_Num; i++) {
        plant[i].radius = 80;
        plant[i].color = WHITE;
        plant[i].pos = (Vector2){windowWidth / 2, WindowHeight / 2};
        plant[i].mass = 200000;
        plant[i].vel = (Vector2){0, 0};
    }
}

void createSat() {
    for (int i = 0; i < Plants_Num; i++) {
        Sat[i].radius = 40;
        Sat[i].color = RED;
        Sat[i].pos = (Vector2){windowWidth / 2, WindowHeight - 100};
        Sat[i].mass = 2000;
        Sat[i].vel = (Vector2){2, 0}; 
    }
}

Vector2 Calcgrv(Plants a, Plants b) {
    Vector2 dir = {b.pos.x - a.pos.x, b.pos.y - a.pos.y};
    float dist = sqrtf(dir.x * dir.x + dir.y * dir.y);
    if (dist < 10.0f) dist = 10.0f;

    float force = G * (a.mass * b.mass) / (dist * dist);
    dir.x /= dist;
    dir.y /= dist;
    dir.x *= force;
    dir.y *= force;

    return dir;
}

void UpdatePhysics() {
    for (int i = 0; i < Plants_Num; i++) {
        Vector2 force = Calcgrv(Sat[i], plant[i]);
        Vector2 acc = {force.x / Sat[i].mass, force.y / Sat[i].mass};
        Sat[i].vel.x += acc.x;
        Sat[i].vel.y += acc.y;
        Sat[i].pos.x += Sat[i].vel.x;
        Sat[i].pos.y += Sat[i].vel.y;
    }
}

void DrawPlants() {
    for (int i = 0; i < Plants_Num; i++) {
        DrawCircleV(plant[i].pos, plant[i].radius, plant[i].color);
        DrawCircleV(Sat[i].pos, Sat[i].radius, Sat[i].color);
    }
}

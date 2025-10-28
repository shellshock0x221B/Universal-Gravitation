#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <raylib.h>

#define G 6.674e-3f   
#define Plants_Num 1  
extern int WindowHeight;
extern int windowWidth;

typedef struct {
    float mass;    
    float radius;
    Color color;   
    Vector2 pos;     
    Vector2 vel;      
} Plants;

extern Plants plant[Plants_Num];
extern Plants Sat[Plants_Num];


void CreatePlants(void);
void createSat(void);
void DrawPlants(void);
void UpdatePhysics(void);
Vector2 Calcgrv(Plants a, Plants b);

#endif // ELEMENTS_H

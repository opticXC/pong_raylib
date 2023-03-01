#pragma once


#include "raylib.h"


class Ball{   
    private:
        
    public:
        float radius;
        Vector2 position;
        Vector2 speed;

    void draw();

Ball(Vector2 position, float radius);
~Ball();
};


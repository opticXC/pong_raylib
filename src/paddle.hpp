#pragma once

#include "raylib.h"


class Paddle{
    private:
        

    public:
        Vector2 position;
        int length;
    
    void draw();

Paddle(Vector2 position , int length);
~Paddle();
};
#include "ball.hpp"


Ball::Ball(Vector2 position, float radius)
{
    this->radius = radius;
    this->position = { (float)GetScreenWidth()/2 , (float)GetScreenHeight()/2};
}

Ball::~Ball()
{
    delete &this->radius;
}

void Ball::draw(){
    DrawCircleV(position, radius, WHITE);
}

#include "paddle.hpp"


Paddle::Paddle(Vector2 position, int length){
    this->length = length;
    this->position = position;
}

Paddle::~Paddle(){
    delete &this->position;

}

void Paddle::draw(){
    DrawRectangleV( position , {10, (float)length}, WHITE);
} 
#pragma once

#include <raylib.h>
#include <iostream>
#include <string>
#include <sstream>

#include <raymath.h>

#include "input.hpp"
#include "paddle.hpp"
#include "ball.hpp"




/// @brief test collision and run 
/// @param player 
/// @param r_paddle 
/// @param ball 
void _collision(Paddle* player, Paddle* r_paddle, Ball* ball);

/// @brief move right paddle relative to the ball
/// @param paddle 
/// @param ball 
void move_right(Paddle* paddle, Ball* ball, float movespeed);
#pragma once

#include <raylib.h>
#include <iostream>
#include <string>
#include <sstream>

#include <raymath.h>

#include "input.hpp"
#include "paddle.hpp"
#include "ball.hpp"




/// @brief collison check and related methods to run
void _collision(Paddle* player, Paddle* r_paddle, Ball* ball);
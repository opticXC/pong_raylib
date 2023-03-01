#include "input.hpp"


float GetHorizontalAxis(){
    if (IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT)) return -1;
    if (IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT) ) return 1;
    
    return 0;
}

float GetVerticalAxis(){
    if (IsKeyDown(KEY_W) or IsKeyDown(KEY_UP) ) return -1;
    if (IsKeyDown(KEY_S) or IsKeyDown(KEY_DOWN) ) return 1;
    
    return 0;
}



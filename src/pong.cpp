#include "pong.hpp"


int main(){
    int screenWidth = 600;
    int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "title");
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);


    float moveSpeed =  (float) screenHeight/1.5;
    float ballSpeed = (float) screenWidth/1.2;

    Paddle* player = new Paddle( (Vector2){10, (float) screenHeight/2} , screenHeight/4);
    Paddle* r_paddle = new Paddle( (Vector2){ (float) screenWidth -20, (float) screenHeight/2} , screenHeight/4);
    player->position.y -= player->length/2;
    r_paddle->position.y -= r_paddle->length/2;

    
    int score_1 = 0;    int score_2 = 0;

    Ball* ball = new Ball(Vector2{ (float) screenWidth/2, (float) screenHeight/2}, (float) screenHeight/125);
    ball->speed = { (float) GetRandomValue(-ballSpeed,ballSpeed) , (float) GetRandomValue(-ballSpeed,ballSpeed) };

    Color defaultColor = (Color){100,100,100,255 };

    float DeltaTime;
    while (!WindowShouldClose())
    {   DeltaTime = GetFrameTime();
        screenHeight = GetScreenHeight();
        screenWidth = GetScreenWidth();

        player->position.y = Clamp(player->position.y + moveSpeed * GetVerticalAxis() * DeltaTime, 0, screenHeight - player->length );
        ball->position.x += ball->speed.x * DeltaTime;
        ball->position.y += ball->speed.y * DeltaTime;
        _collision(player,r_paddle,ball);


        if (ball->position.x <= 0) {
            score_2 ++;
            ball->position = Vector2 { (float) screenWidth/2 , (float) screenHeight/2};
            ball->speed = { (float) GetRandomValue(-ballSpeed,ballSpeed) , (float) GetRandomValue(-ballSpeed,ballSpeed) };
        }else if (ball->position.x >=screenWidth){
            score_1 ++;
            ball->position = Vector2{ (float) screenWidth/2 , (float) screenHeight/2};
            ball->speed = { (float) GetRandomValue(-ballSpeed,ballSpeed) , (float) GetRandomValue(-ballSpeed,ballSpeed) };
        }


        BeginDrawing();
        {
            ClearBackground(BLACK);
            DrawLine(screenWidth/2,-1,screenWidth/2,screenHeight+1,defaultColor);


            player->draw();
            ball->draw();
            r_paddle->draw();

            DrawText(TextFormat("%d", score_1), screenWidth/2 - 50, 50, 24, defaultColor);
            DrawText(TextFormat("%d", score_2), screenWidth/2 + 50, 50, 24, defaultColor);

        }EndDrawing();
    }

    CloseWindow();

    delete player;
    delete ball;
    delete r_paddle;

    MemFree(player);
    MemFree(ball);
    MemFree(r_paddle);

    return 0;
}


void _collision(Paddle* player, Paddle* r_paddle, Ball* ball){
    if (ball->position.x - ball->radius <= player->position.x + 10 and (ball->position.y  -ball->radius >= player->position.y and ball->position.y -ball->radius <= player->position.y +player->length  ) )
    {   
        ball->speed.x *= -1;
        ball->speed.y *= (GetRandomValue(-500,500)/500) ;

    }
    else if (ball->position.x + ball->radius >= r_paddle->position.x and (ball->position.y  -ball->radius >= r_paddle->position.y and ball->position.y -ball->radius <= r_paddle->position.y +r_paddle->length  ))
    {
        ball->speed.x *= -1;
        ball->speed.y *= (GetRandomValue(-500,500)/500) ;
    }
    
    if (ball->position.y -ball->radius <=0 or ball->position.y +ball->radius >= GetScreenHeight()){
        ball->speed.y = ball->speed.y * -1;
    }
    
};
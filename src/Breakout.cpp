#include "Breakout.h"
#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 600;

const int brickRows = 6;
const int brickCols = 10;
const float brickWidth = 70.0f;
const float brickHeight = 20.0f;
const float brickSpacing = 5.0f;
const float brickStartX = 20.0f;
const float brickStartY = 50.0f;

void Breakout::Init() {
    InitWindow( screenWidth, screenHeight, "Breakout");
    SetTargetFPS(50);
    paddle = new Paddle({screenWidth / 2.0f - 50, screenHeight - 30}, {100,20}, WHITE, 6.0f);

    ball = new Ball({screenWidth / 2.0f, screenHeight / 2.0f}, {10,10}, YELLOW, {4.0f, 4.0f});

    Color brickColors[brickRows] = { DARKBLUE, DARKGREEN, GREEN, ORANGE, RED, MAROON};
    bricks.clear();

    for(int y = 0; y < brickRows; y++){
        for(int x = 0; x < brickCols; x++){
            float posX = brickStartX + x *(brickWidth + brickSpacing);
            float posY = brickStartY + y *(brickHeight + brickSpacing);
            bricks.push_back(Brick({posX, posY}, {brickWidth, brickHeight}, brickColors[y]));   
        }
    }
    gameOver = false;
    score = 0;
    lives = 3;
    
}

void Breakout::Update() {
    if(gameOver) {
        if(IsKeyPressed(KEY_R)){
            delete paddle;
            delete ball;
            Init();
        }
        return;
    }
    paddle->Update();
    ball->Update();

    if(ball->GetRect().x <= 0 || ball->GetRect().x + ball->GetRect().width >= screenWidth)
       ball->InvertSpeedX();
    if(ball->GetRect().y <= 0) ball->InvertSpeedY();

    if(CheckCollisionRecs(paddle->GetRect(), ball->GetRect())){
        ball->InvertSpeedY();
    }

    for(auto& brick : bricks){
        if(brick.IsVisible() && CheckCollisionRecs(brick.GetRect(), ball->GetRect())){
            brick.Destroy();
            ball->InvertSpeedY();
            score += 100;
            break;
        }
    }

    if(ball->GetRect().y > screenHeight){
        lives--;
        if(lives <= 0){
            gameOver = true;
        }else{
            ball->Reset({screenWidth / 2.0f, screenHeight / 2.0f}, {4.0f, 4.0f});
            paddle->Reset ({screenWidth / 2.0f - 50, screenHeight - 30});
        }
    } 


}

void Breakout::Draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    if(gameOver){
                   
        DrawText("Game Over", screenWidth / 2 - 100, screenHeight / 2 - 20, 40, RED);
        DrawText("Appuyer sur[R] pour recommencer", screenWidth / 2 - 150, screenHeight / 2 + 30, 20, DARKGRAY);
    }else {
        paddle->Draw();
        ball->Draw();
        for(auto& brick : bricks){
            brick.Draw();
        }
        //Score et vie
        DrawText(TextFormat("Score : %d", score), screenWidth - 150, 10, 20, WHITE);
        DrawText(TextFormat("Vies : %d", lives), 20, 10, 20, DARKBROWN);
    }
    EndDrawing();
}

bool Breakout::Not_finished() {
    return !WindowShouldClose();
}

void Breakout::Deinit() {
    delete paddle;
    delete ball;
    CloseWindow();
}
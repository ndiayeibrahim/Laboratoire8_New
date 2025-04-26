#include "Paddle.h"

Paddle::Paddle( Vector2 pos, Vector2 sz, Color col, float spd)
    : GameObject(pos, sz, col), speed(spd) {}

void Paddle::Update(){
    if(IsKeyDown(KEY_LEFT)) position.x -= speed;
    if(IsKeyDown(KEY_RIGHT)) position.x += speed;

    if(position.x < 0) position.x = 0;
    if(position.x + size.x > GetScreenWidth()) position.x = GetScreenWidth() - size.x;
    
}
 

void Paddle::Reset(Vector2 newPos){
    position = newPos;
}
#include "Ball.h"

Ball::Ball(Vector2 pos, Vector2 sz, Color col, Vector2 spd)
    : GameObject(pos, sz, col), speed(spd) {}

void Ball::Update(){
    position.x += speed.x;
    position.y += speed.y;
}

void Ball::InvertSpeedX(){
    speed.x *= -1;
}
void Ball::InvertSpeedY(){
    speed.y *= -1;
}
Vector2 Ball::GetSpeed() const {
    return speed;
}

void Ball::SetSpeed (Vector2 spd){
    speed = spd;
}

void Ball::Reset(Vector2 newPos, Vector2 newSpeed) {
    position = newPos;
    speed = newSpeed;
}

#pragma once
#include "Game.h"
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include <vector>

class Breakout : public Game {
private:
    Paddle* paddle;
    Ball* ball;
    std::vector<Brick> bricks;
    bool gameOver;
    int score;
    int lives;
public:
    void Init() override;
    void Update() override;
    void Draw() override;
    bool Not_finished() override;
    void Deinit() override;
    
};




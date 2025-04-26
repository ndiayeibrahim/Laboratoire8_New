#pragma once
#include "GameObject.h"

class Ball : public GameObject {
private:
    Vector2 speed;
public:
    Ball(Vector2 pos, Vector2 sz, Color col, Vector2 spd);

    void Update() override;
    void InvertSpeedX();
    void InvertSpeedY();
    Vector2 GetSpeed() const;
    void SetSpeed(Vector2 spd);
    void Reset(Vector2 newPos, Vector2 newSpeed);
};


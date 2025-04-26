#pragma once
#include "GameObject.h"

class Paddle : public GameObject {

public:
    float speed;
    Paddle( Vector2 pos, Vector2 sz, Color col, float spd);
    void Update() override;
    void Reset(Vector2 newPos);

};



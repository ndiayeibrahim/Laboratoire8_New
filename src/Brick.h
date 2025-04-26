#pragma once
#include "GameObject.h"

class Brick : public GameObject {
private:
    bool visible;
public:
    Brick(Vector2 pos, Vector2 sz, Color col);
    void Update() override {}
    void Draw() const override;
    bool IsVisible() const;
    void Destroy();


};


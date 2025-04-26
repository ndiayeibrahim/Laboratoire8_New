#pragma once
#include "raylib.h"

class GameObject {
protected:
   Vector2 position;
   Vector2 size;
   Color color;

public:
    GameObject(Vector2 pos, Vector2 sz, Color col);
    virtual void Update() = 0;
    virtual void Draw() const;
    virtual Rectangle GetRect() const;

};


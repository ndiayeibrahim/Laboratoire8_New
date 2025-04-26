#include "Brick.h"

Brick::Brick(Vector2 pos, Vector2 sz, Color col)
    : GameObject(pos, sz, col), visible(true) {}

void Brick::Draw() const {
    if (visible)
    {
        GameObject::Draw();
    }
    
}
bool Brick::IsVisible() const {
    return visible;
}

void Brick::Destroy() {
    visible = false;
}

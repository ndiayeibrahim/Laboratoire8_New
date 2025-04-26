#pragma once

class Game{
public: 
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual bool Not_finished() = 0;
    virtual void Deinit() = 0;
};

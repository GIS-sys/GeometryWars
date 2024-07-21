#pragma once

class GameScene {
  public:
    virtual ~GameScene() {};
    virtual void draw(uint32_t* buffer) = 0;
    virtual void act(float dt) = 0;
};

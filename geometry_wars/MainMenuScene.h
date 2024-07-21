#pragma once
#include "GameScene.h"


class MainMenuScene : public GameScene {
  private:
    float color;

  public:
    void draw(uint32_t* buffer);
    void act(float dt);
};

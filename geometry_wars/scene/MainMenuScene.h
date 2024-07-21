#pragma once
#include "GameScene.h"


class MainMenuScene {
  private:
    float color;

  public:
    MainMenuScene();
    void draw(uint32_t** buffer);
    void act(float dt);
};

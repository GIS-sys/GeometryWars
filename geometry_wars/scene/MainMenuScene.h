#pragma once
#include "GameScene.h"


class MainMenuScene : public GameScene {
  private:
    float color;

  public:
    MainMenuScene();
    void draw(GameBuffer&& buffer);
    void act(float dt);
};

#pragma once
#include "geometry_wars/scene/GameScene.h"


class MainMenuScene : public GameScene {
  private:
    float color;

  public:
    MainMenuScene();
    void draw(GameBuffer&& buffer);
    void act(float dt);
};

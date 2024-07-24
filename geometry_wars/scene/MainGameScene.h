#pragma once
#include "geometry_wars/scene/GameScene.h"


class MainGameScene : public GameScene {
  private:

  public:
    ~MainGameScene();
    MainGameScene();
    void draw(GameBuffer buffer);
    Type act(float dt);
};

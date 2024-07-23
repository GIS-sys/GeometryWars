#pragma once
#include "geometry_wars/scene/GameScene.h"
#include "geometry_wars/ui/GameObject.h"
#include <vector>


class MainMenuScene : public GameScene {
  private:
    std::vector<GameObject*> objects;
    void start();
    void exit();

  public:
    ~MainMenuScene();
    MainMenuScene();
    void draw(GameBuffer buffer);
    void act(float dt);
};

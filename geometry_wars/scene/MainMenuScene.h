#pragma once
#include "geometry_wars/scene/GameScene.h"
#include "geometry_wars/ui/GameObject.h"
#include <vector>


class MainMenuScene : public GameScene {
  private:
    std::vector<GameObject*> objects;
    bool prev_mleft = 0; // previous left mouse button state
    bool prev_mright = 0; // previous right mouse button state
    int prev_buffer_width = 0;
    int prev_buffer_height = 0;
    void start();
    void exit();

  public:
    ~MainMenuScene();
    MainMenuScene();
    void draw(GameBuffer buffer);
    void act(float dt);
};

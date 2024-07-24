#pragma once
#include "geometry_wars/scene/GameScene.h"


class MainGameScene : public GameScene {
  private:
    Camera camera;
    Battlefield battlefield;
    GOPlayer player;
    std::vector<GameObject*> enemies;
    std::vector<GameObject*> projectiles;
    GOLabel score;

    int prev_buffer_height = 0;
    int prev_buffer_width = 0;

  public:
    ~MainGameScene();
    MainGameScene();
    void draw(GameBuffer buffer);
    Type act(float dt);
};

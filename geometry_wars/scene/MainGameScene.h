#pragma once
#include "geometry_wars/scene/GameScene.h"
#include "geometry_wars/ui/Camera.h"
#include "geometry_wars/ui/Battlefield.h"
#include "geometry_wars/ui/GOLabel.h"
#include "geometry_wars/ui/Projectile.h"
#include "geometry_wars/ui/Unit.h"
#include "geometry_wars/ui/Player.h"
#include "geometry_wars/ui/Enemy.h"
#include <vector>


class MainGameScene : public GameScene {
  private:
    Camera camera;
    Battlefield battlefield;
    Player player;
    std::vector<Enemy*> enemies;
    std::vector<Projectile*> projectiles;
    GOLabel score;

    int prev_buffer_height = 0;
    int prev_buffer_width = 0;

  public:
    ~MainGameScene();
    MainGameScene();
    void draw(GameBuffer buffer);
    Type act(float dt);
};

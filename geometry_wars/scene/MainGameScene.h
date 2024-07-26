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
    const float ENEMY_SPAWN_PROBABILITY = 0.99;
    const float ENEMY_SPAWN_COOLDOWN = 20; //0.1;
    const int MIN_ENEMY_SPAWN_DISTANCE = 100;

    Camera camera;
    Battlefield battlefield;
    Player player;
    std::vector<Enemy*> enemies;
    std::vector<Projectile*> projectiles;
    GOLabel score_label = GOLabel(0.75, 0.05, 0.2, 0.1, (256*256+256+1) * 200);

    int score_value = 0;
    float enemy_spawn_cooldown = 0;
    int prev_buffer_height = 0;
    int prev_buffer_width = 0;

  public:
    ~MainGameScene();
    MainGameScene();
    void draw(GameBuffer buffer);
    Type act(float dt);
};

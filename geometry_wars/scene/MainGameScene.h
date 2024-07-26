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
    GOLabel health_label = GOLabel(0.05, 0.05, 0.3, 0.1, (256*256+256+1) * 200);
    GOLabel score_label = GOLabel(0.65, 0.05, 0.3, 0.1, (256*256+256+1) * 200);

    GOLabel game_over_label = GOLabel(0.35, 0.3, 0.3, 0.1, 200*256*256+50*256+30);
    GOLabel game_over_current_score = GOLabel(0.35, 0.45, 0.3, 0.1, (256*256+256+1) * 200);
    GOLabel game_over_high_score = GOLabel(0.35, 0.6, 0.3, 0.1, (256*256+256+1) * 200);

    int score_value = 0;
    int high_score_value = 0;
    float enemy_spawn_cooldown = 0;
    int prev_buffer_height = 0;
    int prev_buffer_width = 0;
    bool is_game_over = false;

    void restart();

  public:
    ~MainGameScene();
    MainGameScene();
    void draw(GameBuffer buffer) override;
    Type act(float dt) override;
};

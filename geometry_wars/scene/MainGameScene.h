#pragma once
#include "geometry_wars/scene/GameScene.h"
#include "geometry_wars/ui/Camera.h"
#include "geometry_wars/ui/Color.h"
#include "geometry_wars/ui/Battlefield.h"
#include "geometry_wars/ui/GOLabel.h"
#include "geometry_wars/ui/Projectile.h"
#include "geometry_wars/ui/Unit.h"
#include "geometry_wars/ui/Player.h"
#include "geometry_wars/ui/Enemy.h"
#include <vector>


class MainGameScene : public GameScene {
  private:
    EnemySpawner enemy_spawner;
    Camera camera;
    Battlefield battlefield;
    Player player;
    std::vector<Enemy*> enemies;
    std::vector<Projectile*> projectiles;
    GOLabel score_label = GOLabel(0, 0, 0.3, 0.1, Color::YELLOW());
    GOLabel health_label = GOLabel(0.3, 0, 0.35, 0.1, Color::ORANGE());
    GOLabel high_score_label = GOLabel(0.65, 0, 0.3, 0.1, Color::YELLOW());

    GOLabel game_over_label = GOLabel(0.05, 0.3, 0.9, 0.1, Color::RED());
    GOLabel game_over_current_score = GOLabel(0.25, 0.45, 0.5, 0.1, Color::WHITE());
    GOLabel game_over_high_score = GOLabel(0.25, 0.6, 0.5, 0.1, Color::WHITE());

    int score_value = 0;
    int high_score_value = 0;
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

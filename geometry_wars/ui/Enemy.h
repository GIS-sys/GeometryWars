#pragma once

#include "geometry_wars/ui/Battlefield.h"
#include "geometry_wars/ui/Unit.h"
#include "geometry_wars/ui/Projectile.h"


class Enemy : public Unit {
  public:
    int health = 10;
    int bounty = 13;
    float dps = 100;
    Enemy(float x, float y) : Unit(x, y) {}
    void hit(Projectile* projectile) { health -= projectile->damage; }
    bool is_dead() const { return health <= 0; }
};


class EnemyRectangle : public Enemy {
  private:
    const int SIZE = 10;
  public:
    EnemyRectangle(int x, int y) : Enemy(x, y) {}
    bool is_inside(float px, float py, int, int) override {
        return x - SIZE <= px && px <= x + SIZE && y - SIZE <= py && py <= y + SIZE;
    }
    void draw(GameBuffer buffer, Camera* camera) override {
        buffer.draw_rect(x-SIZE, y-SIZE, x+SIZE, y+SIZE, 150*256, camera);
    }
};


class EnemySpawner {
  private:
    // spawner - have no time to move to separate class
    const float ENEMY_SPAWN_PROBABILITY = 0.99;
    const float ENEMY_SPAWN_COOLDOWN = 0.1;
    const int MIN_ENEMY_SPAWN_DISTANCE = 100;
    float enemy_spawn_cooldown = 0;

  public:
    void restart() {
        enemy_spawn_cooldown = 0;
    }

    Enemy* spawn(float dt, int score, std::pair<float, float> player_position, Battlefield& battlefield) {
        enemy_spawn_cooldown -= dt;
        while (enemy_spawn_cooldown < 0) {
            enemy_spawn_cooldown += ENEMY_SPAWN_COOLDOWN;
            if (std::rand() * 1.0 / RAND_MAX < ENEMY_SPAWN_PROBABILITY) {
                std::pair<float, float> new_enemy_pos = player_position;
                while (distance(new_enemy_pos, player_position) < MIN_ENEMY_SPAWN_DISTANCE) {
                    new_enemy_pos = {std::rand() % battlefield.get_width(), std::rand() % battlefield.get_height()};
                }
                return new EnemyRectangle(new_enemy_pos.first, new_enemy_pos.second);
            }
        }
        return nullptr;
    }
};

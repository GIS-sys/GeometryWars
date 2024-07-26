#pragma once

#include "geometry_wars/ui/Battlefield.h"
#include "geometry_wars/ui/Unit.h"
#include "geometry_wars/ui/Projectile.h"


class Enemy : public Unit {
  public:
    int initial_health;
    int health;
    int bounty;
    float dps;
    Enemy(float x, float y, int initial_health=10, int bounty=13, int dps=100) : Unit(x, y), initial_health(initial_health), health(initial_health), bounty(bounty), dps(dps) {}
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


class EnemyCircle : public Enemy {
  private:
    const int SIZE = 10;
  public:
    EnemyCircle(int x, int y) : Enemy(x, y) {}
    bool is_inside(float px, float py, int, int) override {
        return (x - px) * (x - px) + (y - py) * (y - py) <= SIZE * SIZE;
    }
    void draw(GameBuffer buffer, Camera* camera) override {
        buffer.draw_circle(x, y, SIZE, 150*256, camera);
    }
};


class EnemySpawner {
  private:
    // spawner - have no time to move to separate class
    const float ENEMY_SPAWN_PROBABILITY = 0.2;
    const float ENEMY_SPAWN_COOLDOWN = 0.2;
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
                // position
                std::pair<float, float> new_enemy_pos = player_position;
                while (distance(new_enemy_pos, player_position) < MIN_ENEMY_SPAWN_DISTANCE) {
                    new_enemy_pos = {std::rand() % battlefield.get_width(), std::rand() % battlefield.get_height()};
                }
                // enemy type
                Enemy* new_enemy = nullptr;
                float random_type = (std::rand() * 1.0 / RAND_MAX);
                if (0 <= random_type && random_type <= 0.5) {
                    new_enemy = new EnemyRectangle(new_enemy_pos.first, new_enemy_pos.second);
                } else {
                    new_enemy = new EnemyCircle(new_enemy_pos.first, new_enemy_pos.second);
                }
                // vary parameters
                new_enemy->speed_magnitude *= (std::rand() * 2.0 / RAND_MAX);
                return new_enemy;
            }
        }
        return nullptr;
    }
};

#pragma once

#include "geometry_wars/ui/Battlefield.h"
#include "geometry_wars/ui/Unit.h"
#include "geometry_wars/ui/Projectile.h"
#include <iostream>

class Enemy : public Unit {
  public:
    Color color;
    int max_health;
    int bounty;
    float dps;
    float size;
    int health;
    Enemy(float x, float y, int max_health, int bounty, float dps, Color color, float size) : Unit(x, y), max_health(max_health), health(max_health), bounty(bounty), dps(dps), color(color), size(size) {}
    void hit(Projectile* projectile) { health -= projectile->damage; }
    bool is_dead() const { return health <= 0; }
};


class EnemyRectangle : public Enemy {
  private:
    const int BASE_MAX_HEALTH = 10;
    const int BASE_BOUNTY = 10;
    const int BASE_DPS = 10;
    const Color BASE_COLOR = Color::RED();
    const int BASE_SPEED = 10;
    const int BASE_SIZE = 10;

  public:
    EnemyRectangle(int x, int y) : Enemy(x, y, BASE_MAX_HEALTH, BASE_BOUNTY, BASE_DPS, BASE_COLOR, BASE_SIZE) { speed_magnitude = BASE_SPEED; }
    bool is_inside(float px, float py, int, int) override {
        return x - size <= px && px <= x + size && y - size <= py && py <= y + size;
    }
    void draw(GameBuffer buffer, Camera* camera) override {
        buffer.draw_rect(x - size, y - size, x + size, y + size, color, camera);
    }
};


class EnemyCircle : public Enemy {
  private:
    const int BASE_MAX_HEALTH = 20;
    const int BASE_BOUNTY = 10;
    const int BASE_DPS = 10;
    const Color BASE_COLOR = Color::GREEN();
    const int BASE_SPEED = 10;
    const int BASE_SIZE = 10;

  public:
    EnemyCircle(int x, int y) : Enemy(x, y, BASE_MAX_HEALTH, BASE_BOUNTY, BASE_DPS, BASE_COLOR, BASE_SIZE) { speed_magnitude = BASE_SPEED; }
    bool is_inside(float px, float py, int, int) override {
        return (x - px) * (x - px) + (y - py) * (y - py) <= size * size;
    }
    void draw(GameBuffer buffer, Camera* camera) override {
        buffer.draw_circle(x, y, size, color, camera);
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
        std::cout << "1" << std::endl;
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
                std::cout << "2" << std::endl;
                return new_enemy;
            }
        }
        return nullptr;
    }
};

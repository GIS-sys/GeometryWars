#pragma once

#include "geometry_wars/ui/Battlefield.h"
#include "geometry_wars/ui/Unit.h"
#include "geometry_wars/ui/Projectile.h"


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
    Color color_healthed() const { return color * (0.5 + 0.5 * health / max_health); }
};


class EnemyCircle : public Enemy {
    public:
        EnemyCircle(int x, int y) : Enemy(x, y, 10, 10, 10, Color::BLUE(), 10) { speed_magnitude = 100; }
        bool is_inside(float px, float py, int, int) override {
            return (x - px) * (x - px) + (y - py) * (y - py) <= size * size;
        }
        void draw(GameBuffer buffer, Camera* camera) override {
            buffer.draw_circle(x, y, size, color_healthed(), camera);
        }
};


class EnemyRectangle : public Enemy {

  public:
    EnemyRectangle(int x, int y) : Enemy(x, y, 20, 18, 20, Color::RED(), 20) { speed_magnitude = 150; }
    bool is_inside(float px, float py, int, int) override {
        return x - size <= px && px <= x + size && y - size <= py && py <= y + size;
    }
    void draw(GameBuffer buffer, Camera* camera) override {
        buffer.draw_rect(x - size, y - size, x + size, y + size, color_healthed(), camera);
    }
};


class EnemyTriangle : public Enemy {
    public:
        EnemyTriangle(int x, int y) : Enemy(x, y, 30, 24, 30, Color::GREEN(), 30) { speed_magnitude = 200; }
        bool is_inside(float px, float py, int, int) override {
            return (x - px) * (x - px) + (y - py) * (y - py) <= size * size;
        }
        void draw(GameBuffer buffer, Camera* camera) override {
            const int STROKE = 4;
            buffer.draw_line(x - size / 2, y + size / 2, x, y - size, STROKE, color_healthed(), camera);
            buffer.draw_line(x + size / 2, y + size / 2, x, y - size, STROKE, color_healthed(), camera);
            buffer.draw_line(x - size / 2, y + size / 2, x + size / 2, y + size / 2, STROKE, color_healthed(), camera);
        }
};


class EnemySpawner {
  private:
    // spawner - have no time to move to separate class
    const float ENEMY_SPAWN_PROBABILITY = 0.2;
    const float ENEMY_SPAWN_COOLDOWN = 0.2;
    const int MIN_ENEMY_SPAWN_DISTANCE = 100;
    float enemy_spawn_cooldown = 0;
    int already_spawned = 0;

  public:
    void restart() {
        enemy_spawn_cooldown = 0;
        already_spawned = 0;
    }

    Enemy* spawn(float dt, std::pair<float, float> player_position, Battlefield& battlefield) {
        enemy_spawn_cooldown -= dt;
        while (enemy_spawn_cooldown < 0) {
            enemy_spawn_cooldown += ENEMY_SPAWN_COOLDOWN;
            if (std::rand() * 1.0 / RAND_MAX < ENEMY_SPAWN_PROBABILITY) {
                // spawned
                already_spawned += 1;
                // position
                std::pair<float, float> new_enemy_pos = player_position;
                while (distance(new_enemy_pos, player_position) < MIN_ENEMY_SPAWN_DISTANCE) {
                    new_enemy_pos = {std::rand() % battlefield.get_width(), std::rand() % battlefield.get_height()};
                }
                // enemy type
                float prob_rectangle = std::max(0.0, 1 - already_spawned / 10.0);
                float prob_circle = std::max(0.0, 1 - already_spawned / 50.0);
                // create enemy
                Enemy* new_enemy = nullptr;
                float random_type = (std::rand() * 1.0 / RAND_MAX);
                if (0 <= random_type && random_type < prob_rectangle) {
                    new_enemy = new EnemyRectangle(new_enemy_pos.first, new_enemy_pos.second);
                } else if (prob_rectangle <= random_type && random_type < prob_rectangle+prob_circle) {
                    new_enemy = new EnemyCircle(new_enemy_pos.first, new_enemy_pos.second);
                } else {
                    new_enemy = new EnemyTriangle(new_enemy_pos.first, new_enemy_pos.second);
                }
                // vary parameters for some randomness
                new_enemy->speed_magnitude *= (std::rand() * 2.0 / RAND_MAX);
                new_enemy->bounty *= (0.5 + std::rand() * 1.0 / RAND_MAX);
                return new_enemy;
            }
        }
        return nullptr;
    }
};

#pragma once

#include "geometry_wars/ui/Unit.h"
#include "geometry_wars/Utils.h"
#include <iostream>


class Player : public Unit {
  private:
    static constexpr int WEAPON_DAMAGE = 4;
    static constexpr float WEAPON_COOLDOWN = 0.3;
    static constexpr float WEAPON_PROJECTILE_SPEED = 3;
    float MAX_SPEED = 0.25;
    int MAX_HEALTH = 100;
    float acceleration_magnitude = 1;
    float weapon_cooldown_rest = 0;
    float speed_x = 0;
    float speed_y = 0;
    float health = 100;

  public:
    Player() : Unit(0, 0) {}
    bool is_ready_to_shoot() const { return weapon_cooldown_rest <= 0; }
    void reset_shooting_cooldown() { weapon_cooldown_rest = WEAPON_COOLDOWN; }
    void reduce_shooting_cooldown(float dt) { weapon_cooldown_rest = std::max((float)0, weapon_cooldown_rest - dt); }
    Projectile* shoot_projectile(int target_x, int target_y) const {
        auto [vx, vy] = normalize_pair<float>({target_x - x, target_y - y});
        return new Projectile(x, y, vx * WEAPON_PROJECTILE_SPEED, vy * WEAPON_PROJECTILE_SPEED, WEAPON_DAMAGE);
    }
    void draw(GameBuffer buffer, Camera* camera) override {
        buffer.draw_circle(x, y, 10, Color::GREEN(), camera);
    }
    void move(std::pair<float, float> acceleration_dt) override {
        speed_x += acceleration_dt.first * acceleration_magnitude;
        speed_y += acceleration_dt.second * acceleration_magnitude;
        if (speed_x*speed_x + speed_y*speed_y >= MAX_SPEED*MAX_SPEED) {
            auto new_speed = normalize_pair<float>({speed_x, speed_y});
            speed_x = new_speed.first * MAX_SPEED;
            speed_y = new_speed.second * MAX_SPEED;
        }
        //std::cout << speed_x*speed_x+speed_y*speed_y << std::endl;
        x += speed_x;
        y += speed_y;
    }
    float get_speed_x() const { return speed_x; }
    float get_speed_y() const { return speed_y; }
    float get_health() const { return health; }
    void update_health(float dh) {
        health += dh;
        if (health > MAX_HEALTH) health = MAX_HEALTH;
    }
};

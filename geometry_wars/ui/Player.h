#pragma once

#include "geometry_wars/ui/Unit.h"
#include "geometry_wars/Utils.h"


class Player : public Unit {
  private:
    const int WEAPON_DAMAGE = 4;
    const float WEAPON_COOLDOWN = 0.3;
    const float WEAPON_PROJECTILE_SPEED = 3;
    float weapon_cooldown_rest = 0;

  public:
    Player() : Unit(0, 0) {}
    bool is_ready_to_shoot() const { return weapon_cooldown_rest <= 0; }
    void reset_shooting_cooldown() { weapon_cooldown_rest = WEAPON_COOLDOWN; }
    void reduce_shooting_cooldown(float dt) { weapon_cooldown_rest = std::max((float)0, weapon_cooldown_rest - dt); }
    Projectile* shoot_projectile(int target_x, int target_y) const {
        auto [vx, vy] = normalize_pair<float>({target_x - x, target_y - y});
        return new Projectile(x, y, vx * WEAPON_PROJECTILE_SPEED, vy * WEAPON_PROJECTILE_SPEED, WEAPON_DAMAGE);
    }
    void draw(GameBuffer buffer, Camera* camera) {
        buffer.draw_line(x-10, y-10, x+10, y+10, 5, 150*256);
    }
};

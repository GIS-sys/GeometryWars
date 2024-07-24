#pragma once

#include "geometry_wars/ui/Unit.h"


class Player : public Unit {
  private:
    const int WEAPON_DAMAGE = 4;
    const float WEAPON_COOLDOWN = 5;
    float weapon_cooldown_rest = 0;

  public:
    bool is_ready_to_shoot() const { return weapon_cooldown_rest <= 0; }
    void reset_shooting_cooldown() { weapon_cooldown_rest = WEAPON_COOLDOWN; }
    void reduce_shooting_cooldown(float dt) { weapon_cooldown_rest = std::max((float)0, weapon_cooldown_rest - dt); }
    Projectile* shoot_projectile(int target_x, int target_y) const { return new Projectile(WEAPON_DAMAGE); }
    void draw(GameBuffer buffer, Camera* camera) {
        buffer.draw_line(x-10, y-10, x+10, y+10, 5, 150*256);
    }
};

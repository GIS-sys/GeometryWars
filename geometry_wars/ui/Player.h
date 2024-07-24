#pragma once

#include "geometry_wars/ui/Unit.h"


class Player : public Unit {
  public:
    bool is_ready_to_shoot() const;
    void reset_shooting_cooldown();
    void reduce_shooting_cooldown(float dt);
    Projectile* shoot_projectile(int target_x, int target_y) const;
};

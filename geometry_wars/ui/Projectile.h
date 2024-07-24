#pragma once

#include "geometry_wars/ui/Unit.h"


class Projectile : public Unit {
  public:
    int damage;
    Projectile(int damage) : damage(damage) {}
};

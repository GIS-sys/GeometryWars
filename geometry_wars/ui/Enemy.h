#pragma once

#include "geometry_wars/ui/Unit.h"
#include "geometry_wars/ui/Projectile.h"


class Enemy : public Unit {
  public:
    int x;
    int y;
    int health;
    int bounty;
    Enemy(int x, int y);
    void hit(Projectile* projectile);
    bool is_dead() const;
};

class EnemyRectangle : public Enemy {
  public:
    EnemyRectangle(int x, int y);
};

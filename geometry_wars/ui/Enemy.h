#pragma once

#include "geometry_wars/ui/Unit.h"
#include "geometry_wars/ui/Projectile.h"


class Enemy : public Unit {
  public:
    int x = 0;
    int y = 0;
    int health = 10;
    int bounty = 13;
    Enemy(int x, int y) : x(x), y(y) {}
    void hit(Projectile* projectile) { health -= projectile->damage; }
    bool is_dead() const { return health <= 0; }
};

class EnemyRectangle : public Enemy {
  public:
    EnemyRectangle(int x, int y) : Enemy(x, y) {}
    void draw(GameBuffer buffer, Camera* camera) {
        buffer.draw_line(x+10, y-10, x-10, y+10, 5, 150*256);
    }
};

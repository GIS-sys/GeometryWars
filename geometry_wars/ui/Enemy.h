#pragma once

#include "geometry_wars/ui/Unit.h"
#include "geometry_wars/ui/Projectile.h"


class Enemy : public Unit {
  public:
    int health = 10;
    int bounty = 13;
    Enemy(float x, float y) : Unit(x, y) {}
    void hit(Projectile* projectile) { health -= projectile->damage; }
    bool is_dead() const { return health <= 0; }
};

class EnemyRectangle : public Enemy {
  private:
    const int SIZE = 10;
  public:
    EnemyRectangle(int x, int y) : Enemy(x, y) {}
    bool is_inside(float px, float py, int, int) {
        return x - SIZE <= px && px <= x + SIZE && y - SIZE <= py && py <= y + SIZE;
    }
    void draw(GameBuffer buffer, Camera* camera) {
        buffer.draw_line(x+SIZE, y-SIZE, x-SIZE, y+SIZE, 5, 150*256, camera);
    }
};

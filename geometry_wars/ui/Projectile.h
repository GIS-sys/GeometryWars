#pragma once

#include "geometry_wars/ui/Unit.h"


class Projectile : public Unit {
  public:
    int damage;
    float speed_x;
    float speed_y;
    Projectile(float x, float y, float vx, float vy, int damage) : Unit(x, y), speed_x(vx), speed_y(vy), damage(damage) {}
    void draw(GameBuffer buffer, Camera* camera) {
        buffer.draw_line(x-5, y, x+5, y, 5, 255, camera);
    }
};

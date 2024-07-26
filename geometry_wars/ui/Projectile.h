#pragma once

#include "geometry_wars/ui/Unit.h"


class Projectile : public Unit {
  public:
    Color color;
    float radius;
    float speed_x;
    float speed_y;
    int damage;
    Projectile(float x, float y, float vx, float vy, int damage, float radius = 5, Color color = Color::WHITE()) : Unit(x, y), speed_x(vx), speed_y(vy), damage(damage), radius(radius), color(color) {}
    void draw(GameBuffer buffer, Camera* camera) override {
        buffer.draw_circle(x, y, radius, color, camera);
    }
};

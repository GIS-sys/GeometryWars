#pragma once

#include "geometry_wars/ui/GameObject.h"


class Unit : public GameObject {
  public:
    float x = 0;
    float y = 0;
    float speed_magnitude = 100;
    Unit(int x, int y) : x(x), y(y) {}
    virtual void move(std::pair<float, float> acceleration, float dt) {
        x += acceleration.first * dt * speed_magnitude;
        y += acceleration.second * dt * speed_magnitude;
    }
    std::pair<float, float> position() const { return {x, y}; }
    void set_position(std::pair<float, float> pos) { x = pos.first; y = pos.second; }
};

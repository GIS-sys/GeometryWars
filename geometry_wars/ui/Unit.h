#pragma once

#include "geometry_wars/ui/GameObject.h"


class Unit : public GameObject {
  public:
    int x = 0;
    int y = 0;
    virtual void move(std::pair<int, int> acceleration_dt) { x += acceleration_dt.first; y += acceleration_dt.second; }
    std::pair<int, int> position() const { return {x, y}; }
};

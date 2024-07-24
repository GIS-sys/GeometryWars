#pragma once

#include "geometry_wars/ui/GameObject.h"


class Unit : public GameObject {
  public:
    int x;
    int y;
    void move(std::pair<int, int> acceleration_dt);
    std::pair<int, int> position() const { return {x, y}; }
};

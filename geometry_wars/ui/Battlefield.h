#pragma once

#include "geometry_wars/ui/GameObject.h"


class Battlefield : public GameObject {
  public:
    bool is_inside(int x, int y, int buffer_width, int buffer_height) { return true; }
};

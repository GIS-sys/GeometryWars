#pragma once

#include "geometry_wars/ui/Unit.h"


class Enemy : public Unit {
  public:
    int x;
    int y;
    Enemy(int x, int y);
};

class EnemyRectangle : public Enemy {
  public:
    EnemyRectangle(int x, int y);
};

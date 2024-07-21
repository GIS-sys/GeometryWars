#pragma once

#include "geometry_wars/ui/GameBuffer.h"
#include <cstdio>
#include <stdint.h>


class GameScene {
  public:
    ~GameScene();
    virtual void draw(GameBuffer&& buffer) = 0;
    virtual void act(float dt) = 0;
};

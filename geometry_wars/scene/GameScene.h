#pragma once

#include <cstdio>
#include <stdint.h>


class GameScene {
  public:
    ~GameScene();

    template <std::size_t N, std::size_t M>
    void draw(uint32_t (&buffer)[N][M]);

    void act(float dt);
};

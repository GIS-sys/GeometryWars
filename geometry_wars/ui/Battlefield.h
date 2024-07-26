#pragma once

#include "geometry_wars/ui/GameObject.h"


class Battlefield : public GameObject {
  private:
    static constexpr int STROKE = 5;
    int width;
    int height;
  public:
    Battlefield(int width, int height) : width(width), height(height) {}
    bool is_inside(int x, int y, int, int) {
        return 0 <= x && x <= width && 0 <= y && y <= height;
    }
    void draw(GameBuffer buffer, Camera* camera) {
        buffer.draw_line(0, 0, width, 0, STROKE, 150*256);
        buffer.draw_line(0, 0, 0, height, STROKE, 150*256);
        buffer.draw_line(width, height, width, 0, STROKE, 150*256);
        buffer.draw_line(width, height, 0, height, STROKE, 150*256);
    }
};

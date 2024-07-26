#pragma once

#include "geometry_wars/ui/GameObject.h"


class Battlefield : public GameObject {
  private:
    static constexpr int STROKE = 5;
    int width;
    int height;
  public:
    Battlefield(int width, int height) : width(width), height(height) {}
    bool is_inside(float x, float y, int, int) override {
        return 0 <= x && x <= width && 0 <= y && y <= height;
    }
    std::pair<float, float> snap_inside(std::pair<float, float> original_pos) {
        return {
            (original_pos.first < 0) ? 0 : ((original_pos.first > width) ? width : original_pos.first),
            (original_pos.second < 0) ? 0 : ((original_pos.second > height) ? height : original_pos.second)
        };
    }
    void draw(GameBuffer buffer, Camera* camera) override {
        buffer.draw_line(0, 0, width, 0, STROKE, 150*256, camera);
        buffer.draw_line(0, 0, 0, height, STROKE, 150*256, camera);
        buffer.draw_line(width, height, width, 0, STROKE, 150*256, camera);
        buffer.draw_line(width, height, 0, height, STROKE, 150*256, camera);
    }
    int get_width() const { return width; }
    int get_height() const { return height; }
};

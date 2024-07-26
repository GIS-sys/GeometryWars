#pragma once
#include <utility>


class Camera {
  public:
    static constexpr float LAG = 50;
    int buffer_width = 0;
    int buffer_height = 0;
    float fov = 1;
    int corner_x = 0;
    int corner_y = 0;
    void center_on(int center_x, int center_y) {
        corner_x = center_x - fov / 2 * buffer_width;
        corner_y = center_y - fov / 2 * buffer_height;
    }
    std::pair<int, int> convert(std::pair<int, int> coordinate) const {
        return {
            (coordinate.first - corner_x) / fov,
            (coordinate.second - corner_y) / fov
        };
    }
    std::pair<int, int> anti_convert(std::pair<int, int> coordinate) const {
        return {
            coordinate.first * fov + corner_x,
            coordinate.second * fov + corner_y
        };
    }
};

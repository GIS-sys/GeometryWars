#pragma once


class Camera {
  public:
    int buffer_width = 0;
    int buffer_height = 0;
    float fov = 1;
    int corner_x = 0;
    int corner_y = 0;
    void center_on(int center_x, int center_y) {
        corner_x = center_x - fov / 2 * buffer_width;
        corner_y = center_y - fov / 2 * buffer_height;
    }
};

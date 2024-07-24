#pragma once


class Camera {
  public:
    int fov = 1;
    int center_x = 0;
    int center_y = 0;
    void center_on(int x, int y) { center_x = x; center_y = y; }
};

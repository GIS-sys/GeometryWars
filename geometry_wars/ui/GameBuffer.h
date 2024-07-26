#pragma once

#include "geometry_wars/ui/Color.h"
#include "geometry_wars/ui/Camera.h"
#include <cstdio>
#include <cstring>
#include <stdint.h>
#include <string>


class GameBuffer {
  private:
    uint32_t* buffer;

  public:
    std::size_t height;
    std::size_t width;

    GameBuffer(uint32_t* buffer, std::size_t height, std::size_t width) : buffer(buffer), height(height), width(width) {}
    ~GameBuffer() = default;

    void memset(uint32_t value, size_t from, size_t to);
    void set(uint32_t x, uint32_t y, Color color, const Camera* camera = nullptr);
    void draw_line(int x1, int x2, int y1, int y2, int width, Color color, const Camera* camera = nullptr);
    void draw_circle(int cx, int cy, int radius, Color color, const Camera* camera = nullptr);
    void draw_text(const std::string& text, int left, int top, int right, int bottom, Color color, const Camera* camera = nullptr);
};

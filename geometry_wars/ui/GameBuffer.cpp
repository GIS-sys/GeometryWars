#include "GameBuffer.h"
#include "geometry_wars/Utils.h"
#include "geometry_wars/ui/Font.h"
#include <iostream>


void GameBuffer::memset(uint32_t value, size_t from, size_t to) {
    from = clamp(from, 0, width * height - 1);
    to = clamp(to, 0, width * height - 1);
    std::memset(buffer + from, value, (to - from) * sizeof(uint32_t));
}

void GameBuffer::set(uint32_t x, uint32_t y, uint32_t red, uint32_t green, uint32_t blue) {
    red = clamp(red, 0, 255);
    green = clamp(green, 0, 255);
    blue = clamp(blue, 0, 255);
    int color = (uint32_t)(red*256*256 + blue*256 + green);
    set(x, y, color);
}
void GameBuffer::set(uint32_t x, uint32_t y, uint32_t color) {
    x = clamp(x, 0, width);
    y = clamp(y, 0, height);
    buffer[x + y * width] = color;
}

void GameBuffer::draw_line(int x1, int y1, int x2, int y2, int width, uint32_t color) {
    int xsign = (x2 - x1 < 0) ? -1 : 1;
    int ysign = (y2 - y1 < 0) ? -1 : 1;
    if (std::abs(x2 - x1) > std::abs(y2 - y1)) {
        float a = (float)(y2 - y1) / (x2 - x1);
        for (int x = x1; x*xsign < x2*xsign; x+=xsign) {
            float y_center = y1 + a * (x - x1);
            for (int y = y_center - width / 2; y < y_center + (width - width / 2); ++y) {
                set(x, y, color);
            }
        }
    } else {
        float a = (float)(x2 - x1) / (y2 - y1);
        for (int y = y1; y*ysign < y2*ysign; y+=ysign) {
            float x_center = x1 + a * (y - y1);
            for (int x = x_center - width / 2; x < x_center + (width - width / 2); ++x) {
                set(x, y, color);
            }
        }
    }
}

void GameBuffer::draw_text(const std::string& text, int left, int top, int right, int bottom, uint32_t color) {
    int total_height = Font::estimate_height(text);
    int total_width = Font::estimate_width(text);
    float scale = 5; // TODO
    int x = left;
    int y = top;
    Font::draw_text(*this, text, x, y, scale, color);
}

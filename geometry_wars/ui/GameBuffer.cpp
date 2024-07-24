#include "GameBuffer.h"
#include "geometry_wars/Utils.h"
#include "geometry_wars/ui/Font.h"
#include <iostream>


void GameBuffer::memset(uint32_t value, size_t from, size_t to) {
    from = clamp(from, 0, width * height - 1);
    to = clamp(to, from, width * height - 1);
    std::memset(buffer + from, value, (to - from) * sizeof(uint32_t));
}

void GameBuffer::set(uint32_t x, uint32_t y, Color color) {
    if (x < 0 || x >= width || y < 0 || y >= height) return;
    buffer[x + y * width] = Color::mix(color, Color(buffer[x + y * width])).raw();
}

void GameBuffer::draw_line(int x1, int y1, int x2, int y2, int width, Color color) {
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

void GameBuffer::draw_text(const std::string& text, int left, int top, int right, int bottom, Color color) {
    int total_height = Font::estimate_height(text);
    int total_width = Font::estimate_width(text);
    float scale = std::min(1.0 * (right - left) / total_width, 1.0 * (bottom - top) / total_height);
    int x = (left + right - total_width * scale) / 2;
    int y = (top + bottom - total_height * scale) / 2;
    Font::draw_text(*this, text, x, y, scale, color);
}

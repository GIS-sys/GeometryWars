#include "GameBuffer.h"
#include "geometry_wars/Utils.h"
#include <iostream>


class Font {
  private:
    static const int FONT_BASE_HEIGHT = 16;
    static const int FONT_BASE_WIDTH = 8;

  public:
    static int estimate_height(const std::string& text) { return FONT_BASE_HEIGHT; }
    static int estimate_width(const std::string& text) { return FONT_BASE_WIDTH * text.size(); }
    static void draw_text(GameBuffer& buffer, const std::string& text, int x, int y, float scale, uint32_t color) {
        for (char symbol : text) {
            std::pair<int, int> delta = draw_char(buffer, symbol, x, y, scale, color);
            x += delta.first;
            y += delta.second;
        }
    }
    static std::pair<int, int> draw_char(GameBuffer& buffer, char symbol, int x, int y, float scale, uint32_t color) {
        if (symbol == 't') {
            buffer.draw_line(x, y, x + 20, y + 20, 5, color);
        } else {
            buffer.draw_line(x, y, x + 20, y + 10, 2, color);
            buffer.draw_line(x, y + 20, x + 20, y, 2, color);
        }
        return {20, 0};
        // TODO
    }
};


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
    float scale = 0.5; // TODO
    int x = left;
    int y = top;
    Font::draw_text(*this, text, x, y, scale, color);
}

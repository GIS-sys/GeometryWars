#pragma once

#include "geometry_wars/ui/GameObject.h"


class GOLabel : public GameObject {
  private:
    static constexpr float LABEL_PAD_X = 0.2;
    static constexpr float LABEL_PAD_Y = 0.2;
  public:
    std::string text;
    float left;
    float top;
    float width;
    float height;
    Color color;

    GOLabel(float left, float top, float width, float height, Color color) : left(left), top(top), width(width), height(height), color(color) {}

    void draw(GameBuffer buffer, Camera*) {
        int x1 = left * buffer.width;
        int x2 = x1 + width * buffer.width;
        int y1 = top * buffer.height;
        int y2 = y1 + height * buffer.height;
        float pad_x = (x2 - x1) * LABEL_PAD_X;
        float pad_y = (y2 - y1) * LABEL_PAD_Y;
        buffer.draw_text(text, x1 + pad_x, y1 + pad_y, x2 - pad_x, y2 - pad_y, color);
    }
};

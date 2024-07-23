#include "geometry_wars/ui/GOButton.h"


GOButton::GOButton(float left, float top, float width, float height, std::string label, uint32_t color, std::function<void()> on_click) : left(left), top(top), width(width), height(height), label(label), color(color), on_click(on_click) {}

void GOButton::draw(GameBuffer buffer) {
    int x1 = left * buffer.width;
    int x2 = x1 + width * buffer.width;
    int y1 = top * buffer.height;
    int y2 = y1 + height * buffer.height;
    buffer.draw_line(x1, y1, x2, y1, 4, color);
    buffer.draw_line(x1, y2, x2, y2, 4, color);
    buffer.draw_line(x1, y1, x1, y2, 4, color);
    buffer.draw_line(x2, y1, x2, y2, 4, color);
    buffer.draw_text(label, x1, y1, x2, y2, color);
}

bool GOButton::is_inside() { return true; }

void GOButton::click() { on_click(); }

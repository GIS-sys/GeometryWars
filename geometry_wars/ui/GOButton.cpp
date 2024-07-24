#include "geometry_wars/ui/GOButton.h"
#include <iostream>

GOButton::GOButton(float left, float top, float width, float height, std::string label, uint32_t color, std::function<void()> on_click) : left(left), top(top), width(width), height(height), label(label), color(color), on_click(on_click) {}

void GOButton::draw(GameBuffer buffer) {
    int x1 = left * buffer.width;
    int x2 = x1 + width * buffer.width;
    int y1 = top * buffer.height;
    int y2 = y1 + height * buffer.height;
    buffer.draw_line(x1, y1, x2, y1, pressed?4:8, color);
    buffer.draw_line(x1, y2, x2, y2, pressed?8:4, color);
    buffer.draw_line(x1, y1, x1, y2, pressed?4:8, color);
    buffer.draw_line(x2, y1, x2, y2, pressed?8:4, color);
    float pad_x = (x2 - x1) * BUTTON_PAD_X;
    float pad_y = (y2 - y1) * BUTTON_PAD_Y;
    buffer.draw_text(label, x1 + pad_x, y1 + pad_y, x2 - pad_x, y2 - pad_y, color);
}

bool GOButton::is_inside(int x, int y, int buffer_width, int buffer_height) {
    if (buffer_width == 0 || buffer_height == 0) return false;
    float fx = 1.0 * x / buffer_width;
    float fy = 1.0 * y / buffer_height;
    return left <= fx && fx <= left+width && top <= fy && fy <= top+height;
}

void GOButton::mouse_outside(bool lmb_pressed, bool rmb_pressed) {
    if (!lmb_pressed) pressed = false;
}

void GOButton::mouse_press(int button) {
    pressed = true;
}

void GOButton::mouse_release(int button) {
    if (pressed) on_click();
    pressed = false;
}

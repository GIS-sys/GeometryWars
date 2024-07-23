#include "GameBuffer.h"
#include "geometry_wars/Utils.h"

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

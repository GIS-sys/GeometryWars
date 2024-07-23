#pragma once

#include <cstdio>
#include <cstring>
#include <stdint.h>


class GameBuffer {
  public:
    uint32_t* buffer;
    std::size_t height;
    std::size_t width;

    GameBuffer(uint32_t* buffer, std::size_t height, std::size_t width) : buffer(buffer), height(height), width(width) {}
    ~GameBuffer() = default;

    void memset(uint32_t value, size_t from, size_t to);
    void set(uint32_t x, uint32_t y, uint32_t red, uint32_t green, uint32_t blue);
    void set(uint32_t x, uint32_t y, uint32_t color);
};

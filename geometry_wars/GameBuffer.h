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

    void memset(uint32_t value, size_t from, size_t to) {
        if (to > height * width) to = height * width;
        std::memset(buffer + from, value, (to - from) * sizeof(uint32_t));
    }
};

#include "GameBuffer.h"


void GameBuffer::memset(uint32_t value, size_t from, size_t to) {
    if (to > height * width) to = height * width;
    std::memset(buffer + from, value, (to - from) * sizeof(uint32_t));
}

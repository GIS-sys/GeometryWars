#pragma once

template <typename T, typename U, typename V>
auto clamp(T value, U min, V max) {
    auto return_type = value + min + max;
    return_type *= 0;
    if (value < min) return min + return_type;
    if (value > max) return max + return_type;
    return value + return_type;
}

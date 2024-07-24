#pragma once

#include <cmath>
#include <vector>


template <typename T, typename U, typename V>
auto clamp(T value, U min, V max) {
    auto return_type = value + min + max;
    return_type *= 0;
    if (value < min) return min + return_type;
    if (value > max) return max + return_type;
    return value + return_type;
}

template <typename T>
std::vector<T> normalize_vector(const std::vector<T>& raw_vector) {
    if (raw_vector.size() == 0) return raw_vector;
    // sum
    T sum = 0;
    for (T number : raw_vector) sum += number;
    if (sum == 0) return  std::vector<T>(raw_vector.size(), 0);
    // normalize
    std::vector<T> result_vector;
    for (T number : raw_vector) result_vector.push_back(number / sum);
    return result_vector;
}

template <typename T>
std::pair<T, T> normalize_pair(const std::pair<T, T>& raw_pair) {
    auto result_vector = normalize_vector<T>({raw_pair.first, raw_pair.second});
    return std::make_pair(result_vector[0], result_vector[1]);
}

template <typename T>
float distance(const std::pair<T, T>& a, const std::pair<T, T>& b) {
    return std::sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

template <typename T>
std::vector<T> filter_vector_by_mask(const std::vector<T>& source, const std::vector<bool>& mask) {
    std::vector<T> result;
    for (int i = 0; i < mask.size(); ++i) {
        if (mask[i]) result.push_back(source[i]);
    }
    return result;
}

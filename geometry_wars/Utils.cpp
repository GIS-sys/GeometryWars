#include "geometry_wars/Utils.h"

#include <math.h>


std::pair<float, float> rotate_pair(std::pair<float, float> vector, float degrees) {
    float cs = std::cos(degrees * M_PI / 180.0);
    float sn = std::sin(degrees * M_PI / 180.0);
    return {
        vector.first * cs - vector.second * sn,
        vector.first * sn + vector.second * cs
    };
}

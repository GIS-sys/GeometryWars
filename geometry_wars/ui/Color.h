#pragma once

#include <cstdint>
//#include "geometry_wars/ui/GameBuffer.h"
class GameBuffer;


class Color {
  private:
    uint32_t color;
    float alpha = 0;

  public:
    Color(uint32_t color);
    Color(uint32_t color, float alpha);

    // void apply(GameBuffer* buffer, int x, int y) const;
    uint32_t raw() const;

    static Color mix(Color a, Color b);
    static Color from_rgb(int red, int blue, int green);
    static Color from_rgba(int red, int blue, int green, float alpha);
    static Color from_shade(int shade);
    static Color from_shade(int shade, float alpha);
};

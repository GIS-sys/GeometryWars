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

    static Color WHITE() { return Color::from_shade(224); }
    static Color BLACK() { return Color::from_shade(0); }
    static Color RED() { return Color::from_rgb(255, 32, 32); }
    static Color BLUE() { return Color::from_rgb(32, 32, 255); }
    static Color LIGHT_BLUE() { return Color::from_rgb(32, 32, 64); }
    static Color GREEN() { return Color::from_rgb(32, 255, 32); }
    static Color LIGHT_GREEN() { return Color::from_rgb(32, 64, 32); }
    static Color YELLOW() { return Color::from_rgb(224, 224, 32); }
    static Color ORANGE() { return Color::from_rgb(255, 128, 32); }
};

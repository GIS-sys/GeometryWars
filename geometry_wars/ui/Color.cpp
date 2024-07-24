#include "geometry_wars/ui/Color.h"
#include "geometry_wars/Utils.h"


Color::Color(uint32_t color) : color(color) {}

Color::Color(uint32_t color, float alpha) : color(color), alpha(alpha) {}

// void Color::apply(GameBuffer* buffer, int x, int y) const {
//     Color current_color = Color(buffer.get(x, y));
//     Color result_color = mix(*this, current_color);
//     buffer->set(x, y, result_color.color);
// }

uint32_t Color::raw() const { return color; }

Color Color::mix(Color a, Color b) {
    return a; // TODO
}

Color Color::from_rgb(int red, int blue, int green) {
    red = clamp(red, 0, 255);
    green = clamp(green, 0, 255);
    blue = clamp(blue, 0, 255);
    return Color(red*256*256 + blue*256 + green);
}

Color Color::from_rgba(int red, int blue, int green, float alpha) {
    Color color = from_rgb(red, green, blue);
    color.alpha = alpha;
    return color;
}

Color Color::from_shade(int shade) { return from_rgb(shade, shade, shade); }

Color Color::from_shade(int shade, float alpha) { return from_rgba(shade, shade, shade, alpha); }

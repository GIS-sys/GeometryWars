#pragma once

#include <string>
#include "geometry_wars/ui/GameBuffer.h"


class Font {
  private:
    static const int FONT_BASE_HEIGHT = 16;
    static const int FONT_BASE_WIDTH = 16;
    static const int FONT_BASE_PAD_Y = 2;
    static const int FONT_BASE_PAD_X = 2;
    static const int FONT_BASE_STROKE = 3;

  public:
    static int estimate_height(const std::string& text);
    static int estimate_width(const std::string& text);
    static void draw_text(GameBuffer& buffer, const std::string& text, int x, int y, float scale, uint32_t color);
    static std::pair<int, int> draw_char(GameBuffer& buffer, char symbol, int x, int y, float scale, uint32_t color);
};

#include "Font.h"


int Font::estimate_height(const std::string& text) { return FONT_BASE_HEIGHT; }

int Font::estimate_width(const std::string& text) { return FONT_BASE_WIDTH * text.size(); }

void Font::draw_text(GameBuffer& buffer, const std::string& text, int x, int y, float scale, uint32_t color) {
    for (char symbol : text) {
        std::pair<int, int> delta = draw_char(buffer, symbol, x, y, scale, color);
        x += delta.first;
        y += delta.second;
    }
}

std::pair<int, int> Font::draw_char(GameBuffer& buffer, char symbol, int x, int y, float scale, uint32_t color) {
    if (symbol == 't') {
        buffer.draw_line(x, y, x + 20, y + 20, 5, color);
    } else {
        buffer.draw_line(x, y, x + 20, y + 10, 2, color);
        buffer.draw_line(x, y + 20, x + 20, y, 2, color);
    }
    return {20, 0};
    // TODO
}

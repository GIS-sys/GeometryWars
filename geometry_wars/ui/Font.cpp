#include "Font.h"


int Font::estimate_height(const std::string& text) { return FONT_BASE_HEIGHT + 2 * FONT_BASE_PAD_Y; }

int Font::estimate_width(const std::string& text) { return (FONT_BASE_WIDTH + 2 * FONT_BASE_PAD_X) * text.size(); }

void Font::draw_text(GameBuffer& buffer, const std::string& text, int x, int y, float scale, uint32_t color) {
    for (char symbol : text) {
        std::pair<int, int> delta = draw_char(buffer, symbol, x, y, scale, color);
        x += delta.first;
        y += delta.second;
    }
}

std::pair<int, int> Font::draw_char(GameBuffer& buffer, char symbol, int x, int y, float scale, uint32_t color) {
    // TODO
    x += FONT_BASE_PAD_X;
    y += FONT_BASE_PAD_Y;
    int cwidth = FONT_BASE_WIDTH * scale;
    int cheight = FONT_BASE_HEIGHT * scale;
    if (symbol == 'A') {
        buffer.draw_line(x, y + cheight, x + cwidth / 2, y, FONT_BASE_STROKE, color);
        buffer.draw_line(x + cwidth, y + cheight, x + cwidth / 2, y, FONT_BASE_STROKE, color);
        buffer.draw_line(x + cwidth / 4, y + cheight / 2, x + cwidth * 3 / 4, y + cheight / 2, FONT_BASE_STROKE, color);
    } else if (symbol == 'B') {
    } else if (symbol == 'C') {
    } else if (symbol == 'D') {
    } else if (symbol == 'E') {
    } else if (symbol == 'F') {
    } else if (symbol == 'G') {
    } else if (symbol == 'H') {
    } else if (symbol == 'I') {
    } else if (symbol == 'J') {
    } else if (symbol == 'K') {
    } else if (symbol == 'L') {
    } else if (symbol == 'M') {
    } else if (symbol == 'N') {
    } else if (symbol == 'O') {
    } else if (symbol == 'P') {
    } else if (symbol == 'Q') {
    } else if (symbol == 'R') {
        buffer.draw_line(x, y, x, y + cheight, FONT_BASE_STROKE, color);
        buffer.draw_line(x, y, x + cwidth, y + cheight / 4, FONT_BASE_STROKE, color);
        buffer.draw_line(x, y + cheight / 2, x + cwidth, y + cheight / 4, FONT_BASE_STROKE, color);
        buffer.draw_line(x, y + cheight / 2, x + cwidth, y + cheight, FONT_BASE_STROKE, color);
    } else if (symbol == 'S') {
        buffer.draw_line(x + cwidth, y, x, y + cheight / 3, FONT_BASE_STROKE, color);
        buffer.draw_line(x, y + cheight / 3, x + cwidth, y + cheight * 2 / 3, FONT_BASE_STROKE, color);
        buffer.draw_line(x + cwidth, y + cheight * 2 / 3, x, y + cheight, FONT_BASE_STROKE, color);
    } else if (symbol == 'T') {
        buffer.draw_line(x, y, x + cwidth, y, FONT_BASE_STROKE, color);
        buffer.draw_line(x + cwidth / 2, y, x + cwidth / 2, y + cheight, FONT_BASE_STROKE, color);
    } else if (symbol == 'U') {
    } else if (symbol == 'V') {
    } else if (symbol == 'W') {
    } else if (symbol == 'X') {
    } else if (symbol == 'Y') {
    } else if (symbol == 'Z') {
    } else {
    }
    return {cwidth + 2 * FONT_BASE_PAD_X * scale, 0};
}

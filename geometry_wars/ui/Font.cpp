#include "Font.h"

#include <cmath>


int Font::estimate_height(const std::string& text) { return FONT_BASE_HEIGHT + 2 * FONT_BASE_PAD_Y; }

int Font::estimate_width(const std::string& text) { return (FONT_BASE_WIDTH + 2 * FONT_BASE_PAD_X) * text.size(); }

void Font::draw_text(GameBuffer& buffer, const std::string& text, int x, int y, float scale, Color color, const Camera* camera) {
    for (char symbol : text) {
        std::pair<int, int> delta = draw_char(buffer, symbol, x, y, scale, color, camera);
        x += delta.first;
        y += delta.second;
    }
}

std::pair<int, int> Font::draw_char(GameBuffer& buffer, char symbol, int x, int y, float scale, Color color, const Camera* camera) {
    // TODO
    x += FONT_BASE_PAD_X;
    y += FONT_BASE_PAD_Y;
    int cwidth = FONT_BASE_WIDTH * scale;
    int cheight = FONT_BASE_HEIGHT * scale;
    int scaled_stroke = std::ceil(FONT_BASE_STROKE * scale);
    if (symbol == 'A') {
        buffer.draw_line(x, y + cheight, x + cwidth / 2, y, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth, y + cheight, x + cwidth / 2, y, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth / 4, y + cheight / 2, x + cwidth * 3 / 4, y + cheight / 2, scaled_stroke, color, camera);
    } else if (symbol == 'B') {
    } else if (symbol == 'C') {
        buffer.draw_line(x + cwidth, y, x, y, scaled_stroke, color, camera);
        buffer.draw_line(x, y, x, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight, x + cwidth, y + cheight, scaled_stroke, color, camera);
    } else if (symbol == 'D') {
        buffer.draw_line(x, y, x, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x, y, x + cwidth, y + cheight / 2, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight, x + cwidth, y + cheight / 2, scaled_stroke, color, camera);
    } else if (symbol == 'E') {
        buffer.draw_line(x, y, x, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x, y, x + cwidth, y, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight / 2, x + cwidth, y + cheight / 2, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight, x + cwidth, y + cheight, scaled_stroke, color, camera);
    } else if (symbol == 'F') {
    } else if (symbol == 'G') {
        buffer.draw_line(x + cwidth, y + cheight / 3, x + cwidth / 2, y, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight / 2, x + cwidth / 2, y, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight / 2, x + cwidth / 2, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth, y + cheight / 2, x + cwidth / 2, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth, y + cheight / 2, x + cwidth / 2, y + cheight / 2, scaled_stroke, color, camera);
    } else if (symbol == 'H') {
        buffer.draw_line(x, y, x, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth, y, x + cwidth, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight / 2, x + cwidth, y + cheight / 2, scaled_stroke, color, camera);
    } else if (symbol == 'I') {
        buffer.draw_line(x + cwidth / 2, y, x + cwidth / 2, y + cheight, scaled_stroke, color, camera);
    } else if (symbol == 'J') {
    } else if (symbol == 'K') {
    } else if (symbol == 'L') {
        buffer.draw_line(x, y, x, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight, x + cwidth, y + cheight, scaled_stroke, color, camera);
    } else if (symbol == 'M') {
        buffer.draw_line(x, y, x, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x, y, x + cwidth / 2, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth, y, x + cwidth / 2, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth, y, x + cwidth, y + cheight, scaled_stroke, color, camera);
    } else if (symbol == 'N') {
    } else if (symbol == 'O') {
        buffer.draw_line(x + cwidth, y, x, y, scaled_stroke, color, camera);
        buffer.draw_line(x, y, x, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight, x + cwidth, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth, y, x + cwidth, y + cheight, scaled_stroke, color, camera);
    } else if (symbol == 'P') {
    } else if (symbol == 'Q') {
    } else if (symbol == 'R') {
        buffer.draw_line(x, y, x, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x, y, x + cwidth, y + cheight / 4, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight / 2, x + cwidth, y + cheight / 4, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight / 2, x + cwidth, y + cheight, scaled_stroke, color, camera);
    } else if (symbol == 'S') {
        buffer.draw_line(x + cwidth, y, x, y + cheight / 3, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight / 3, x + cwidth, y + cheight * 2 / 3, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth, y + cheight * 2 / 3, x, y + cheight, scaled_stroke, color, camera);
    } else if (symbol == 'T') {
        buffer.draw_line(x, y, x + cwidth, y, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth / 2, y, x + cwidth / 2, y + cheight, scaled_stroke, color, camera);
    } else if (symbol == 'U') {
    } else if (symbol == 'V') {
        buffer.draw_line(x, y, x + cwidth / 2, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth, y, x + cwidth / 2, y + cheight, scaled_stroke, color, camera);
    } else if (symbol == 'W') {
    } else if (symbol == 'X') {
        buffer.draw_line(x, y, x + cwidth, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth, y, x, y + cheight, scaled_stroke, color, camera);
    } else if (symbol == 'Y') {
    } else if (symbol == 'Z') {
    } else if (symbol == '0') {
        buffer.draw_line(x + cwidth, y, x, y, scaled_stroke, color, camera);
        buffer.draw_line(x, y, x, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight, x + cwidth, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth, y, x + cwidth, y + cheight, scaled_stroke, color, camera);
    } else if (symbol == '1') {
        buffer.draw_line(x + cwidth / 2, y, x + cwidth / 2, y + cheight, scaled_stroke, color, camera);
    } else if (symbol == '2') {
        buffer.draw_line(x, y + cheight / 3, x + cwidth / 2, y, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth, y + cheight / 3, x + cwidth / 2, y, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth, y + cheight / 3, x, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight, x + cwidth, y + cheight, scaled_stroke, color, camera);
    } else if (symbol == '3') {
        buffer.draw_line(x + cwidth, y, x + cwidth, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x, y, x + cwidth, y, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight / 2, x + cwidth, y + cheight / 2, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight, x + cwidth, y + cheight, scaled_stroke, color, camera);
    } else if (symbol == '4') {
        buffer.draw_line(x, y, x, y + cheight / 2, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight / 2, x + cwidth, y + cheight / 2, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth, y, x + cwidth, y + cheight, scaled_stroke, color, camera);
    } else if (symbol == '5') {
        buffer.draw_line(x + cwidth, y, x, y, scaled_stroke, color, camera);
        buffer.draw_line(x, y, x, y + cheight / 2, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth, y + cheight / 2, x, y + cheight / 2, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth, y + cheight / 2, x + cwidth, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight, x + cwidth, y + cheight, scaled_stroke, color, camera);
    } else if (symbol == '6') {
        buffer.draw_line(x + cwidth, y, x, y, scaled_stroke, color, camera);
        buffer.draw_line(x, y, x, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth, y + cheight / 2, x, y + cheight / 2, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth, y + cheight / 2, x + cwidth, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight, x + cwidth, y + cheight, scaled_stroke, color, camera);
    } else if (symbol == '7') {
        buffer.draw_line(x + cwidth, y, x + cwidth / 2, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x, y, x + cwidth, y, scaled_stroke, color, camera);
    } else if (symbol == '8') {
        buffer.draw_line(x, y, x, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth, y, x + cwidth, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x, y, x + cwidth, y, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight / 2, x + cwidth, y + cheight / 2, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight, x + cwidth, y + cheight, scaled_stroke, color, camera);
    } else if (symbol == '9') {
        buffer.draw_line(x, y, x, y + cheight / 2, scaled_stroke, color, camera);
        buffer.draw_line(x + cwidth, y, x + cwidth, y + cheight, scaled_stroke, color, camera);
        buffer.draw_line(x, y, x + cwidth, y, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight / 2, x + cwidth, y + cheight / 2, scaled_stroke, color, camera);
        buffer.draw_line(x, y + cheight, x + cwidth, y + cheight, scaled_stroke, color, camera);
    } else if (symbol == '-') {
        buffer.draw_line(x, y + cheight / 2, x + cwidth, y + cheight / 2, scaled_stroke, color, camera);
    } else {
    }
    return {cwidth + 2 * FONT_BASE_PAD_X * scale, 0};
}

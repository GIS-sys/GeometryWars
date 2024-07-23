#pragma once

#include <functional>
#include <string>
#include "geometry_wars/ui/GameObject.h"


class GOButton : public GameObject {
  private:
    std::function<void()> on_click;
    std::string label;
    float left;
    float top;
    float width;
    float height;
    uint32_t color;
  public:
    ~GOButton() = default;
    GOButton(float left, float top, float width, float height, std::string label, uint32_t color, std::function<void()> on_click);
    void draw(GameBuffer buffer);
    bool is_inside();
    void click();
};

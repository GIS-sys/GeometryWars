#pragma once

#include <functional>
#include <string>
#include "geometry_wars/ui/Color.h"
#include "geometry_wars/ui/GameObject.h"
#include "geometry_wars/ui/Camera.h"


class GOButton : public GameObject {
  private:
    static constexpr float BUTTON_PAD_X = 0.2;
    static constexpr float BUTTON_PAD_Y = 0.2;
    bool pressed = false;
    std::function<void()> on_click;
    std::string label;
    float left;
    float top;
    float width;
    float height;
    Color color;
  public:
    ~GOButton() = default;
    GOButton(float left, float top, float width, float height, std::string label, Color color, std::function<void()> on_click);
    void draw(GameBuffer buffer, Camera* camera);
    bool is_inside(int x, int y, int buffer_width, int buffer_height);
    void mouse_outside(bool lmb_pressed, bool rmb_pressed);
    void mouse_press(int button);
    void mouse_release(int button);
};

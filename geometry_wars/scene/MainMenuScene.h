#pragma once
#include "geometry_wars/scene/GameScene.h"


#include <functional>
#include <string>
#include <iostream>
class GameObject {
  public:
    virtual void draw(GameBuffer buffer) {}
    virtual bool is_inside() { return false; }
    virtual void click() {}
    virtual ~GameObject() = 0;
};
inline GameObject::~GameObject() {}
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
    GOButton(float left, float top, float width, float height, std::string label, uint32_t color, std::function<void()> on_click) : left(left), top(top), width(width), height(height), label(label), color(color), on_click(on_click) {}
    void draw(GameBuffer buffer) {
        int x1 = left * buffer.width;
        int x2 = x1 + width * buffer.width;
        int y1 = top * buffer.height;
        int y2 = y1 + height * buffer.height;
        //buffer.draw_line(x1, y1, x2, y2, 4, color);
        //buffer.draw_line(x1, y2, x2, y1, 4, color);
        buffer.draw_line(x1, y1, x2, y1, 4, color);
        buffer.draw_line(x1, y2, x2, y2, 4, color);
        buffer.draw_line(x1, y1, x1, y2, 4, color);
        buffer.draw_line(x2, y1, x2, y2, 4, color);
        buffer.draw_text(label, x1, y1, x2, y2, color);
    }
    bool is_inside() { return true; }
    void click() { on_click(); }
};

class MainMenuScene : public GameScene {
  private:
    std::vector<GameObject*> objects;
    void start();
    void exit();

  public:
    ~MainMenuScene();
    MainMenuScene();
    void draw(GameBuffer buffer);
    void act(float dt);
};

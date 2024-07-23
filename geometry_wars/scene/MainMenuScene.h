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
    float left;
    float top;
    float width;
    float height;
    std::string label;
    std::function<void()> on_click;
  public:
    ~GOButton() = default;
    GOButton(float left, float top, float width, float height, std::string label, std::function<void()> on_click) : left(left), top(top), width(width), height(height), label(label), on_click(on_click) {}
    void draw(GameBuffer buffer) {
        int step = 32;
        for (int red = 0; red < 256; red+=step) {
        for (int blue = 0; blue < 256; blue+=step) {
        for (int green = 0; green < 256; green+=step) {
            int i = green/step + blue/step*256/step + red/step*256/step*256/step;
            //std::cout << i << " ";
            for (int y = 5; y <=50; ++y) buffer.set(i, y, red, green, blue);
        }
        }
        }
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

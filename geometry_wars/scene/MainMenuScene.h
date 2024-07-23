#pragma once
#include "geometry_wars/scene/GameScene.h"


#include <functional>
#include <string>
#include <iostream>
class GameObject {
  public:
    virtual bool is_inside() { return false; }
    virtual void click() {}
    virtual ~GameObject() = 0;
};
inline GameObject::~GameObject() {}
class GOButton : public GameObject {
  private:
    std::string label;
    std::function<void()> on_click;
  public:
    ~GOButton() = default;
    GOButton(std::string label, std::function<void()> on_click) : label(label), on_click(on_click) {}
    bool is_inside() { return true; }
    void click() { on_click(); }
};

class MainMenuScene : public GameScene {
  private:
    float color = 0;
    std::vector<GameObject*> objects;
    void start();
    void exit();

  public:
    ~MainMenuScene();
    MainMenuScene();
    void draw(GameBuffer&& buffer);
    void act(float dt);
};

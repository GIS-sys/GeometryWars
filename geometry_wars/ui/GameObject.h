#pragma once

#include "geometry_wars/ui/GameBuffer.h"

class GameObject {
  public:
    virtual void draw(GameBuffer buffer) {}
    virtual bool is_inside(int x, int y, int buffer_width, int buffer_height) { return false; }
    virtual bool is_outside(int x, int y, int buffer_width, int buffer_height) { return !is_inside(x, y, buffer_width, buffer_height); }
    virtual void mouse_outside(bool lmb_pressed, bool rmb_pressed) {}
    virtual void mouse_press(int button) {}
    virtual void mouse_release(int button) {}
    virtual ~GameObject() = 0;
};

inline GameObject::~GameObject() {}

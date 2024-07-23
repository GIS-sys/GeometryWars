#pragma once

#include "geometry_wars/ui/GameBuffer.h"

class GameObject {
  public:
    virtual void draw(GameBuffer buffer) {}
    virtual bool is_inside() { return false; }
    virtual void click() {}
    virtual ~GameObject() = 0;
};

inline GameObject::~GameObject() {}

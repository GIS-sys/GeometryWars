#pragma once

#include "geometry_wars/ui/GameBuffer.h"
#include <cstdio>
#include <stdint.h>


class GameScene {
  protected:
    class keys {
      public:
        static int K_ESCAPE;
        static int K_SPACE;
        static int K_LEFT;
        static int K_UP;
        static int K_RIGHT;
        static int K_DOWN;
        static int K_RETURN;
        static int K__COUNT;
    };

    bool engine_is_key_pressed(int button_vk_code);
    int engine_get_cursor_x();
    int engine_get_cursor_y();
    bool engine_is_mouse_button_pressed(int button); // 0 - left, 1 - right
    void engine_schedule_quit_game();

  public:
    ~GameScene();
    virtual void draw(GameBuffer&& buffer) = 0;
    virtual void act(float dt) = 0;
};

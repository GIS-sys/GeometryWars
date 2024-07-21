#include "Engine.h"
#include "geometry_wars/scene/GameScene.h"
#include "geometry_wars/scene/MainMenuScene.h"
#include <stdlib.h>
#include <memory.h>

#include <stdio.h>
#include <iostream>


//  You are free to modify this file
//

//  is_key_pressed(int button_vk_code) - check if a key is pressed,
//                                       use keycodes (VK_SPACE, VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, VK_RETURN)
//
//  get_cursor_x(), get_cursor_y() - get mouse cursor position
//  is_mouse_button_pressed(int button) - check if mouse button is pressed (0 - left button, 1 - right button)
//  schedule_quit_game() - quit game after act()

GameScene* game_scene;

// initialize game data in this function
void initialize()
{
    game_scene = new MainMenuScene();
}

// this function is called to update game data,
// dt - time elapsed since the previous update (in seconds)
void act(float dt)
{
    if (is_key_pressed(VK_ESCAPE)) schedule_quit_game();
    game_scene->act(dt);
}

// fill buffer in this function
// uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH] - is an array of 32-bit colors (8 bits per R, G, B)
void draw()
{
    memset(buffer, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));
    game_scene->draw(GameBuffer((uint32_t*)buffer, SCREEN_HEIGHT, SCREEN_WIDTH));
}

// free game data in this function
void finalize()
{
    delete game_scene;
}


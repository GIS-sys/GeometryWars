#include "MainMenuScene.h"

#include <cstring>
#include <iostream>
#include "geometry_wars/scene/GameScene.h"
#include "geometry_wars/ui/GameBuffer.h"
#include "geometry_wars/ui/GOButton.h"


MainMenuScene::MainMenuScene() {
    objects.push_back(new GOButton(0.1, 0.25, 0.8, 0.2, "START -0123456789", 200, [this](){ this->start(); }));
    objects.push_back(new GOButton(0.1, 0.55, 0.8, 0.2, "EXIT SCORE RECORD", 200*256*256, [this](){ this->exit(); }));
}

MainMenuScene::~MainMenuScene() {
    for (GameObject* go : objects) delete go;
}

void MainMenuScene::start() {
    need_transition_to_start = true;
}

void MainMenuScene::exit() {
    engine_schedule_quit_game();
}

void MainMenuScene::draw(GameBuffer buffer) {
    prev_buffer_width = buffer.width;
    prev_buffer_height = buffer.height;
    for (GameObject* go : objects) go->draw(buffer, nullptr);
}

GameScene::Type MainMenuScene::act(float dt) {
    // get mouse data
    int cx = engine_get_cursor_x();
    int cy = engine_get_cursor_y();
    bool mleft = engine_is_mouse_button_pressed(0);
    bool mright = engine_is_mouse_button_pressed(1);
    // check if mouse press/release happened
    bool mleft_event = (mleft != prev_mleft);
    bool mright_event = (mright != prev_mright);
    // for all objects...
    for (GameObject* go : objects) {
        // if mouse is not inside object - tell it and skip it
        if (go->is_outside(cx, cy, prev_buffer_width, prev_buffer_height)) {
            go->mouse_outside(mleft, mright);
            continue;
        }
        // if one of the buttons is pressed - tell it and skip all
        if (mleft_event) {
            if (mleft) go->mouse_press(0);
            if (!mleft) go->mouse_release(0);
        }
        if (mright_event) {
            if (mright) go->mouse_press(1);
            if (!mright) go->mouse_release(1);
        }
    }
    // exit
    if (engine_is_key_pressed(keys::K_ESCAPE)) {
        exit();
    }
    // remember new button states
    prev_mleft = mleft;
    prev_mright = mright;
    // transition if necessary
    if (need_transition_to_start) return GameScene::Type::main_game;
    return GameScene::Type::none;
}

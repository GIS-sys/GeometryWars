#include "MainMenuScene.h"

#include <cstring>
#include "geometry_wars/scene/GameScene.h"
#include <iostream>


MainMenuScene::MainMenuScene() {
    objects.push_back(new GOButton("Start", [this](){ this->start(); }));
    objects.push_back(new GOButton("Exit", [this](){ this->exit(); }));
}

MainMenuScene::~MainMenuScene() {
    for (GameObject* go : objects) delete go;
}

void MainMenuScene::start() {
    std::cout << "start" << std::endl;
}

void MainMenuScene::exit() {
    std::cout << "exit" << std::endl;
    engine_schedule_quit_game();
}

void MainMenuScene::draw(GameBuffer&& buffer) {
    buffer.memset(((uint32_t)color) * (256 * 256 + 256 + 1), 0, 10000);
}

void MainMenuScene::act(float dt) {
    if (engine_is_mouse_button_pressed(0)) objects[1]->click();
    const int COLOR_CHANGE_RATE = 100;
    if (engine_is_key_pressed(keys::K_SPACE)) {
        color += dt * COLOR_CHANGE_RATE;
    } else {
        color -= dt * COLOR_CHANGE_RATE;
    }
    
    if (color > 256) {
        color -= 256;
    } else if (color < 0) {
        color += 256;
    }
}

#include "MainMenuScene.h"

#include <cstring>
#include "geometry_wars/scene/GameScene.h"
#include <iostream>


MainMenuScene::MainMenuScene() {
    objects.push_back(new GOButton(0.1, 0.25, 0.8, 0.2, "Start", [this](){ this->start(); }));
    objects.push_back(new GOButton(0.1, 0.55, 0.8, 0.2, "Exit", [this](){ this->exit(); }));
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

void MainMenuScene::draw(GameBuffer buffer) {
    for (GameObject* go : objects) go->draw(buffer);
}

void MainMenuScene::act(float dt) {
    if (engine_is_mouse_button_pressed(0)) objects[1]->click();
    if (engine_is_key_pressed(keys::K_ESCAPE)) {
        exit();
    }
}

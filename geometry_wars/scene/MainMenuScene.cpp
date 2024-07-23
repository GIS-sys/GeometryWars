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
}

void MainMenuScene::exit() {
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

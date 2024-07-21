#include "geometry_wars/GameScene.h"
#include "geometry_wars/MainMenuScene.h"


MainMenuScene::MainMenuScene() {
    color = 0;
}

void MainMenuScene::draw(uint32_t* buffer) {
    memset(buffer, (uint32_t)color, 100 * sizeof(uint32_t));
}

void MainMenuScene::act(float dt) {
    color = (color + dt) % 255;
}

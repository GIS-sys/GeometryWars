#include "GameScene.h"
#include "MainMenuScene.h"
#include <cstring>


MainMenuScene::MainMenuScene() {
    color = 128;
}

void MainMenuScene::draw(uint32_t** buffer) {
    memset(buffer, ((uint32_t)color) * (256 * 256 + 256 + 1), 10000 * sizeof(uint32_t));
}

void MainMenuScene::act(float dt) {
    color += dt;
    if (color > 256) {
        color -= 256;
    }
}

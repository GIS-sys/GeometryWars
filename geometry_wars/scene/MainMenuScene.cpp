#include "MainMenuScene.h"

#include <cstring>
#include "geometry_wars/scene/GameScene.h"


MainMenuScene::MainMenuScene() {
    color = 128;
}

void MainMenuScene::draw(GameBuffer&& buffer) {
    buffer.memset(((uint32_t)color) * (256 * 256 + 256 + 1), 0, 10000);
}

void MainMenuScene::act(float dt) {
    const int COLOR_CHANGE_RATE = 100;
    color += dt * COLOR_CHANGE_RATE;
    if (color > 256) {
        color -= 256;
    }
}

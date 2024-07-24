#include "MainGameScene.h"


MainGameScene::~MainGameScene() {}

MainGameScene::MainGameScene() {}

void MainGameScene::draw(GameBuffer buffer) {}

GameScene::Type MainGameScene::act(float dt) {
    // exit to main menu
    if (engine_is_key_pressed(keys::K_RETURN)) {
        return GameScene::Type::main_menu;
    }
    return GameScene::Type::none;
}

#include "MainGameScene.h"


MainGameScene::~MainGameScene() {
    for (GameObject* go : enemies) delete go;
    for (GameObject* go : projectiles) delete go;
}

MainGameScene::MainGameScene() {}

void MainGameScene::draw(GameBuffer buffer) {
    prev_buffer_width = buffer.width;
    prev_buffer_height = buffer.height;
    battlefield.draw(&camera);
    player.draw(&camera);
    for (GameObject* go : enemies) go->draw(buffer);
    for (GameObject* go : projectiles) go->draw(buffer);
}

GameScene::Type MainGameScene::act(float dt) {
    // move player TODO
    // move enemies toward player TODO
    // move projectiles TODO
    // fire new projectiles TODO
    // spawn new enemies TODO
    // move camera TODO
    // exit to main menu
    if (engine_is_key_pressed(keys::K_RETURN)) {
        return GameScene::Type::main_menu;
    }
    return GameScene::Type::none;
}

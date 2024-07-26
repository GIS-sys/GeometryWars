#include "GameScene.h"
#include "geometry_wars/Engine.h"


GameScene::~GameScene() {}

int GameScene::keys::K_ESCAPE = VK_ESCAPE;
int GameScene::keys::K_SPACE = VK_SPACE;
int GameScene::keys::K_LEFT = VK_LEFT;
int GameScene::keys::K_UP = VK_UP;
int GameScene::keys::K_RIGHT = VK_RIGHT;
int GameScene::keys::K_DOWN = VK_DOWN;
int GameScene::keys::K_RETURN = VK_RETURN;
int GameScene::keys::K__COUNT = VK__COUNT;

bool GameScene::engine_is_key_pressed(int button_vk_code) {
    return is_key_pressed(button_vk_code);
}

int GameScene::engine_get_cursor_x() {
    return get_cursor_x();
}

int GameScene::engine_get_cursor_y() {
    return get_cursor_y();
}

bool GameScene::engine_is_mouse_button_pressed(int button) { // 0 - left, 1 - right
    return is_mouse_button_pressed(button);
}

void GameScene::engine_schedule_quit_game() {
    schedule_quit_game();
}

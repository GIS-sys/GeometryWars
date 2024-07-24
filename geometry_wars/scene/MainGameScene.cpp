#include "MainGameScene.h"
#include <cstdlib>
#include "geometry_wars/Utils.h"
#include <algorithm>


MainGameScene::~MainGameScene() {
    for (Enemy* unit : enemies) delete unit;
    for (Projectile* unit : projectiles) delete unit;
}

MainGameScene::MainGameScene() {}

void MainGameScene::draw(GameBuffer buffer) {
    prev_buffer_width = buffer.width;
    prev_buffer_height = buffer.height;
    battlefield.draw(buffer, &camera);
    player.draw(buffer, &camera);
    for (Enemy* unit : enemies) unit->draw(buffer, &camera);
    for (Projectile* unit : projectiles) unit->draw(buffer, &camera);
}

GameScene::Type MainGameScene::act(float dt) {
    // move player TODO
    std::pair<float, float> player_acceleration_dt;
    if (engine_is_key_pressed(keys::K_LEFT)) player_acceleration_dt.first -= dt;
    if (engine_is_key_pressed(keys::K_RIGHT)) player_acceleration_dt.first += dt;
    if (engine_is_key_pressed(keys::K_UP)) player_acceleration_dt.second -= dt;
    if (engine_is_key_pressed(keys::K_DOWN)) player_acceleration_dt.second += dt;
    player.move(player_acceleration_dt);
    // move enemies toward player TODO
    for (Enemy* enemy : enemies) {
        std::pair<float, float> enemy_acceleration = normalize_vector({player.x - enemy->x, player.y - enemy->y});
        std::pair<float, float> enemy_acceleration_dt = {enemy_acceleration.first * dt, enemy_acceleration.second * dt};
        enemy->move(enemy_acceleration_dt);
    }
    // move projectiles TODO
    for (Projectile* projectile : projectiles) projectile->move({dt, dt});
    // delete projectiles which killed enemy / hit borders TODO
    std::vector<bool> alive_projectiles = std::vector<bool>(projectiles.size(), true);
    for (int i = 0; i < projectiles.size(); ++i) {
        Projectile* projectile = projectiles[i];
        if (battlefield.is_outside(projectile->x, projectile->y, prev_buffer_width, prev_buffer_height)) {
            alive_projectiles[i] = false;
            break;
        }
        for (Enemy* enemy : enemies) {
            if (enemy->is_inside(projectile->x, projectile->y, prev_buffer_width, prev_buffer_height)) {
                enemy->hit(projectile);
                alive_projectiles[i] = false;
                break;
            }
        }
    }
    for (int i = 0; i < projectiles.size(); ++i) {
        if (!alive_projectiles[i]) delete projectiles[i];
    }
    filter_vector_by_mask(projectiles, alive_projectiles);
    // delete enemies which are dead
    for (Enemy* enemy : enemies) {
        if (enemy->is_dead()) {
            score.text = enemy->bounty;
            delete enemy;
        }
    }
    enemies.erase(std::remove_if(begin(enemies), end(enemies), [](Enemy* e) { return e->is_dead(); }), end(enemies));
    // fire new projectiles TODO
    if (!player.is_ready_to_shoot()) {
        player.reduce_shooting_cooldown(dt);
    } else {
        if (engine_is_mouse_button_pressed(0)) {
            player.reset_shooting_cooldown();
            projectiles.push_back(player.shoot_projectile(engine_get_cursor_x(), engine_get_cursor_y()));
        }
    }
    // spawn new enemies TODO
    while (std::rand() * 1.0 / RAND_MAX > ENEMY_SPAWN_PROBABILITY) {
        std::pair<int, int> new_enemy_pos = player.position();
        while (distance(new_enemy_pos, player.position()) < MIN_ENEMY_SPAWN_DISTANCE) {
            new_enemy_pos = {std::rand() % prev_buffer_width, std::rand() % prev_buffer_height};
        }
        enemies.push_back(new EnemyRectangle(new_enemy_pos.first, new_enemy_pos.second));
    }
    // move camera TODO
    camera.move(player.x, player.y);
    camera.fov = 50;
    // exit to main menu
    if (engine_is_key_pressed(keys::K_RETURN)) {
        return GameScene::Type::main_menu;
    }
    return GameScene::Type::none;
}

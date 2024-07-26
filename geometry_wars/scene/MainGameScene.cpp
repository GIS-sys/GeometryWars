#include "MainGameScene.h"
#include <cstdlib>
#include "geometry_wars/Utils.h"
#include <algorithm>


MainGameScene::~MainGameScene() {
    for (Enemy* unit : enemies) delete unit;
    for (Projectile* unit : projectiles) delete unit;
}

MainGameScene::MainGameScene() : battlefield(1200, 800) {
}

void MainGameScene::restart() {
    camera = Camera();
    battlefield = Battlefield(1200, 800);
    player = Player();
    for (Enemy* unit : enemies) delete unit;
    enemies.clear();
    enemy_spawner.restart();
    for (Projectile* unit : projectiles) delete unit;
    projectiles.clear();
    score_value = 0;
    // high_score_value = 0;
    is_game_over = false;
}

void MainGameScene::draw(GameBuffer buffer) {
    prev_buffer_width = buffer.width;
    prev_buffer_height = buffer.height;
    battlefield.draw(buffer, &camera);
    player.draw(buffer, &camera);
    score_label.draw(buffer, nullptr);
    health_label.draw(buffer, nullptr);
    high_score_label.draw(buffer, nullptr);
    for (Enemy* unit : enemies) unit->draw(buffer, &camera);
    for (Projectile* unit : projectiles) unit->draw(buffer, &camera);

    if (is_game_over) {
        game_over_label.text = "GAME OVER - ENTER TO RESTART";
        game_over_current_score.text = "SCORE " + std::to_string(score_value);
        game_over_high_score.text = "HIGH SCORE " + std::to_string(high_score_value);
        game_over_label.draw(buffer, nullptr);
        game_over_current_score.draw(buffer, nullptr);
        game_over_high_score.draw(buffer, nullptr);
    }
}

GameScene::Type MainGameScene::act(float dt) {
    // exit to main menu
    if (engine_is_key_pressed(keys::K_ESCAPE)) {
        return GameScene::Type::main_menu;
    }
    // if game is over - display label
    if (is_game_over) {
        if (engine_is_key_pressed(keys::K_RETURN)) {
            high_score_value = std::max(score_value, high_score_value);
            restart();
        }
        return GameScene::Type::none;
    }
    // move player 
    std::pair<float, float> player_acceleration;
    if (engine_is_key_pressed(keys::K_LEFT)) player_acceleration.first -= 1;
    if (engine_is_key_pressed(keys::K_RIGHT)) player_acceleration.first += 1;
    if (engine_is_key_pressed(keys::K_UP)) player_acceleration.second -= 1;
    if (engine_is_key_pressed(keys::K_DOWN)) player_acceleration.second += 1;
    player_acceleration = normalize_pair(player_acceleration);
    player.move(player_acceleration, dt);
    // snap player inside battlefield
    player.set_position(battlefield.snap_inside(player.position()));
    // move enemies toward player 
    for (Enemy* enemy : enemies) {
        std::pair<float, float> enemy_acceleration = normalize_pair<float>({player.x - enemy->x, player.y - enemy->y});
        enemy->move(enemy_acceleration, dt);
    }
    // move projectiles 
    for (Projectile* projectile : projectiles) {
        projectile->move({projectile->speed_x, projectile->speed_y}, dt);
    }
    // delete projectiles which killed enemy / hit borders 
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
    projectiles = filter_vector_by_mask(projectiles, alive_projectiles);
    // delete enemies which are dead
    for (Enemy* enemy : enemies) {
        if (enemy->is_dead()) {
            score_value += enemy->bounty;
        }
    }
    score_label.text = "SCORE " + std::to_string(score_value);
    high_score_label.text = "HIGHSCORE " + std::to_string(high_score_value);
    enemies.erase(std::remove_if(begin(enemies), end(enemies), [](Enemy* e) {
        if (e->is_dead()) {
            delete e;
            return true;
        }
        return false;
    }), end(enemies));
    // collide enemies with player
    for (Enemy* enemy : enemies) {
        if (enemy->is_inside(player.x, player.y, prev_buffer_width, prev_buffer_height)) {
            player.update_health(-enemy->dps * dt);
        }
    }
    // if player is dead - set game over flag
    if (player.get_health() <= 0) {
        is_game_over = true;
        return GameScene::Type::none;
    }
    // fire new projectiles 
    if (!player.is_ready_to_shoot()) {
        player.reduce_shooting_cooldown(dt);
    } else {
        if (engine_is_mouse_button_pressed(0)) {
            player.reset_shooting_cooldown();
            auto [cx, cy] = camera.anti_convert({engine_get_cursor_x(), engine_get_cursor_y()});
            projectiles.push_back(player.shoot_projectile(cx, cy));
        }
    }
    // spawn new enemies
    Enemy* new_enemy = enemy_spawner.spawn(dt, player.position(), battlefield);
    if (new_enemy) enemies.push_back(new_enemy);
    // move camera 
    camera.buffer_width = prev_buffer_width;
    camera.buffer_height = prev_buffer_height;
    camera.fov = 0.5 + player.get_speed_magnitude_fraction() / 20;
    camera.center_on(player.x - Camera::LAG * player.get_speed_x(), player.y - Camera::LAG * player.get_speed_y());
    // update health
    health_label.text = "HEALTH " + std::to_string((int)player.get_health());
    return GameScene::Type::none;
}

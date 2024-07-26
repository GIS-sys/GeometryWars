# Geometry Wars

A simple version of a popular game

# Controls

0. on the main menu screen press one of the buttons: either EXIT (closes the game) or START (starts the game; also you can just press ENTER instead);

1. on the main game screen press ESCAPE at any time to return to the main menu screen;

2. move around using arrows on keyboard, shoot using mouse movement and left button;

3. you can kill enemies to earn points, when you reach a certain point limit you will unlock next weapon;

4. enemies will hurt you if they touch you, you will die if your health reaches 0;

5. when the game is over, press ENTER to play again or ESCAPE to exit to the main menu.

# Build

0. Install required tools: `sudo apt install g++ cmake libx11-dev`

1. Compile and run using `./compile_and_run.sh`

# Credits

Based on template engine: https://github.com/imp5imp5/game_template_linux

# TODO

- use Color instead of all colors in functions to allow for inverse color or transparent colors - TEST FOR ALPHA, ADD INVERSE, REPLACE EVERYWHERE FOR RGB

- add new enemies

- add powerups - player, enemies, projectiles etc.; player can store his own powerups, others are global and need method apply_if_applicable()


- probably break down MainGameScene act into several methods

- add real colliders

- allow to draw rotated

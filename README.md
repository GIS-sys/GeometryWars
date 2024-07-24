# Geometry Wars

A simple version of a popular game

# Controls

0. on main menu screen press one of th ebuttons: either EXIT (closes the game) or START (starts the game; also you can just press ENTER)

1. on main game screen press ESCAPE at any time to return to main menu screen

2. move around using arrows on keyboard, shoot using mouse movement and left button

# Build

0. Install required tools: `sudo apt install g++ cmake libx11-dev`

1. Compile and run using `./compile_and_run.sh`

# Credits

Based on template engine: https://github.com/imp5imp5/game_template_linux

# TODO

- design game screen


- use Color instead of all colors in functions to allow for inverse color or transparent colors

- add override everywhere

- add powerups - player, enemies, projectiles etc.; player can store his own powerups, others are global and need method apply_if_applicable()

- probably break down MainGameScene act into several methods

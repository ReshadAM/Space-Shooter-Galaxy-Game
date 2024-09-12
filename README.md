# How to run the game on a pi

* Install the following dependencies:
   - SDL dev `sudo apt-get install libsdl2-dev`
   - SDL image dev `sudo apt-get install libsdl2-image-dev`
   - SDL mixer dev `sudo apt-get install libsdl2-mixer-dev`

* After installing dependencies, run `make` from the root folder.
* To start the game, run `./game`.

# Notes for TA about acceptance tests

Some of the acceptance tests are not fully valid since some parts of the game are still in development (parts that are not included in the selected stories for this stage). I have emailed the professor, and he said to make note of it in the README to avoid losing marks on those acceptance tests:

### Game UI - Start screen Acceptance tests

* "The user can view the high score board by clicking the high score board option."
   * Currently, the high score screen is not implemented, so the score button will bring the user to a blank screen.

### Game UI - Health bar, Score counter, Wave tracker Acceptance tests

* "Player score increases when an enemy is killed."
   * Score system not implemented yet, so this will not show.
* "Wave counter should increment when a wave finishes."
   * Wave system not implemented yet, so this will not show.

### Game Mechanic - Player/sprite that can move and shoot Acceptance tests

* When an enemy takes damage, it is not visible to the user until the damage is enough to kill the enemy.

### Closed stories

- Game UI - Start Screen
- Game Mechanic - Player/sprite that can move and shoot
- Game Mechanic - AI enemies and asteroids
- Game Audio - Sound Effects
- Game Audio - Music (Optional Feature)

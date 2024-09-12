#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include "Screen.h"
#include <SDL.h>
#include "Player.h"
#include "HealthBar.h"
#include "Bullet.h"
#include "EnemyShip.h"
#include "StartScreen.h"
#include <vector>

/**
 * Represents the playing state of the game. This is where the player, enemies, bullets, etc. live.
 *
 * \author acallin
*/
class PlayScreen : public Screen {
private:
    Player player;
    healthBar _healthBar;
    std::vector<Bullet*> bullets;
    std::vector<EnemyShip*> enemies;
public:
    /**
     * Constructs a PlayScreen object, doing things like loading sound effects and putting the player in the center of 
     * the screen. 
    */
    PlayScreen();

    /**
     * Destroys the PlayScreen.
    */
    virtual ~PlayScreen() override;

    /**
     * Updates the state of the PlayScreen. Essentially calls the update functions of player, enemies, etc.
    */
    virtual void update() override;

    /**
     * Draws the PlayScreen / the player, enemies, etc.
    */
    virtual void draw() override;
};

#endif

#ifndef ENEMYSHIP_H
#define ENEMYSHIP_H

#include "SDL.h"
#include "SDL_image.h"
#include "Engine.h"
#include "Bullet.h"
#include <math.h>
#include <cmath>
#include <vector>

/**
 * EnemyShip class
 *
 * This class defines the EnemyShip object and provides functions to track the Player objects current position, follow the Player object, fire projectiles
 * at the Player object, and take damage from bullets fired by the Player object.
 */
class EnemyShip {
    //Private Variables and Functions
    private:
        // SDL variables
        SDL_Surface* _spriteSurface;        /** The SDL_Surface pointer associated with the player sprite */
        SDL_Texture* _sprite;               /** The SDL_Texture pointer associated with the player sprite */
        SDL_FRect _destinationRect;         /** The SDL_FRect object associated with the player sprite */
        // Standard type variables
        double _velocityX;                  /** The current the current velocity of the player sprite along the x-axis of the playerscreen */
        double _velocityY;                  /** The current the current velocity of the player sprite along the x-axis of the playerscreen */
        const double _moveSpeed;            /** The rate of acceleration the player travels at when moving forward and backward */
        int _health;                        /** The player's current health points */
        double _rateOfFire;                 /** The rate at which the Player can shoot bullets when the associated button is pressed */
        double _fireRecharge;               /** The timer that determines how long until the player can fire another bullet */
        bool _canFire;                      /** The boolean that determines whether or not the player is capable of shooting */
        double _bulletSpeed;                /** The speed at which the bullets can travel */
        bool _alive;                        /** The boolean that determines whether or not the player is capable of shooting */
        int _rotation;                      /** The current rotation (in degrees) of the player object */

    //Public Variabes and Functions
    public:
        EnemyShip(int x, int y);            /** The Constructor for the EnemyShip class */
        ~EnemyShip();                       /** The Destructor for the EnemyShip class */

        SDL_Rect getBounds() const;         /** Returns the SDL_FRect object associated with the EnemyShip sprite */
        bool getHealth() const;             /** Returns the current health of the EnemyShip */
        void decrementHealth();             /** Decreases the total remaining health of the EnemyShip */

        void update(int playerX, int playerY, std::vector<Bullet*>* bullets, int cameraX, int cameraY);   /** Updates the information about the enemyship */
        void draw();                        /** Draws the EnemyShip to the playscreen */
};

#endif

#ifndef PLAYER_H
#define PLAYER_H

#include "SDL.h"
#include "SDL_image.h"
#include "Engine.h"
#include "Bullet.h"
#include <vector>
#include <cmath>

/**
 * Player Class
 *
 * This class defines the Player object and its functions. Handles input events, collisions with other sprites
 * (e.g., EnemyShip), and contains important information pertaining to the Player instance (health, acceleration,
 * total points, e.t.c.)
 */
class Player{
    //Private Variables and Functions
    private:
        const double _rotateSpeed;       /** The rate at which the player can rotate left and right */
        const double _moveSpeed;         /** The rate of acceleration the player travels at when moving forward and backward */
        const int _normalShootRate;      /** The normal rate at which the Player can shoot bullets when the associated button is pressed */
        const int _shootSpeed;           /** The speed at which the bullets can travel */
        const int _normalDamageAmount;   /** The normal amount of damage dealt by the Player's fired bullets */


        SDL_Surface* _spriteSurface;     /** The SDL_Surface pointer associated with the player sprite */
        SDL_Texture* _sprite;            /** The SDL_Texture pointer associated with the player sprite */
        SDL_FRect _destinationRect;      /** The SDL_FRect object associated with the player sprite */
        double _rotation;                /** The current rotation (in degrees) of the player object */
        double _localX;                  /** The current x-coordinate of the player sprite on the playerscreen */
        double _localY;                  /** The current y-coordinate of the player sprite on the playerscreen */
        double _velocityX;               /** The current the current velocity of the player sprite along the x-axis of the playerscreen */
        double _velocityY;               /** The current the current velocity of the player sprite along the x-axis of the playerscreen */
        int _currentShootRate;           /** The current rate at which the player can fire projectiles */
        int _currentDamageAmount;
        int _shotRecharge;               /** The timer that determines how long until the player can fire another bullet */
        bool _canShoot;                  /** The boolean that determines whether or not the player is capable of shooting */
        bool _hasShield;                 /** The boolean that determines whether or not the shield buff is currently active */
        bool _hasDamageBuff;             /** The boolean that determines whether or not the damage buff is currently active */
        bool _hasPelletShot;             /** The boolean that determines whether or not the pellet shot buff is currently active */
        bool _hasAutoShot;               /** The booleant that determines whether or not the auto shot buff is currently active */
        int _shieldCharge;               /** The integer that dictates how much longer the shield buff will remain actibe */
        int _damageCharge;               /** The integer that dictates how much longer the damage buff will remain actibe */
        int _pelletCharge;               /** The integer that dictates how much longer the pellet shot buff will remain actibe */
        int _autoCharge;                 /** The integer that dictates how much longer the auto shot buff will remain actibe */
        int _health;                     /** The player's current health points */
        int _maxHealth;                  /** The player's maximum health points */
    //Public Variables and Functions
    public:
        Player();                        /** The Constructor for the player class */
        ~Player();                       /** The Destructor for the player class */

        SDL_Rect getBounds() const;      /** The function that returns the rectangle associated with the player sprite */
        int getCenterX() const;          /** Returns the current x-coordinate of the center of the player sprite on the playscreen */
        int getCenterY() const;          /** Returns the current y-coordinate of the center of the player sprite on the playscreen */
        int getLocalX() const;           /** Returns the current x-coordinate of the player sprite on the playscreen */
        int getLocalY() const;           /** Returns the current y-coordinate of the player sprite on the playscreen */
        void setPosition(int x, int y);  /** Sets the player sprite's new coordinates on the playscreen */
        int getHealth() const;           /** Returns the player's current health */
        void decrementHealth();          /** Decreases the player's total remaining health */
        void incrementHealth(int points); /** Sets the player's health */
        void activateShield(int duration);
        void update(std::vector<Bullet*>* const bullets);   /** Updates the player's current position on the board */
        void draw();                                        /** Draws the player object to the screen */
    };

#endif
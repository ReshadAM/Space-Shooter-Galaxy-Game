/**
 * PowerUp Class
 * 
 * The class that defines the PowerUp object
 */ 
#ifndef POWERUP_H
#define POWERUP_H

#include "SDL.h"
#include "SDL_image.h"
#include "Engine.h"
#include "Player.h"

class PowerUp{
private:
    SDL_Surface* _spriteSurface;
    SDL_Texture* _sprite;
    SDL_FRect _destinationRect;
    bool _isMarkedForDeletion;
    int _buffDuration;
    int _buffValue;

public:
    PowerUp(int x, int y)
    ~PowerUp()

    /**
     * Returns the duration of the powerup
     * \return the duration of powerup
    */
    int getBuffDuration();

    /**
     * Returns the value tied to the powerup
     * \return value tied to the powerup 
    */
    int getBuffValue();

    /**
     * Applies the buff effect to the player object
     * \return the updated player object, now using the powerup's effect
    */
    Player applyBuff(Player player);

    /**
     * Returns the bounds of the PowerUp.
     * \return the x, y, width, and height of the PowerUp
    */
    SDL_Rect getBounds() const;


    /**
     * Returns if the powerup is marked for deletion. Automatically set to true if the bullet's lifetime expires.
     * \return true if the powerup should be deleted
    */
    bool isMarkedForDeletion() const;

    /**
     * Makes isMarkedForDeletion() return true. Used to manually set if the powerup should be deleted.
    */
    void markForDeletion();


    /**
     * Draws the powerup at its current position.
    */
    void draw();
}

#endif
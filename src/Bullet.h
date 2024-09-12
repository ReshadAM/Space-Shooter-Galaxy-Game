#ifndef BULLET_H
#define BULLET_H

#include "SDL.h"
#include "SDL_image.h"
#include "Engine.h"

/**
 * Represents who the bullet originated from.
 * 
 * \author acallin
*/
enum BulletSource { player, enemy };

/**
 * Bullet represents a bullet fired from either the player or an enemy.
 * 
 * \author acallin
*/
class Bullet {
private:
    SDL_Surface* _spriteSurface;
    SDL_Texture* _sprite;
    SDL_FRect _destinationRect;
    BulletSource _source;
    double _velocityX;
    double _velocityY;
    const double _maxLifeSpan; // How many frames until the bullet should expire and be deleted.
    int _currentLifeSpan;
    bool _isMarkedForDeletion;
public:
    /**
     * Creates a bullet object.
     * \param source did the bullet come from the player or the enemy?
     * \param x the initial x position of the bullet
     * \param y the initial y position of the bullet
     * \param directionX the unit x direction of the bullet
     * \param directionY the unit y direction of the bullet
     * \param speed the magnitude of the bullet
    */
    Bullet(BulletSource source, int x, int y, double directionX, double directionY, double speed);

    /**
     * Destroys a bullet object.
    */
    ~Bullet();

    /**
     * Returns who sent the bullet.
     * \return either player or enemy
    */
    BulletSource getSource() const;

    /**
     * Returns the bounds of the bullet.
     * \return the x, y, width, and height of the bullet
    */
    SDL_Rect getBounds() const;

    /**
     * Returns if the bullet is marked for deletion. Automatically set to true if the bullet's lifetime expires.
     * \return true if the bullet should be deleted
    */
    bool isMarkedForDeletion() const;

    /**
     * Makes isMarkedForDeletion() return true. Used to manually set if the bullet should be deleted.
    */
    void markForDeletion();

    /**
     * Update the state of the bullet in the game.
    */
    void update();

    /**
     * Draws the bullet at its current position.
    */
    void draw();
};

#endif
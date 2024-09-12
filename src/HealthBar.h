//
// Created by delan on 2022-11-08.
//

#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include "SDL.h"
#include "SDL_image.h"
#include "Engine.h"

/**
 * healthbar class.
 *
 * This class displays a healthbar that decreases as damage is taken by the player.
 *
 * \author Delany
 */
class healthBar{
private:
    int hearts;
    SDL_Surface* _spriteSurface1;
    SDL_Texture* _sprite1;
    SDL_Surface* _spriteSurface2;
    SDL_Texture* _sprite2;
    SDL_Surface* _spriteSurface3;
    SDL_Texture* _sprite3;
    SDL_FRect _destinationRect;

public:

    /**
     * healthbar - healthbar constructor.
     */
    healthBar();

    /**
     * ~healthbar - free up surfaces and destroy textures.
     */
    ~healthBar();

    /**
     * update - update number of hearts to render
     * @param hearts number of hearts
     */
    void update(int hearts);

    /**
     * draw - render hearts to the screen
     */
    void draw();
};


#endif

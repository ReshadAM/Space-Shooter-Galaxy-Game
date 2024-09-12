//
// Created by delan on 2022-11-08.
//

#include "HealthBar.h"
#include <SDL_surface.h>
#include <SDL_image.h>

healthBar::healthBar() : hearts(3){

    _spriteSurface1 = IMG_Load("res/heart.png");
    _sprite1 = SDL_CreateTextureFromSurface(Engine::getInstance()->getRenderer(), _spriteSurface1);
    _spriteSurface2 = IMG_Load("res/heart.png");
    _sprite2 = SDL_CreateTextureFromSurface(Engine::getInstance()->getRenderer(), _spriteSurface1);
    _spriteSurface3 = IMG_Load("res/heart.png");
    _sprite3 = SDL_CreateTextureFromSurface(Engine::getInstance()->getRenderer(), _spriteSurface3);


    int width;
    int height;
    SDL_QueryTexture(_sprite1, NULL, NULL, &width, &height);
    SDL_QueryTexture(_sprite2, NULL, NULL, &width, &height);
    SDL_QueryTexture(_sprite3, NULL, NULL, &width, &height);
    _destinationRect.x = 0;
    _destinationRect.y = 0;
    _destinationRect.w = (float)width;
    _destinationRect.h = (float)height;



}

healthBar::~healthBar() {
    SDL_FreeSurface(_spriteSurface1);
    SDL_DestroyTexture(_sprite1);
    SDL_FreeSurface(_spriteSurface2);
    SDL_DestroyTexture(_sprite2);
    SDL_FreeSurface(_spriteSurface3);
    SDL_DestroyTexture(_sprite3);

}

void healthBar::update(int hearts) {
    this->hearts = hearts;
}

void healthBar::draw() {
    SDL_Rect destinationRectInt;
    destinationRectInt.x = (int)_destinationRect.x;
    destinationRectInt.y = (int)_destinationRect.y;
    destinationRectInt.w = (int)_destinationRect.w;
    destinationRectInt.h = (int)_destinationRect.h;
    SDL_Point center;
    center.x = _destinationRect.w / 2;
    center.y = _destinationRect.h / 2;
    if(hearts > 0) {
        SDL_RenderCopyEx(Engine::getInstance()->getRenderer(), _sprite1, NULL, &destinationRectInt, 0, &center,SDL_FLIP_NONE);
    }
    if(hearts > 1) {
        destinationRectInt.x += 50;
        SDL_RenderCopyEx(Engine::getInstance()->getRenderer(), _sprite2, NULL, &destinationRectInt, 0, &center,SDL_FLIP_NONE);
    }
    if(hearts > 2) {
        destinationRectInt.x += 50;
        SDL_RenderCopyEx(Engine::getInstance()->getRenderer(), _sprite2, NULL, &destinationRectInt, 0, &center,SDL_FLIP_NONE);
    }


    }




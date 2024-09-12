#include "PowerUp.h"

PowerUp::PowerUp(int x, int y){
    _spriteSurface = IMG_Load("res/Bullet.png");
    _sprite = SDL_CreateTextureFromSurface(Engine::getInstance()->getRenderer(), _spriteSurface);

    SDL_QueryTexture(_sprite, NULL, NULL, &width, &height);
    _destinationRect.x = x;
    _destinationRect.y = y;
    _destinationRect.w = (float)width;
    _destinationRect.h = (float)height;

    _isMarkedForDeletion = false;
}


PowerUp::~PowerUp() {
    SDL_FreeSurface(_spriteSurface);
    SDL_DestroyTexture(_sprite);
}

SDL_Rect PowerUp::getBounds() const {
    SDL_Rect destinationRectInt;
    destinationRectInt.x = (int)_destinationRect.x;
    destinationRectInt.y = (int)_destinationRect.y;
    destinationRectInt.w = (int)_destinationRect.w;
    destinationRectInt.h = (int)_destinationRect.h;
    return destinationRectInt;
}

int PowerUp::getBuffDuration(){
    return _buffDuration;
}

int PowerUp::getBuffValue(){
    return _buffValue;
}

Player PowerUp::applyBuff(Player player){
    player.incrementHealth(_buffValue)
    return player;
}

bool PowerUp::isMarkedForDeletion() const {
    return _isMarkedForDeletion;
}

void PowerUp::markForDeletion() {
    _isMarkedForDeletion = true;
}


void PowerUp::draw() {
    SDL_Rect destinationRectInt = getBounds();
    SDL_Point center;
    center.x = _destinationRect.w / 2;
    center.y = _destinationRect.h / 2;
    SDL_RenderCopy(Engine::getInstance()->getRenderer(), _sprite, NULL, &destinationRectInt);
}
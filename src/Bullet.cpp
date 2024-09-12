/*
 * acallin
 * edited Nov. 8, 2022
 * 
 * Source code for Bullet.h.
*/

#include "Bullet.h"

Bullet::Bullet(BulletSource source, int x, int y, double directionX, double directionY, double speed) : _maxLifeSpan(600) {
    _spriteSurface = IMG_Load("res/Bullet.png");
    _sprite = SDL_CreateTextureFromSurface(Engine::getInstance()->getRenderer(), _spriteSurface);

    int width;
    int height;
    SDL_QueryTexture(_sprite, NULL, NULL, &width, &height);
    _destinationRect.x = x;
    _destinationRect.y = y;
    _destinationRect.w = (float)width;
    _destinationRect.h = (float)height;

    _source = source;

    _velocityX = directionX * speed;
    _velocityY = directionY * speed;

    _currentLifeSpan = 0;
    _isMarkedForDeletion = false;
}

Bullet::~Bullet() {
    SDL_FreeSurface(_spriteSurface);
    SDL_DestroyTexture(_sprite);
}

BulletSource Bullet::getSource() const {
    return _source;
}

SDL_Rect Bullet::getBounds() const {
    SDL_Rect destinationRectInt;
    destinationRectInt.x = (int)_destinationRect.x;
    destinationRectInt.y = (int)_destinationRect.y;
    destinationRectInt.w = (int)_destinationRect.w;
    destinationRectInt.h = (int)_destinationRect.h;
    return destinationRectInt;
}

bool Bullet::isMarkedForDeletion() const {
    return _isMarkedForDeletion;
}

void Bullet::markForDeletion() {
    _isMarkedForDeletion = true;
}

void Bullet::update() {
    if (!_isMarkedForDeletion) {
        _destinationRect.x += _velocityX;
        _destinationRect.y += _velocityY;
        _currentLifeSpan++;
        if (_currentLifeSpan >= _maxLifeSpan)
            _isMarkedForDeletion = true;
    }
}

void Bullet::draw() {
    SDL_Rect destinationRectInt = getBounds();
    SDL_Point center;
    center.x = _destinationRect.w / 2;
    center.y = _destinationRect.h / 2;
    SDL_RenderCopy(Engine::getInstance()->getRenderer(), _sprite, NULL, &destinationRectInt);
}
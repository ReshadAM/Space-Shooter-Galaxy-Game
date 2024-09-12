//
// Created by incis on 2022-11-07.
//

#include "EnemyShip.h"

EnemyShip::EnemyShip(int x, int y) : _moveSpeed(2) {
    _spriteSurface = IMG_Load("res/Enemy.png");
    _sprite = SDL_CreateTextureFromSurface(Engine::getInstance()->getRenderer(), _spriteSurface);

    int width;
    int height;
    SDL_QueryTexture(_sprite, NULL, NULL, &width, &height);
    _destinationRect.x = x;
    _destinationRect.y = y;
    _destinationRect.w = (float)width;
    _destinationRect.h = (float)height;

    _velocityX = 0;
    _velocityY = 0;
    _health = 1;
    _rateOfFire = 120;
    _fireRecharge = 0;
    _canFire = true;
    _bulletSpeed = 4;
    _alive = true;
    _rotation = 0;
}

EnemyShip::~EnemyShip(){
    SDL_FreeSurface(_spriteSurface);
    SDL_DestroyTexture(_sprite);
}

SDL_Rect EnemyShip::getBounds() const {
    SDL_Rect destinationRectInt;
    destinationRectInt.x = (int)_destinationRect.x;
    destinationRectInt.y = (int)_destinationRect.y;
    destinationRectInt.w = (int)_destinationRect.w;
    destinationRectInt.h = (int)_destinationRect.h;
    return destinationRectInt;
}

bool EnemyShip::getHealth() const {
    return _health;
}
void EnemyShip::decrementHealth() {
    _health--;
}

void EnemyShip::update(int playerX, int playerY, std::vector<Bullet*>* bullets, int cameraX, int cameraY) {
    // Apply camera transformation.
    _destinationRect.x -= cameraX;
    _destinationRect.y -= cameraY;

    // Getting center position of enemyship
    double enemyPosX = _destinationRect.x + _destinationRect.w/2;
    double enemyPosY = _destinationRect.y + _destinationRect.h/2;

    // Get direction vector from enemyship to player
    double dirVectorX = playerX - enemyPosX;
    double dirVectorY = playerY - enemyPosY;

    // Calculate magnitude of direction vector
    double magnitude = sqrt(dirVectorX*dirVectorX + dirVectorY*dirVectorY);
    if (magnitude != 0) {
        _velocityX = dirVectorX/magnitude*_moveSpeed;
        _velocityY = dirVectorY/magnitude*_moveSpeed;
    } else {
        _velocityX = 0;
        _velocityY = 0;
    }

    // Update enemyship position
    _destinationRect.x += _velocityX;
    _destinationRect.y += _velocityY;

    // Recharge shot.
    if (!_canFire) {
        _fireRecharge++;
        if (_fireRecharge == _rateOfFire) {
            _canFire = true;
            _fireRecharge = 0;
        }
    }

    // Shoot at the player.
    if (_canFire) {
        SDL_Point center;
        center.x = _destinationRect.x + _destinationRect.w / 2;
        center.y = _destinationRect.y + _destinationRect.h / 2;
        double bulletVelocityX = _velocityX * _bulletSpeed;
        double bulletVelocityY = _velocityY * _bulletSpeed;
        bullets->push_back(new Bullet(BulletSource::enemy, center.x, center.y, bulletVelocityX, bulletVelocityY, _bulletSpeed));
        Engine::getInstance()->getSoundEffect()->playSoundEffect(1, 1);
        _canFire = false;
    }

    // Spin the UFO sprite.
    _rotation = (_rotation + 4) % 360;
}

void EnemyShip::draw() {
    SDL_Rect destinationRectInt = getBounds();
    SDL_Point center;
    center.x = _destinationRect.w / 2;
    center.y = _destinationRect.h / 2;
    SDL_RenderCopyEx(Engine::getInstance()->getRenderer(), _sprite, NULL, &destinationRectInt, _rotation, &center, SDL_FLIP_NONE);
}
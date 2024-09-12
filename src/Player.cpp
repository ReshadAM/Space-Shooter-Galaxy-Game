/*
 * acallin
 * edited Nov. 7, 2022
 * 
 * Source code for Player.h.
*/

#include "Player.h"

Player::Player() : _rotateSpeed(8.0), _moveSpeed(0.2), _normalShootRate(20), _shootSpeed(10), _normalDamageAmount(1) {
    _spriteSurface = IMG_Load("res/Player.png");
    _sprite = SDL_CreateTextureFromSurface(Engine::getInstance()->getRenderer(), _spriteSurface);

    int width;
    int height;
    SDL_QueryTexture(_sprite, NULL, NULL, &width, &height);
    _destinationRect.x = 0;
    _destinationRect.y = 0;
    _destinationRect.w = (float)width;
    _destinationRect.h = (float)height;

    _rotation = 0;
    _localX = 0;
    _localY = 0;
    _velocityX = 0;
    _velocityY = 0;

    _canShoot = true;
    _shotRecharge = 0;

    _maxHealth = 3;
    _health = 3;

    _currentShootRate = _normalShootRate;
    _currentDamageAmount = _normalDamageAmount;

    _hasDamageBuff = false;
    _hasShield = false;
    _hasPelletShot = false;
    _hasAutoShot = false;

}

Player::~Player() {
    SDL_FreeSurface(_spriteSurface);
    SDL_DestroyTexture(_sprite);
}

SDL_Rect Player::getBounds() const {
    SDL_Rect destinationRectInt;
    destinationRectInt.x = (int)_destinationRect.x;
    destinationRectInt.y = (int)_destinationRect.y;
    destinationRectInt.w = (int)_destinationRect.w;
    destinationRectInt.h = (int)_destinationRect.h;
    return destinationRectInt;
}

int Player::getCenterX() const {
    return _destinationRect.x + _destinationRect.w / 2;
}

int Player::getCenterY() const {
    return _destinationRect.y + _destinationRect.h / 2;
}

int Player::getLocalX() const {
    return _localX;
}

int Player::getLocalY() const {
    return _localY;
}

void Player::setPosition(int x, int y) {
    _destinationRect.x = x;
    _destinationRect.y = y;
}

void Player::incrementHealth(int points){
    _health += points;
    if (_health > _maxHealth)
    {
        _health = _maxHealth;
    }
    
    
}

int Player::getHealth() const {
    return _health;
}

void Player::decrementHealth() {
    _health--;
}

void Player::activateShield(int duration){
    _hasShield = true;
    _shieldCharge = duration;
}

void Player::update(std::vector<Bullet*>* const bullets) {
    const Uint8* state = SDL_GetKeyboardState(NULL);

    // Rotate with A and D.
    if (state[SDL_SCANCODE_A])
        _rotation -= _rotateSpeed;
    if (state[SDL_SCANCODE_D])
        _rotation += _rotateSpeed;
    if (_rotation >= 360)
        _rotation -= 360;
    if (_rotation <= -360)
        _rotation += 360;

    // Calculate direction the player is facing.
    const double PI = 3.14159;
    double rotationRadians = _rotation * (PI / 180);
    double directionX = sin(rotationRadians);
    double directionY = -cos(rotationRadians);
    
    // Accelerate with W.
    if (state[SDL_SCANCODE_W]) {
        _velocityX += directionX * _moveSpeed;
        _velocityY += directionY * _moveSpeed;
    }

    // Apply the player's current velocity as the local coordinates. These act as the camera coords to draw everything 
    // else on.
    _localX = _velocityX;
    _localY = _velocityY;

    // Recharge shot if the player can't shoot.
    if (!_canShoot) {
        _shotRecharge++;
        if (_shotRecharge == _currentShootRate) {
            _canShoot = true;
            _shotRecharge = 0;
        }
    }

    // Shoot with Spacebar.
    if (_canShoot && state[SDL_SCANCODE_SPACE]) {
        SDL_Point center;
        center.x = _destinationRect.x + _destinationRect.w / 2;
        center.y = _destinationRect.y + _destinationRect.h / 2;
        bullets->push_back(new Bullet(BulletSource::player, center.x, center.y, directionX, directionY, _shootSpeed));
        Engine::getInstance()->getSoundEffect()->playSoundEffect(0, 1);
        _canShoot = false;
    }
}

void Player::draw() {
    SDL_Rect destinationBoundsInt = getBounds();
    SDL_Point center;
    center.x = _destinationRect.w / 2;
    center.y = _destinationRect.h / 2;
    SDL_RenderCopyEx(Engine::getInstance()->getRenderer(), _sprite, NULL, &destinationBoundsInt, _rotation, &center, SDL_FLIP_NONE);
}

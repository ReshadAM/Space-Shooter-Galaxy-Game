//
// Created by jbunt on 27-Oct.-22.
//

#include "Button.h"
#include <iostream>
#include <SDL_surface.h>
#include <SDL_image.h>

using namespace std;

Button::Button(SDL_Renderer *r) {
    _renderer = r;

    _texture = IMG_LoadTexture(_renderer, "res/buttons.png");
    if (_texture == NULL)
        cout << SDL_GetError()  << endl;
    else
        cout << "image loaded." << endl;

    // set source rect dimensions
    _src.h = 50;
    _src.w = 210;

    // source rect x position will always be 0 since non-selected
    // button sprites start at x=0 in texture file
    _src.x = 0;

    // set size of destination rect
    _dst.h = 50;
    _dst.w = 210;
}

Button::~Button() {}

void Button::update() {
    int x, y;
    SDL_GetMouseState(&x, &y);

    SDL_Rect mouseRect;
    mouseRect.w = 1;
    mouseRect.h = 1;
    mouseRect.x = x;
    mouseRect.y = y;

    // if mouse rect intersects with button, change to selected texture
    if (SDL_HasIntersection(&mouseRect, &_dst)) {
        _isSelected = true;
        // move src rect to capture selected button texture
        _src.x = 221;
    } else {
        _isSelected = false;
        _src.x = 0;
    }
}

void Button::draw() {
    SDL_RenderCopy(_renderer, _texture, &_src, &_dst);
}

bool Button::isSelected() {
    return _isSelected;
}

const void Button::handleClick() const {
    this->_buttonHandler->handleClick();
}

void Button::setButtonHandler(ButtonHandler *b) {
    _buttonHandler = b;
}

void Button::setSourceRectY(int y) {
    _src.y = y;
}

void Button::setDestinationRectX(int x) {
    _dst.x = x;
}

void Button::setDestinationRectY(int y) {
    _dst.y = y;
}

int Button::getDestinationRectW() {
    return _dst.w;
}

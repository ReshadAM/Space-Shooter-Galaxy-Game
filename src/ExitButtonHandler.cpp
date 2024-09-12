//
// Created by jbunt on 15-Nov.-22.
//

#include "ExitButtonHandler.h"
#include <SDL.h>

const void ExitButtonHandler::handleClick() const {
    SDL_Event e;
    e.type = SDL_QUIT;
    SDL_PushEvent(&e);
}
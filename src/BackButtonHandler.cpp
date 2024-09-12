//
// Created by jbunt on 15-Nov.-22.
//

#include "BackButtonHandler.h"
#include "Engine.h"
#include "StartScreen.h"

const void BackButtonHandler::handleClick() const {
    Engine *engine = Engine::getInstance();

    engine->setScreen(new StartScreen());    // TODO: set to prev screen when
}
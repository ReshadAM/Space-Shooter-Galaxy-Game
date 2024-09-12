//
// Created by jbunt on 10-Nov.-22.
//

#include "StartButtonHandler.h"
#include "Engine.h"
#include "PlayScreen.h"

const void StartButtonHandler::handleClick() const {
    Engine *engine = Engine::getInstance();

    engine->setScreen(new PlayScreen());
}
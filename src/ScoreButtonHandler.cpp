//
// Created by jbunt on 15-Nov.-22.
//

#include "ScoreButtonHandler.h"
#include "Engine.h"
#include "HighscoreScreen.h"

const void ScoreButtonHandler::handleClick() const {
    Engine *engine = Engine::getInstance();

    engine->setScreen(new HighscoreScreen());
}
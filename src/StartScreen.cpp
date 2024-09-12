//
// Created by jbunt on 06-Nov.-22.
//
#include "StartScreen.h"
#include <iostream>

using namespace std;

const int _BUTTON_PADDING = 60;     // vertical space between buttons
const int _START_BTN_Y = 0;         // Y position of buttons
const int _SCORE_BTN_Y = 45;        //
const int _EXIT_BTN_Y = 95;        //

StartScreen::StartScreen() {
    Engine *engine = Engine::getInstance();

    // create buttons and set their handlers
    Button *startButton = new Button(engine->getRenderer());
    startButton->setButtonHandler(new StartButtonHandler);
    Button *scoreButton = new Button(engine->getRenderer());
    scoreButton->setButtonHandler(new ScoreButtonHandler);
    Button *exitButton = new Button(engine->getRenderer());
    exitButton->setButtonHandler(new ExitButtonHandler);

    // set source and destination positions
    startButton->setSourceRectY(_START_BTN_Y);
    startButton->setDestinationRectX( engine->InternalWidth/2 - startButton->getDestinationRectW()/2);
    startButton->setDestinationRectY(engine->InternalHeight/3);

    scoreButton->setSourceRectY(_SCORE_BTN_Y);
    scoreButton->setDestinationRectX(engine->InternalWidth/2 - scoreButton->getDestinationRectW()/2);
    scoreButton->setDestinationRectY(engine->InternalHeight/3 + _BUTTON_PADDING);

    exitButton->setSourceRectY(_EXIT_BTN_Y);
    exitButton->setDestinationRectX(engine->InternalWidth/2 - exitButton->getDestinationRectW()/2);
    exitButton->setDestinationRectY(engine->InternalHeight/3 + _BUTTON_PADDING *2);

    _buttons.push_back(*startButton);
    _buttons.push_back(*scoreButton);
    _buttons.push_back(*exitButton);
}

StartScreen::~StartScreen() {}

void StartScreen::update() {
    Engine *engine = Engine::getInstance();
    Uint32 mouseState = SDL_GetMouseState(NULL, NULL);
    for (Button &button : _buttons) {
        button.update();
        // if button is clicked with left mouse button, handle click
        if (mouseState & SDL_BUTTON_LEFT & button.isSelected()) {
            button.handleClick();
        }
    }
}

void StartScreen::draw() {
    for (Button &button : _buttons) {
        button.draw();
    }
}

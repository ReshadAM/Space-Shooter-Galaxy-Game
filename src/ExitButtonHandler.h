//
// Created by jbunt on 15-Nov.-22.
//

#ifndef EXITBUTTONHANDLER_H
#define EXITBUTTONHANDLER_H


#include "ButtonHandler.h"

/**
 * ExitButtonHandler class.
 *
 * This class is a concrete ButtonHandler that implements a handler for the exit button.
 *
 * \author Jake Bunting (jbuntin4)
 */
class ExitButtonHandler : public ButtonHandler {
public:

    /**
     * handleCLick - handles exit button click, exits the game to desktop.
     */
    const void handleClick() const;
};


#endif
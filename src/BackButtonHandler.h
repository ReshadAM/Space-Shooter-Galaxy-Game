//
// Created by jbunt on 15-Nov.-22.
//

#ifndef BACKBUTTONHANDLER_H
#define BACKBUTTONHANDLER_H


#include "ButtonHandler.h"

/**
 * BackButtonHandler class.
 *
 * This class is a concrete ButtonHandler that implements a handler for the back button.
 *
 * \author Jake Bunting (jbuntin4)
 */
class BackButtonHandler : public ButtonHandler {
public:

    /**
     * handleCLick - handles back button click, brings player to start screen.
     */
    const void handleClick() const;
};


#endif
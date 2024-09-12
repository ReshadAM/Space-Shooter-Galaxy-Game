//
// Created by jbunt on 10-Nov.-22.
//

#ifndef STARTBUTTON_H
#define STARTBUTTON_H

#include "ButtonHandler.h"

/**
 * StartButtonHandler class.
 *
 * This class is a concrete ButtonHandler that implements a handler for the start button.
 *
 * \author Jake Bunting (jbuntin4)
 */
class StartButtonHandler : public ButtonHandler {
public:

    /**
     * handleCLick - handles start button click, bringing user to play screen.
     */
    const void handleClick() const;
};


#endif
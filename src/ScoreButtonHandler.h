//
// Created by jbunt on 15-Nov.-22.
//

#ifndef SCOREBUTTONHANDLER_H
#define SCOREBUTTONHANDLER_H


#include "ButtonHandler.h"

/**
 * ScoreButtonHandler class.
 *
 * This class is a concrete ButtonHandler that implements a handler for the score button.
 *
 * \author Jake Bunting (jbuntin4)
 */
class ScoreButtonHandler : public ButtonHandler {
public:

    /**
     * handleCLick - handles score button click, bringing user to score screen.
     */
    const void handleClick() const;
};


#endif
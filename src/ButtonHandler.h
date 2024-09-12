//
// Created by jbunt on 15-Nov.-22.
//

#ifndef BUTTONHANDLER_H
#define BUTTONHANDLER_H

/**
 * ScoreButtonHandler class.
 *
 * Defines an interface for concrete button handlers.
 *
 * \author Jake Bunting (jbuntin4)
 */
class ButtonHandler {
public:
    /**
     * handleCLick - handles button click.
     */
    virtual const void handleClick() const = 0;
};

#endif
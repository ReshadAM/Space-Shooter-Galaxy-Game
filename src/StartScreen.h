#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "Screen.h"
#include "StartButtonHandler.h"
#include "ScoreButtonHandler.h"
#include "ExitButtonHandler.h"
#include "Engine.h"
#include "PlayScreen.h"
#include "Button.h"
#include <vector>
#include <variant>

/**
 * StartScreen class.
 *
 * This class is a concrete implementation of Screen. This screen is allows the player to start a game,
 * look at the high score board, and exit to desktop.
 *
 * \author Jake Bunting (jbuntin4)
 */
class StartScreen : public Screen {
private:
    std::vector<Button> _buttons;        /**< vector of buttons on the screen */
public:
    /**
     * StartScreen - creates the games start screen.
     */
    StartScreen();

    /**
     * ~StartScreen - destructor for StartScreen.
     */
    virtual ~StartScreen();

    /**
     * update - handles screen button functionality.
     */
    void update();

    /**
     * draw - renders the screen elements to the screen.
     */
    void draw();
};

#endif
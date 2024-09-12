#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "Screen.h"
#include "Button.h"
#include "Engine.h"
#include "PlayScreen.h"
#include "BackButtonHandler.h"
#import "ScoreDB.h"
#import "ScoreField.h"
#import <SDL.h>
#import <SDL_ttf.h>
#include <vector>

/**
 * HighscoreScreen class.
 *
 * This class is a concrete implementation of Screen. This screen is allows the player view the highscores,
 * and go back to start screen.
 *
 * \author Jake Bunting (jbuntin4)
 */
class HighscoreScreen : public Screen {
private:
    std::vector<Button> _buttons;        /**< vector of buttons on the screen */
    SDL_Texture* _scoreOutput;           /**< score to print to the screen */
    SDL_Rect _text_rect;                 /**< highscore text rectangle */
    SDL_Surface* _textSurface;           /**< highscore text surface */
public:
    /**
     * HighscoreScreen - creates the highscore screen.
     */
    HighscoreScreen();

    /**
     * ~HighscoreScreen - destructor for HighscoreScreen.
     */
    virtual ~HighscoreScreen();

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

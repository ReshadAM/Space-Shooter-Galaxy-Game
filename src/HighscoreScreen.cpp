//
// Created by Jake Bunting on 2022-11-25.
//
#import "HighscoreScreen.h"
#import <iostream>

const int _BUTTON_PADDING = 60;     // vertical space between buttons
const int _BACK_BTN_Y = 145;        // Y position of buttons
const int FONT_SIZE = 12;           // font size
const int TEXT_RECT_X = 60;         // text rect x pos
const int TEXT_RECT_Y = 30;         // text rect y pos
const Uint32 WRAP_LENGTH = 300;     // render text wrap length

HighscoreScreen::HighscoreScreen() {
    Engine *engine = Engine::getInstance();
    ScoreDB *HighScoreDB = new ScoreDB();

    // get highscores saved in the database
    std::vector<ScoreField> scores = HighScoreDB->GetTopScores();

    // create score string to be drawn to screen
    std::string scoreString;
    for (auto entry : scores) {
        scoreString.append(entry.getPlayerName() + ": " + entry.getScore() + "\n");
    }

    // open the font
    TTF_Font* font = TTF_OpenFont("res/8bitOperatorPlus8-Bold.ttf", FONT_SIZE);
    if (font == NULL)
        std::cout << SDL_GetError()  << std::endl;
    else
        std::cout << "font loaded." << std::endl;

    // text colour
    SDL_Color white = {255, 255, 255};

    // creat text surface
    _textSurface = TTF_RenderText_Blended_Wrapped(font, scoreString.c_str(), white, WRAP_LENGTH);

    // convert to texture
    _scoreOutput = SDL_CreateTextureFromSurface(engine->getRenderer(), _textSurface);

    // create rect to render texture on
    _text_rect.x = TEXT_RECT_X;
    _text_rect.y = TEXT_RECT_Y;
    _text_rect.w = engine->InternalWidth - TEXT_RECT_X;
    _text_rect.h = engine->InternalHeight - TEXT_RECT_X * 2;

    // create button and set handlers
    Button *backButton = new Button(engine->getRenderer());
    backButton->setButtonHandler(new BackButtonHandler);

    // set source and destination position
    backButton->setSourceRectY(_BACK_BTN_Y);
    backButton->setDestinationRectX( engine->InternalWidth/2 - backButton->getDestinationRectW()/2);
    backButton->setDestinationRectY(engine->InternalHeight - _BUTTON_PADDING);

    _buttons.push_back(*backButton);

    TTF_CloseFont(font);
}

HighscoreScreen::~HighscoreScreen() {
    SDL_FreeSurface(_textSurface);
    SDL_DestroyTexture(_scoreOutput);
}

void HighscoreScreen::update() {
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

void HighscoreScreen::draw() {
    Engine *engine = Engine::getInstance();

    // render scores
    SDL_RenderCopy(engine->getRenderer(), _scoreOutput, NULL, &_text_rect);

    // render buttons
    for (Button &button : _buttons) {
        button.draw();
    }
}
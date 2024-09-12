/*
 * acallin
 * edited Nov. 8, 2022
 * 
 * The source code for Engine.h.
*/

#include "Engine.h"

const int Engine::InternalWidth = 3456/3;
const int Engine::InternalHeight = 2234/3;
const int Engine::FramerateLimit = 60; // Limit # of frames per second so that the raspberry pi doesn't explode.

Engine* Engine::_instance = NULL;

Engine::Engine() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    TTF_Init();
    _window = SDL_CreateWindow("SDL2Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, InternalWidth, InternalHeight, 0);
	_renderer = SDL_CreateRenderer(_window, -1, 0);

    _currentScreen = NULL;
    _isRunning = true;
}

Engine::~Engine() {
    setScreen(NULL); // Destruct the last screen we were on.

    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Engine::setScreen(Screen* const screen) {
    if (_currentScreen != NULL)
        delete _currentScreen; // Call the destructor of the current screen before changing to the new one.
    _currentScreen = screen;
}

void Engine::doGameLoop() {
    const float frameFrequency = 1000.0f / FramerateLimit; // How frequently, in ms, we do another "frame." Ex: at a  
                                                           // limit of 30 FPS this comes out to 1 frame per ~33.3 ms.
    Uint32 accumulatedTime = 0;
    Uint32 previousTime = SDL_GetTicks();

    while (_isRunning) {
        Uint32 currentTime = SDL_GetTicks();
        accumulatedTime += currentTime - previousTime;
        previousTime = SDL_GetTicks();

        while (accumulatedTime >= frameFrequency) {
            pollEvents();
            if (_isRunning) { // Check again in case the user just closed the window.
                update();
                draw();
            }
            accumulatedTime -= frameFrequency;
        }
    }
}

Engine* Engine::getInstance() {
    if (Engine::_instance == NULL)
        Engine::_instance = new Engine();
    return Engine::_instance;
}

SDL_Window* Engine::getWindow() const {
    return _window;
}

SDL_Renderer* Engine::getRenderer() const {
    return _renderer;
}

Music* Engine::getMusic() {
    return &_music;
}

SoundEffect* Engine::getSoundEffect() {
    return &_soundEffect;
}

///// HELPER FUNCTIONS /////

void Engine::pollEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT)
            _isRunning = false; // Game loop exit condition.
    }
}

void Engine::update() {
    if (_currentScreen != NULL)
        _currentScreen->update();
}

void Engine::draw() {
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(_renderer);
    if (_currentScreen != NULL)
        _currentScreen->draw();
    SDL_RenderPresent(_renderer);
}

////////////////////////////

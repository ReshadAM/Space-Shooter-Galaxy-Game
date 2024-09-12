#ifndef ENGINE_H
#define ENGINE_H

#include "SDL.h"
#include "SDL_ttf.h"
#include "Screen.h"
#include "Music.h"
#include "SoundEffect.h"

/**
 * The engine is the foundation of the app. The engine boots up SDL and acts as a screen manager. The current screen 
 * can assume that it'll have its update and draw functions called FramerateLimit times per second.
 * 
 * Singleton.
 * 
 * \author acallin
*/
class Engine { // Singleton.
private:
    static Engine* _instance;
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    Screen* _currentScreen;
    Music _music;
    SoundEffect _soundEffect;
    bool _isRunning;
    
    Engine();
    void pollEvents();
    void update();
    void draw();

public:
    const static int InternalWidth;
    const static int InternalHeight;
    const static int FramerateLimit;

    /**
     * Destroys the Engine object. Of all other game components this destroyed last.
    */
    ~Engine();

    /**
     * Singleton - delete copy constructor.
    */
    Engine(const Engine& other) = delete;

    /**
     * Singleton - delete copy assignment operator.
    */
    Engine& operator=(const Engine& other) = delete;

    /**
     * Returns the singleton instance of this class.
     * \return the single Engine instance
    */
    static Engine* getInstance();

    /**
     * Returns the game window.
     * \return the SDL_Window object for the game.
    */
    SDL_Window* getWindow() const;

    /**
     * Returns the game renderer.
     * \return the SDL_Renderer for the game.
    */
    SDL_Renderer* getRenderer() const;

    /**
     * Returns the music player.
     * \return the Music object for the game.
    */
    Music* getMusic();

    /**
     * Returns the sound effect player.
     * \return the SoundEffect object for the game.
    */
    SoundEffect* getSoundEffect();

    /**
     * Sets the current screen of the game and calls the destructor of the previous screen if there was one. This is 
     * used to transition from the main menu, to in game, to the highscore menu, etc.
     * \param screen the new screen to update and draw
    */
    void setScreen(Screen* const screen);

    /**
     * The game loop: poll game events (input, window events, etc.) and update and draw the current screen. The speed 
     * is limited to the set framerate limit.
    */
    void doGameLoop();
};

#endif
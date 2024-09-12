#ifndef SCREEN_H
#define SCREEN_H

/**
 * Abstract class. Represents a screen or game scene. The engine has a reference to a concrete instance of some screen 
 * at all times to update and draw them. Screens are containers of game objects, and represent the main menu, in game, 
 * the settings menu, etc.
 * 
 * \author acallin
*/
class Screen {
public:
    /**
     * Creates a Screen object. Default constructor called when a concrete Screen object is created.
    */
    Screen();

    /**
     * Destroys a Screen object. Default destructor called when a concrete Screen object is destroyed.
    */
    virtual ~Screen() = 0;

    /**
     * The update function to be implemented by concrete screens. Game logic, physics, etc.
    */
    virtual void update() = 0;

    /**
     * The draw function to be implemented by concrete screens. Drawing sprites, text, etc.
    */
    virtual void draw() = 0;
};

#endif
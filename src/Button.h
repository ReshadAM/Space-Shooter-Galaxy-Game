#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <SDL.h>
#include <SDL_rect.h>
#include <SDL_surface.h>
#include "ButtonHandler.h"

/**
 * Button class.
 *
 * This class defines the button object and provides functions to handle mouse events and draw the button
 * to the screen. This class inherits from SDL_Surface.
 *
 * \author Jake Bunting (jbuntin4)
 */
class Button : public SDL_Surface {
private:
    SDL_Texture *_texture;          /**< pointer to button texture */
    SDL_Renderer *_renderer;        /**< pointer to game engine renderer */
    SDL_Rect _src;                  /**< source rectangle */
    SDL_Rect _dst;                  /**< destination rectangle */
    bool _isSelected = false;       /**< true when mouse intersects _dst, else false */
    ButtonHandler *_buttonHandler;  /**< pointer to button handler - handles button click */
public:
    /**
     * Button - Creates a UI button object.
     * \param id the string id of the button.
     * \param r pointer to engine renderer
     */
    Button(SDL_Renderer *r);

    /**
     * ~Button - Button object destructor.
     */
    virtual ~Button();

    /**
     * update - checks if the mouse hovers over the button and changes it to selected state.
     */
    void update();

    /**
     * draw - renders the button to the screen.
     */
    void draw();

    /**
     * isSelected - returns true when the mouse intersects with the button
     * \return  boolean
     */
    bool isSelected();

    /**
     * handleClick - calls button handle strategy
     */
    const void handleClick() const;

    /**
     * setButtonHandler - sets the button handle strategy that determines
     * what happens when the button is clicked.
     * @param b the concrete button handler.
     */
    void setButtonHandler(ButtonHandler *b);

    /**
     * setSourceRectY - set the y position of the texture source rect.
     * \param y the y position.
     */
    void setSourceRectY(int y);

    /**
     * setDestinationRectX - set the x position of the destination rect.
     * \param x the x position
     */
    void setDestinationRectX(int x);

    /**
     * setDestinationRectY - set the y position fo the destination rect.
     * \param y the y position
     */
    void setDestinationRectY(int y);

    /**
     * getDestinationRectW - Getter returning the width of the destination rect.
     * @return int width of destination rect.
     */
    int getDestinationRectW();

};


#endif //BUTTON_H
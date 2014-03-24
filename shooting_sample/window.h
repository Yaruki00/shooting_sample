//
//  window.h
//  game_sample
//
//  Created by 裕太 川辺 on 14/02/21.
//  Copyright (c) 2014年 __MyCompanyName__. All rights reserved.
//

#ifndef game_sample_window_h
#define game_sample_window_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>

class Window {
public:
    //Start SDL and TTF, create the window and renderer
    static void Init(std::string title, SDL_Rect pos);
    //Quit SDL and TTF
    static void Quit();
    /**
     *  Draw a SDL_Texture to the screen at dstRect with various other options
     *  @param tex The SDL_Texture to draw
     *  @param dstRect The destination position and width/height to draw the texture with
     *  @param clip The clip to apply to the image, if desired
     *  @param angle The rotation angle to apply to the texture, default is 0
     *  @param xPivot The x coordinate of the pivot, relative to (0, 0) being center of dstRect
     *  @param yPivot The y coordinate of the pivot, relative to (0, 0) being center of dstRect
     *  @param flip The flip to apply to the image, default is none
     */
    static void Draw(SDL_Texture *tex, SDL_Rect &dstRect, SDL_Rect *clip = NULL,
                     float angle = 0.0, int xPivot = 0, int yPivot = 0,
                     SDL_RendererFlip flip = SDL_FLIP_NONE);
    /**
     *  Loads an image directly to texture using SDL_image's
     *  built in function IMG_LoadTexture
     *  @param file The image file to load
     *  @return SDL_Texture* to the loaded texture
     */
    static SDL_Texture* LoadImage(const std::string &file);
    /**
     *  Generate a texture containing the message we want to display
     *  @param message The message we want to display
     *  @param fontFile The font we want to use to render the text
     *  @param color The color we want the text to be
     *  @param fontSize The size we want the font to be
     *  @return An SDL_Texture* to the rendered message
     */
    static SDL_Texture* RenderText(const std::string &message, const std::string &fontFile, 
                                   SDL_Color color, int fontSize);
    //Clear window
    static void Clear();
    //Present renderer
    static void Present();
    //Get the window's box
    static SDL_Rect Box();
    
private:
    static std::unique_ptr<SDL_Window, void (*)(SDL_Window*)> mWindow;
    static std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer*)> mRenderer;
    static SDL_Rect mBox;
};

#endif

//
//  ball.h
//  shooting_sample
//
//  Created by 裕太 川辺 on 14/02/24.
//  Copyright (c) 2014年 __MyCompanyName__. All rights reserved.
//

#ifndef shooting_sample_ball_h
#define shooting_sample_ball_h

#include <SDL2/SDL.h>
#include "window.h"

class Ball {
public:
    Ball();
    void Init(SDL_Texture* a_img, SDL_Rect a_pos, int a_x_move, int a_y_move);
    void Move();
    SDL_Texture* Get_Img();
    SDL_Rect Get_Pos();
    bool Get_Flag();
private:
    SDL_Texture *img;
    SDL_Rect pos;
    int x_move;
    int y_move;
    bool flag;
};

#endif
